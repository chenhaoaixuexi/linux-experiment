
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/select.h>

main ()
{
	int fd1, fd2;
	fd_set rfds;
	struct timeval tv;
	int retval;
	int n;
	char buf[1024];

	if ((fd1 = open ("/dev/input/mice", O_RDONLY)) == -1)
	{
		perror ("cannot open");
		exit (1);
	}
	if ((fd2 = open ("/dev/pts/0", O_RDONLY)) == -1)
	{
		perror ("cannot open");
		exit (1);
	}

	while (1)
	{
		FD_ZERO (&rfds);
		FD_SET (fd1, &rfds);
		FD_SET (fd2, &rfds);

		/* Wait up to five seconds. */
		tv.tv_sec = 5;
		tv.tv_usec = 0;

		retval = select (fd2 + 1, &rfds, NULL, NULL, &tv);

		if (retval == -1)
		{
			perror ("select()");
		}
		else if (retval > 0)
		{
			printf ("Data is available now.\n");
			if (FD_ISSET (fd1, &rfds))
			{
				n = read (fd1, buf, sizeof (buf));
				fflush (stdout);
				printf ("mice:%.*s\n", n, buf);
			}
			if (FD_ISSET (fd2, &rfds))
			{
				n = read (fd2, buf, sizeof (buf));
				fflush (stdout);
				printf ("tty:%.*s\n", n, buf);
			}
		}
		else
		{
			printf ("No data within five seconds.\n");
		}
	}
}

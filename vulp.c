    /*  vulp.c  */

    #include <stdio.h>
    #include <unistd.h>


    int main()
    {
       char * fn = "/tmp/XYZ";
       char buffer[150];
       FILE *fp;

       /* get user input */
       scanf("%150s", buffer );
       if(!access(fn, W_OK)){
	    fp = fopen(fn, "a+");
            fwrite("\n", sizeof(char), 1, fp);
            fwrite(buffer, sizeof(char), strlen(buffer), fp);
            fclose(fp);
       }
       else printf("No permission \n");
    }

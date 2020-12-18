#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
#include&lt;string.h&gt;
#include &lt;dirent.h&gt;

char s[100], c[100], n1[100], n2[100];
int
main ()
{
int ch, n, i, t, j, check;
char temp[200], line[100];
FILE *fptr1, *fptr2, *ftemp;
struct dirent *de;
char p;
while (1)
{
printf (&quot;enter your choice of command&quot;);
printf
(&quot;1:zero file commands\n2:one file commands\n3:two file commands\n4:exit&quot;);
scanf (&quot;%d&quot;, &amp;ch);
switch (ch)
{
case 1:

printf (&quot;you have selected zero file commands\n&quot;);
printf (&quot;enter the command:&quot;);
scanf (&quot;%s&quot;, c);
break;
case 2:
printf (&quot;you have selected one file commands\n&quot;);

printf (&quot;enter the command:&quot;);
scanf (&quot;%s %s&quot;, c,n1);
break;
case 3:
printf (&quot;you have selected two file commands\n&quot;);

printf (&quot;enter the command:&quot;);
scanf (&quot;%s %s %s&quot;, c,n1,n2);
break;
}
DIR *dr = opendir (n1);

if(strcmp(c,&quot;mkdir&quot;)==0){
check = mkdir (n1);
if (!check)
printf (&quot;Directory created\nname of directory:%s\n&quot;, n1);
else
printf (&quot;Unable to create directory\n&quot;);}
if(strcmp(c,&quot;vi&quot;)==0){
fptr1 = fopen (n1, &quot;a&quot;);
if (fptr1 == NULL)

{
printf (&quot;Cannot open file %s \n&quot;, n1);
exit (0);
}
else
{
printf (&quot;file opened&quot;);
}
}
if(strcmp(c,&quot;copy&quot;)==0){
fptr1 = fopen (n1, &quot;w&quot;);
if (fptr1 == NULL)
{
printf (&quot;Cannot open file %s \n&quot;, n1);
exit (0);
}
fptr2 = fopen (n2, &quot;w&quot;);
if (fptr2 == NULL)
{
printf (&quot;Cannot open file %s \n&quot;, n2);
exit (0);
}
p = fgetc (fptr1);
while (p != EOF)
{
fputc (p, fptr2);
p = fgetc (fptr1);
}
printf (&quot;\nContents copied to %s&quot;, n2);
fclose (fptr1);
fclose (fptr2);
}

if(strcmp(c,&quot;mov&quot;)==0){
fptr1 = fopen (n1, &quot;r&quot;);
if (fptr1 == NULL)
{
printf (&quot;Cannot open file %s \n&quot;, n1);
exit (0);
}
fptr2 = fopen (n2, &quot;w&quot;);
if (fptr2 == NULL)
{
printf (&quot;Cannot open file %s \n&quot;, n2);
exit (0);
}
p = fgetc (fptr1);
while (p != EOF)
{
fputc (p, fptr2);
p = fgetc (fptr1);
}
fclose (fptr1);
fptr1 = fopen (n1, &quot;w&quot;);
printf (&quot;\nContents copied to %s and deleted from %s&quot;, n1, n2);
fclose (fptr1);
fclose (fptr2);
}
if(strcmp(c,&quot;append&quot;)==0){
fptr1 = fopen (n1, &quot;r&quot;);
fptr2 = fopen (n2, &quot;r&quot;);
if (fptr1 == NULL || fptr2 == NULL)
{
printf (&quot;Press any key to exit...\n&quot;);
exit (EXIT_FAILURE);
}
ftemp = fopen (&quot;abc.txt&quot;, &quot;w&quot;);

if (ftemp == NULL)
{
printf (&quot;Press any key to exit...\n&quot;);
exit (EXIT_FAILURE);
}
while ((ch = fgetc (fptr1)) != EOF)
fputc (ch, ftemp);
while ((ch = fgetc (fptr2)) != EOF)
fputc (ch, ftemp);
printf (&quot;Two files merged successfully.\n&quot;);
fclose (fptr1);
fclose (fptr2);
fclose (ftemp);
}
if(strcmp(c,&quot;ls&quot;)==0){
if (dr == NULL)
{
printf (&quot;Could not open current directory&quot;);
return 0;
}
while ((de = readdir (dr)) != NULL)
printf (&quot;%s\n&quot;, de-&gt;d_name);
closedir (dr);
}
if(strcmp(c,&quot;grep&quot;)==0){
fptr1 = fopen (n1, &quot;r&quot;);
while (!feof (fptr1))
{
fgets (temp, 1000, fptr1);
if (strstr (temp, n2))
printf (&quot;%s&quot;, temp);
}
fclose (fptr1);

}
if(strcmp(c,&quot;cat&quot;)==0){
fptr1 = fopen (n1, &quot;r&quot;);
while (fscanf (fptr1, &quot;%[^\n]\n&quot;, line) != EOF)
{
printf (&quot;%s\n&quot;, line);
}
fclose (fptr1);
}
if(strcmp(c,&quot;exit&quot;)==0){
exit (0);
}
if(strcmp(c,&quot;delete&quot;)==0){
if (remove (n1) == 0)
printf (&quot;Deleted successfully&quot;);
else
printf (&quot;Unable to delete the file&quot;);
}
ch=99;
}
}

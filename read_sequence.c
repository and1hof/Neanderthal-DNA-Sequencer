#include <stdio.h>
#include <string.h>

int read_sequence(char * filename, char * sequence, char * name) {
 
  /* Assume lines don't extend beyond 1024 chars. */
  char line[1024];
  
  /* Open file sP with given file location: filename. Open for reading. */
  FILE * sP;
  sP = fopen (filename,"r");
  
  /* Provide user feedback when opened file correctly. */
  if (sP != NULL) {
   //printf("Sequence file: %s opened successfully!\n", filename);
  } else {
   fprintf(stderr, "ERROR: sequence cannot be read. Terminating application.\n");
  }
  
  /* Grab the name of the sequence. It is the first line, but requires some logic to parse. */
  int firstLine = 0;
  while (fgets(line, sizeof line, sP) != NULL && firstLine == 0) {
    strtok(line, "\n"); /* kill the newline char \n */
    strcpy(name, line); /* copy the first line into the name variable. */
    name = name + 1; /* move the pointer one to the right so that the > char falls off of the string. */
    firstLine++; /* ensure we only grab first line here. */
  }
  printf("%s\n", name);
  printf("%s\n", "Enzyme	Number of Fragments	Fragment Sizes");
  fclose(sP);

 /* Re-open sP starting from the beginning. */
 sP = fopen (filename,"r");
 /* Create buffer, and fast-forwards so we skip line #1. */
 char buffer[100];
 /* As long as the buffer is 100, c interperts it as the first line. (provided first line is under 100 char, which all of ours are.) */
 fgets(buffer, 100, sP);
 
  /* store all lines minus line #1 in the sequence string. */
  while (fgets(line, sizeof(line), sP)) { 
     strtok(line, "\n"); /* eliminate trailing \n chars. */
     strcat (sequence, line); /* add line to existing sequence. */
  }
  
  /* grab sequence length. */
  int length = strlen(sequence);
  /* close the file pointer to save memory. */
  fclose(sP);

 /* return the length of this DNA sequence. */
 return length; 
}

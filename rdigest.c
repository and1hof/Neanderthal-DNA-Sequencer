/* rdigest.h manages all of the includes required for this program to run. */
#include "rdigest.h"

/*
 * The main method has two important params.
 * @param argc is an integer which represents the number of command line arguments passed in via the user.
 * @param *argv[] is an array of pointers, each pointing to a string which represents passed in arguments. Argv index 0 is the filename. 
 * @return an integer of 0 or 1 to show if execution of this program was successful.
*/
int main(int argc, char * argv[]) {
	
	/* Max sequence length: 50,000. Max sequence file-name length: 1024. */
	char sequence[50000], sequence_name[1024];
	/* Maximum number of fragments: 128. */
	int fragment_lengths[128];
	
	/* Char pointers in1 and in2 point to the index 0 of the two command-line inputs (not including filename). 
	 * Both are stored as text files.
	*/
	/* Pointer in1 contains a sequence. */
	char * sequence_filename = NULL;
	/* Pointer in2 contains a list of enzymes. */
	char * enzyme_list_filename = NULL;

	/*
	 * Because we require both a sequence and an enzyme list, we must ensure we have two command-line params passed in.
	 * To do this, we ensure argc is equal to three (filename, sequence, enzyme list). 
	*/
	if (argc != 3) { 
		fprintf(stderr, "ERROR: Incorrect numbers of arguments (%d). Expected 2 arguments (sequence, enzyme list).\n", (argc - 1));
		return 1;
	}
	//printf("%s", "Arguments valid.\n");
	
	/* 
	 * FILE POINTERS.
	 * We must create two file pointers, one for the sequence (input #1), and one for the enzyme list (input #2).
	*/
	FILE * sP; /* sequence pointer */
	FILE * eP; /* enzyme pointer */
	
	/* Set sequence file name pointer to the input argument #1. */
	sequence_filename = argv[1];
	/* Set enzyme list file name pointer to the input argument #2. */
	enzyme_list_filename = argv[2];
	/* Inform user this was successful. */
	//printf("Sequence file read as: %s\n", sequence_filename);
    //printf("Enzyme file read as %s\n", enzyme_list_filename);


	/*read in the sequence from the sequence filename by calling the function read_sequence
	 * It will look something like:
	 * sequence_length=read_sequence(sequence_file,sequence,sequence_name);
	 * 
	 * where sequence and sequence_name are string variables
	 *  
	 * Check that there is a sequence_length is not zero before proceeding
	 * 
	 */
	 
	 /* Now call read_sequence to determine sequence_length. */
	 int sequence_length = read_sequence(sequence_filename, sequence, sequence_name);
	 //printf("Sequence Length: %d\n", sequence_length);
	 
	/* Open the list of enzymes. */
	 eP = fopen (enzyme_list_filename, "r");

 	/* Ensure the enzyme list opened correctly. */
	if (eP != NULL) { 
		
		/* Default sizes for line-length, enzyme name length and enzyme site length. */
		char line[1024], enzyme_name[64], enzyme_site[32];

		/* Read in the enzyme file. */
		while (fgets(line, sizeof line, eP)) { 

			/* Parse the enzymes using sscanf. */
			sscanf (line,"%s %s", enzyme_name, enzyme_site);
			//printf("%s %s\n", enzyme_name, enzyme_site);

			int nfragments = digest(sequence, enzyme_site, fragment_lengths);
			/* call the function digest - something like:
			 *
			 * nfragments=digest(sequence,enzyme_site,fragment_lengths);
			 * 
			 * where fragment_lengths is an array containing the fragment lengths 
			 * 
			 */

			/* print out the name of the enzyme and a tab */
			printf("%s	", enzyme_name);

			/*print out the number of fragments and a tab*/
			printf("%d	", nfragments);

			/* have a for loop print out the first nfragments elements of fragment_lengths 
			 * each length is followed by a space (NOT a tab) */
			int i;
			for (i = 0; i < nfragments; i++) {
				printf("%d ", fragment_lengths[i]);
			}

			/*print a newline character after the for loop printing out the fragment_lengths is done*/
			printf("\n");
		}

	}
	return (1);
}

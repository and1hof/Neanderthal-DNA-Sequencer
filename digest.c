#include <stdio.h>
#include <string.h>

/* Insertion Sort algorithm at bottom of page. */
void insertion_sort(int * array, int array_size);

int digest(char * sequence, char * enzyme_site, int * fragments) {
	
	/* Integer to store the number of fragments found. */
	int nfragments = 0;
	/* initialize left free end location */
	int lfree_end = 0;
	/* assign a value to last so that the the sequence starting sequence[i] is at least the length of the enzyme site */
	int last = strlen(enzyme_site); /* store length of enzyme site. sequence[i] must contain this many or more chars to be valid. */
	
	//printf("%s (%d)\n", enzyme_site, last);
	/*loop a pointer from the beginning of the sequence string to almost to the end of the string - you want to make sure that there are always as many characters in the substring pointed to by the pointer are at least the length of the enzyme site */

	
	int sequence_length = strlen(sequence);
	//printf("%d\n", sequence_length);
	int i = 0;
	
	while (i <= sequence_length) { /* iterate through the sequence */
		//printf("%d", i);
		
		if (sequence_length - i >= last) { /* make sure substring we check is large enough to contain something. */
			/* check to see if enzyme can be found anywhere in the sequence. */
			if (strncmp (enzyme_site, &sequence[i], last) == 0) {
				fragments[nfragments] = i-lfree_end;
				nfragments++;
				lfree_end = i;
			}
		}
		i++;
	}

/* the DNA is linear so there is always going to be an extra free end at end of the sequence - 
 * so we have to take this into account with the next statement*/
fragments[nfragments++] = strlen(sequence) - lfree_end;

/* call insertion sort on fragments */
insertion_sort(fragments, nfragments);

/* Return the number of fragments. */
return (nfragments);
}

/* 
 * A standard insertion sort algorithm.
 * O(n^2) time complexity. (worst case)
 * O(1) space complexity. (worst case)
 *
 * https://en.wikipedia.org/wiki/Insertion_sort 
*/
void insertion_sort(int * array, int array_size) {
    int i, j, temp;
    
    for (i = 1; i < array_size; i++) {
        temp = array[i];
        for (j = i; j > 0 && temp < array[j - 1]; j--) {
            array[j] = array[j - 1];
        }
        array[j] = temp;
    }
}

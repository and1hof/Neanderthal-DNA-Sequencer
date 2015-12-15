#!/bin/sh

mkdir ./results

#statement to run rdigest on control DNA
./rdigest sequences/lambda.fa enzyme_list > results/lambda_fragments.txt

#add 2 similar statements to run rdigest on human.fa and neanderthal.fa
./rdigest sequences/human.fa enzyme_list > results/human_fragments.txt
./rdigest sequences/neanderthal.fa enzyme_list > results/neanderthal_fragments.txt

#remove the first two lines using 'tail' and pipe the output to 'cut'
#use cut to keep the first two columns (i.e. the name and the number of cuts 
#For human DNA the command will be of the form 
# tail <proper flags> results/human_fragments.txt | cut <proper flags>  > results/human_nfragments.txt
# use google or man to find the proper flags
tail -n+3 results/human_fragments.txt | cut -d "	" -f 1,2 > results/human_nfragments.txt
#Repeat for neanderthal DNA the command will be of the form 
# tail <proper flags> results/neanderthal_fragments.txt | cut <proper flags>  > results/neanderthal_nfragments.txt
tail -n+3 results/neanderthal_fragments.txt | cut -d "	" -f 1,2 > results/neanderthal_nfragments.txt


# now compare each line of human_nfragments and print out the lines that are *not* found in neanderthal_nfragments (or vice versa)
# then pipe this to cut to keep only the enzyme names
# the command looks like
# grep <proper flags> results/human_nfragments.txt results/neanderthal_nfragments.txt | cut <proper flags>  > results/good_enzymes.txt
grep -f results/human_nfragments.txt results/neanderthal_nfragments.txt | cut -d "	" -f 1 > results/good_enzymes.txt


# Neanderthal-DNA-Sequencer
This application takes three DNA sequences, a lambdaphage bacteria (control), human and neanderthal. 
By simulating the application of restriction enzymes on the DNA, we can cut the DNA sequences down to manageable snippets. Afterwards, we can compare the Neanderthal and the Human DNA to determine if the Human in question has a Neanderthal ancestor. 

### PREREQUISITES
A Linux machine capable of compiling C90 code.

### GETTING STARTED
Download the repo as a .zip, unzip it on your desktop and compile the code in C90 mode using the MakeFile provided.

### USAGE
1. Run rdigest on the lamda-phage DNA (control): ./rdigest sequences/lambda.fa enzyme_list > results/lambda_fragments.txt
2. Run rdigest on the neanderthal DNA provided lamda runs: ./rdigest sequences/neanderthal.fa enzyme_list > results/neanderthal_fragments.txt
3. Run rdigest on the human DNA: ./rdigest sequences/human.fa enzyme_list > results/human_fragments.txt
4. Remove un-needed lines on Human: tail -n+3 results/human_fragments.txt | cut -d "	" -f 1,2 > results/human_nfragments.txt
5. Remove un-needed lines on Neanderthal: tail -n+3 results/neanderthal_fragments.txt | cut -d "	" -f 1,2 > results/neanderthal_nfragments.txt
6. Compare Human and Neanderthal DNA: grep -f results/human_nfragments.txt results/neanderthal_nfragments.txt | cut -d "	" -f 1 > results/good_enzymes.txt

### WHATS IMPLEMENTED
- Returns reasonably accurate results verifying if a given human has Neanderthal ancestors

### TODO
- Optimize the code-base
- Add a GUI for easier usage

### CONTRIBUTE
If you think you can improve this project, please feel free to make a branch followed by a pull request! 

### LEGAL
This software is provided free of any license, and you are entirely responsible for how you choose to use it.



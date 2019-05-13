#!/bin/bash

# change permissions with 
# chmod +x openface_pNN.sh

#
# USAGE
# sh openface_pNN.sh pNNgXXaMM
# where NN is the number of participant
#      	XX is the gender, and
#	MM is the estimated age


pNNgXXaNN=$1
echo "Participant $pNNgXXaNN"
cd $HOME/hri/tmp/demo_v009 && mkdir -p openface && cd openface
mkdir -p $pNNgXXaNN && cd $pNNgXXaNN
$HOME/hri/OpenFace/build/bin/./Recording   #[Q to exit]

$HOME/hri/OpenFace/build/bin/./FeatureExtraction -rigid -verbose -f live.avi -of "default.txt" -simalign aligned -tracked -vis-aus

# Play the FaceLandmarkVideo
cd processed 
cvlc --loop --fullscreen default.avi
# to stop the video press 'crtl-c' in the terminal


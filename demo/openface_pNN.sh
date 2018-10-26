#!/bin/bash

# change permissions with 
# chmod +x openface_pNN.sh

#
# USAGE
# $ ./openface_pNN.sh pNNgXXaMM
# where NN is the number of participant
#      	XX is the gender, and
#	MM is the estimated age


pNNgXXaNN=$1
echo "Participant $pNNgXXaNN"

cd /home/map479/tmp/openday_v06 && mkdir -p openface && cd openface
mkdir -p $pNNgXXaNN && cd $pNNgXXaNN
~/OpenFace/build/bin/./Record    #[Q to exit]
~/OpenFace/build/bin/./FaceLandmarkVid -f out.avi -ov "flvid.avi"

# Play the FaceLandmarkVideo
cvlc --loop --fullscreen flvid.avi
# to stop the video press 'crtl-c' in the terminal


# This is for later user
# ~/OpenFace/build/bin/./FeatureExtraction -rigid -verbose -f out.avi -of "default.txt" -simalign aligned

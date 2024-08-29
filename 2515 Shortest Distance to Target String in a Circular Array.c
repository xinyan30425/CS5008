int closetTarget(char ** words, int wordsSize, char * target, int startIndex){
    int minDistance = INT_MAX;
    int targetFound = 0;

    for (int i=0; i< wordsSize; i++){
        if (strcmp(words[i],target) == 0){
            targetFound = 1;
            int forwardDistance = (i - startIndex + wordsSize) % wordsSize;
            int backwardDistance = (startIndex -i + wordsSize) % wordsSize;
            int distance = forwardDistance < backwardDistance ? forwardDistance : backwardDistance;
            
            if(distance < minDistance) {
                minDistance = distance;
            }
        }
    }

    if (!targetFound){
        return -1;
    }
    return minDistance;

}
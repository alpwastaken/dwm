#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../util.h"

const char *
playerctlstatus() {
	
  FILE *fp;
  char path[1035];
  char line[128];
  char buf[256];

  /* Open the command for reading. */
  fp = popen("/usr/bin/playerctl status > outputplayerctl", "r");
  
  if (fp == NULL) {
    return "Failed to run command\n";
    exit(1);
  }
  
  pclose(fp);
  
  FILE* fp2;
  fp2 = fopen("outputplayerctl", "r");

  /* Read the output a line at a time - output it. */
  while ( fscanf(fp2,"%[^\n] ", line) != EOF ) {
    sscanf(path, "%s", &line);
    if(strstr(line, "Paused") != NULL) {
    	return "";
    } else if(strstr(line, "Playing") != NULL) {
    	return "";
    }
  }

  // return buf;
}

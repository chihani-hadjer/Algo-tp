#include <stdio.h>
#include <stdlib.h>


//lire une chaîne de caractère de l'utilisateur & Allocation memoire
char *LoadString(int N) {
  	char *str = (char *)malloc((N + 1) * sizeof(char));
    if (str == NULL) {
      		  printf("Erreur d'allocation memoire!\n");
     	      exit(1);
    }
    printf("Entrer une chaine : ");
    fgets(str, N + 1, stdin);
    return str;
}

//Compter la taille de la chaîne sans l'utilisation de la fonction strlen()
int StringLength(char *str) {
		int len = 0;
		while (str[len] != '\0' && str[len] != '\n')
			len++;
		return len;
}

//Copier  la chaîne dans une tableau
void LoadArray(char *p, char arr[]) {
		int i =0;
		while (p[i] != '\0' && '\n') {
			arr[i] = p[i];
			i++;
	}
		arr[i] = '\0';
}


void ReverseArray(char arr[], char rev[], int n) {
	    int i;
	    for (i = 0; i < n; i++) {
     		   rev[i] = arr[n - i - 1];
    }
	    rev[n] = '\0';
} 

//Inverser le contenu de tableau
void DisplayArray(char arr[], int n) {int i;
		for(i = 0; i< n; i++)
				printf("%c ", arr[i]);
		printf("\n");
}

//Compter la somme ASCII
int SumStringASCII(char *p) {
	if(*p == '\0' || *p == '\n') return 0;
	return *p + SumStringASCII(p +1);
}

//Inverser la chaîne  avec la foncutin "recursion"
void ReverseString(char *start, char *end) {
		if (start >= end)return;
		char temp = *start;
		*start = *end;
		*end = temp;
		ReverseString(start + 1, end - 1);
	}

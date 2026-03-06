
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>



typedef struct list  {
char word[20];
struct list *next;
}List_Wt;

//Необходимо составить из слов односвязный список и упорядочить по алфавиту. Список необходимо удалить в конце программы.
//Необходимо использовать данную структуры организации списка.
/*
 * Необходимо реализовать односвязный список и обслуживающие его функции.
add_to_list
 swap_elements
 print_list
 delete_list
*/

 void swap_elements(List_Wt **p)
 {
	 if (*p == NULL) return;
	 char temp[20]={0};
	 List_Wt *currHeadFirst = *p; 
	 List_Wt *currHeadSecond = *p; 
	 List_Wt *Terminate=NULL; 
	 while (currHeadFirst->next)
	 {
		currHeadSecond=*p;
		while(currHeadSecond->next&&currHeadSecond!=Terminate)
		{
			if (strcmp(currHeadSecond->word, currHeadSecond->next->word)>0)
			{
				 strcpy(temp, currHeadSecond->word);
				 strcpy(currHeadSecond->word, currHeadSecond->next->word);
				 strcpy(currHeadSecond->next->word, temp);
			}
			currHeadSecond = currHeadSecond->next;
		}
		 Terminate=currHeadSecond;
		 currHeadFirst = currHeadFirst->next;
		
	 }
 }
 
 


void print_list(List_Wt *f)
{
	List_Wt *p=f;
	while(p)
 {
	printf("%s ",p->word);
	p = p->next;
 }
 printf("\n");
}

void delete_list(List_Wt *p)
{
	List_Wt *priv=p;
	
   while(p)
 {
	p = p->next;
	free(priv);
	priv=p;
 }
}


void add_to_list(List_Wt **head, const char value []) 
{
	List_Wt *new = calloc(1,sizeof(List_Wt));
	int i=0;
	while (value[i]!='\0')
	{
		new->word[i] = value[i];
		i++;
	}
	new->word[i]='\0';
	
	if( *head == NULL ) { // пустой список
		*head = new; // изменяем голову списка
	} 
	else 
	{
		List_Wt *p = *head;
	    while(p->next != NULL)
		{
			p = p->next; //идем в конец списка
		}
		p->next = new;
	}
}




int main(int argc, char **argv)
{
	
	//char text[1000];
	char word[100];
	
	List_Wt * First=NULL;
	

	   while (scanf("%99s", word) == 1)
	   {
		       char *dot = strchr(word, '.');
    
		if (dot != NULL) 
		 {
          *dot = '\0'; // Обрубаем строку в месте точки (ставим терминатор)
        
           // Если перед точкой остались буквы (например, "word"), добавляем их
          if (strlen(word) > 0) {
            add_to_list(&First, word);
			}
			break; // Выходим из цикла
		 }
		   add_to_list(&First, word);
		}
		
	//print_list(First);
	
	swap_elements(&First);

	print_list(First);
	
	delete_list(First);
	
	 
	return 0;
}
/*
 * 
 * 
 *  
 
 // if (currHead->next!=NULL)
		 
//int result=strcmp(currHeadSecond->word, currHeadSecond->next->word);
 *  void swap_elements_(List_Wt **p)
 {
	 
	 while (*p)
	 {
		 if ((*p)->next!=NULL)
		 {
		  int result=strcmp((*p)->word, (*p)->next->word);
			if ( result>0)
			{
				List_Wt *n=(*p)->next->next;
				(*p)->next->next=*p;
				(*p)->next=n;
			}
		 }

		 *p = (*p)->next;
	 }
 }
 
 
	if (fgets(text, sizeof(text), stdin) == NULL) return 1;
	
	int i=0;
	while (text[i] != '\0' && text[i] != '\n'&&text[i]!='.')
	{
		_
	}
	
	
				  char s1[100]={0};
			  int i=0;
			  while ((*p)->next->word[i]!='\0')
			  {
				  s1[i++]=(*p)->next->word[i];
			  }
	
	
	
	*/
	
	//char simbol;
	//List_W * First=calloc(1, sizeof(List_W));
	//head[i]    = (snake_t*)malloc(sizeof(snake_t));
	//struct list 
	//~ do
	//~ {
		//~ scanf ("%c", &simbol);
		
	//~ }
	//~ while(simbol!='.');
	
	

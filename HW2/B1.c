
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>



typedef struct list {
uint64_t address;
size_t size;
char comment[64];
struct list *next;
} list;


uint64_t findMaxBlock(list *head)
{
	if(head == NULL) return 0;
	
	size_t sizeMax;
	list *tmp=head;
	uint64_t address=tmp->address;
	sizeMax=tmp->size;
	while (tmp)
	{
		if (sizeMax<(tmp->size)) 
		{
			sizeMax=tmp->size;
			address=tmp->address;
		}
		tmp=tmp->next;
	}
	return address;
}

int main(int argc, char **argv)
{
	
	return 0;
}


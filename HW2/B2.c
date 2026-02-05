#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


typedef struct list {
void *address;
size_t size;
char comment[64];
struct list *next;
} list;

size_t totalMemoryUsage(list *head)
{
	if(head == NULL) return 0;
	list *tmp=head;
	size_t total=0;
	while (tmp)
	{
		total+=tmp->size;
		tmp=tmp->next;
	}
	return total;
}


int main(int argc, char **argv)
{
	
	return 0;
}


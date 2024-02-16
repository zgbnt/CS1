#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int length = 0;
	node *inc;
	inc = head;

	if(inc != NULL) {
		length++;
		while(inc->next != NULL) {
			inc = inc->next;
			length++;
		}
	}

	return length;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	int i;
	char *str;
	str = (char*)malloc((length(head) + 1) * sizeof(char));
	node *inc = NULL;
	inc = head;
	if (inc != NULL) {
		for(i = 0; inc != NULL; i++) {
			str[i] = inc->letter;
			inc = inc->next;
		}
	}
	str[i] = '\0';

	return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node *newNode = NULL;
	node *inc = NULL;
	inc = *pHead;
	newNode = (node*)malloc(sizeof(node));
	newNode->letter = c;
	newNode->next = NULL;
	if (inc != NULL) {
		while(inc->next != NULL) {
			inc = inc->next;
		}
		inc->next = newNode;
	}
	else {
		*pHead = newNode;
	}
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node *temp;
	temp = *pHead;
	while(temp != NULL) {
		*pHead = temp->next;
		free(temp);
		temp = *pHead;
	}
	*pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");
	if (inFile == NULL) 
		printf("File could not be opened");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}
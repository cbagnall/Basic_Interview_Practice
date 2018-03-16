

typedef void* (callback)(node* data); //generic function which takes
									  //a node and returns void

typedef struct node
{
	int data;
	struct node* next;
}

node* create(int data, node* next)
{
	node* new_node = (node*)malloc(sizeof(node));
	new_node->data = data;
	new_node->next = next;
	return new_node;
}

node* Add_to_Front(node* head, int data)
{
	node* new_node = create(data, head);
	head = new_node;
	return head;
}

node* Add_to_End(node* head, int data)
{
	node* new_node = create(data, NULL);
	node* ptr = head;
	while(ptr->next != NULL){
		ptr = ptr->next;
	}
	ptr->next = new_node;
}

int traverse(node* head, callback f)
{
	node* ptr = head;
	int count = 0;
	while(ptr->next != NULL){
		count++;
		f(ptr);
		ptr = ptr->next;
	}
	return count;
}
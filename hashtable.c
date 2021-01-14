#include <stdio.h>
#include <stdlib.h>

struct data
{
  int key;
  int value;
} *array;
int capacity = 10; //fixed for this program
int size = 0; //initial size of hashtable

int hashFunction(int key)
{
  return (key % capacity); // h(k)= k%capacity
}

void init_array() // array creation according to the capacity
{
  array = (struct data *)malloc(capacity * sizeof(struct data));
  for (int i = 0; i < capacity; i++) //setting all (key,val) pairs to zero
  {
    array[i].key = 0;
    array[i].value = 0;
  }
}

void insert(int key, int value)
{
  int index = hashFunction(key); //find index
  if (array[index].value == 0) //if index is free insert key,val
  {
    array[index].key = key;
    array[index].value = value;
    size++;
    printf("\n Key (%d) has been inserted \n", key);
  }
  else if (array[index].key == key) //if index is occupied by same key update value
  {
    array[index].value = value;
	printf("\n Key (%d) has been updated \n", key);
  }
  else //reporting collision
  {
    printf("\n Collision occured  \n");
  }
}

void remove_element(int key)
{
  int index = hashFunction(key); //find index
  if (array[index].value == 0) //no key
  {
    printf("\n This key does not exist \n");
  }
  else //remove key and value
  {
    array[index].key = 0;
    array[index].value = 0;
    size--;
    printf("\n Key (%d) has been removed \n", key);
  }
}
void display()
{
  int i;
  for (i = 0; i < capacity; i++)
  {
    if (array[i].value == 0)
    {
      printf("\n array[%d]: / ", i);
    }
    else
    {
      printf("\n key: %d array[%d]: %d \t", array[i].key, i, array[i].value);
    }
  }
}

int size_of_hashtable()
{
  return size; //total num of elements in the hash table
}

int main()
{
  int choice, key, value, n;
  int c = 0;
  init_array();

  do
  {
    printf("1.Insert item in the Hash Table"
         "\n2.Remove item from the Hash Table"
         "\n3.Check the size of Hash Table"
         "\n4.Display a Hash Table"
		 "\n5.Exit"
         "\nPlease enter your choice: ");

    scanf("%d", &choice);
    switch (choice)
    {
    case 1:

      printf("Enter key -:\t");
      scanf("%d", &key);
      printf("Enter value -:\t");
      scanf("%d", &value);
      insert(key, value);

      break;

    case 2:

      printf("Enter the key to delete-:");
      scanf("%d", &key);
      remove_element(key);

      break;

    case 3:

      n = size_of_hashtable();
      printf("Size of Hash Table is-:%d\n", n);

      break;

    case 4:

      display();

      break;

	case 5:

      exit(0);

      break;
    default:

      printf("Invalid Input\n");
    }

  } while (1);
}

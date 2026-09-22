#include <stdio.h>
#include <stdlib.h>

typedef struct heap
{
    int *data;
    int capacity;
    int size;
}   t_heap;


t_heap *heap_create(int capacity)
{
    int i = 0;
    t_heap *heap = (t_heap *)malloc(sizeof(t_heap));
    heap->data = (int *)malloc(sizeof(int) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return (heap);
}

static void heapify_down(t_heap *h, int idx)
{
    int l;
    int r;
    int s;
    while (1)
    {
        l = (idx * 2) + 1;
        r = (idx * 2) + 2;
        s = idx;
        if (h->data[l] < h->data[s])
            s = l;
        if(h->data[r] < h->data[s])
            s = l;
        if (idx = s)
            return ;
        swap(h->data[s], h->data[idx]);
        idx = s;
    }
}

void    swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void    heap_extract_min(t_heap *h, int *data)
{
    if (h->size == 0)
        return ;
    h->size--;
    *data = h->data[0];
    if (h->size > 0)
    {
        h->data[0] = h->data[h->size];
        heapify_down(h, 0);
    }
}

void    heap_insert(t_heap *heap, int value)
{
    if (heap->size == heap->capacity)
        return ;
    heap->size++;
    int i = heap->size - 1;
    int parent = 0;
    heap->data[i] = value;
    while (i > 0)
    {
        parent = (i - 1)/ 2;
        if (heap->data[i] < heap->data[parent])
            swap(&heap->data[i], &heap->data[parent]);
        i = parent;
    }
}

int main()
{
    t_heap  *heap = heap_create(6);
    int tab[6] = {2, 3, 5, 8, 4, 0};
    for (int i = 0; i < 6; i++)
        heap_insert(heap, tab[i]);
    printf("[ ");
    for (int i = 0; i < 6; i++)
        printf("| %d |", heap->data[i]);
    printf("]\n");
    return (0);
}

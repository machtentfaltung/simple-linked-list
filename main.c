// Simple Linked List
// Copyright (C) 2024-2025 Matei Pralea <matei.pralea@proton.me>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};

typedef struct Node node_t;

node_t *node_new(int value)
{
    node_t *node = malloc(sizeof(node_t));
    node->value = value;
    node->next = NULL;
    return node;
}

node_t *node_get_random(int amount)
{
    node_t *x = node_new(1);
    node_t *head = x;

    for (int i = 2; i <= amount; i++)
    {
        x->next = node_new(i);
        x = x->next;
    }
    return head;
}

void node_print_from_head(node_t *head)
{
    node_t *x = head;

    while (x != NULL)
    {
        printf("[%p; %d] ", x, x->value);
        x = x->next;
    }
}

int main(int argc, char **argv)
{
    printf("Simple Linked List - Example\n");
    printf("Please enter the amount of nodes to create on the heap: ");
    int amount;
    scanf("%d", &amount);
    node_t *head = node_get_random(amount);
    node_print_from_head(head);
    printf("\n");
    fflush(stdout);
    return 0;
}

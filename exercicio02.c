/*
Compare o desempenho do algoritmo de ordenação por bolha com algoritmo de ordenação o quicksort e
o mergesort, usando arrays de tamanhos diferentes. Meça o tempo de execução e compare os resultado.

*/

//  Lucas Gabriel Pereira de Menezes UC22101832

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *a, int *b);
void generate_random_array(int arr[], int size);
void bubble_sort(int arr[], int size);
int partition(int arr[], int low, int high);
void quick_sort(int arr[], int low, int high);
void merge(int arr[], int left, int mid, int right);
void merge_sort(int arr[], int left, int right);


int main() {
    srand(time(NULL));
    int sizes[] = {1000, 5000, 10000, 50000, 100000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < num_sizes; i++) {
        int size = sizes[i];
        int *arr_bubble = (int *)malloc(sizeof(int) * size);
        int *arr_quick = (int *)malloc(sizeof(int) * size);
        int *arr_merge = (int *)malloc(sizeof(int) * size);

        generate_random_array(arr_bubble, size);
        for (int j = 0; j < size; j++) {
            arr_quick[j] = arr_bubble[j];
            arr_merge[j] = arr_bubble[j];
        }

        // Medir o tempo de execução do Bubble Sort
        clock_t start_time = clock();
        bubble_sort(arr_bubble, size);
        clock_t end_time = clock();
        double bubble_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        // Medir o tempo de execução do Quick Sort
        start_time = clock();
        quick_sort(arr_quick, 0, size - 1);
        end_time = clock();
        double quick_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        // Medir o tempo de execução do Merge Sort
        start_time = clock();
        merge_sort(arr_merge, 0, size - 1);
        end_time = clock();
        double merge_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        printf("Tamanho do array: %d\n", size);
        printf("Tempo de execucao do Bubble Sort: %f segundos\n", bubble_time);
        printf("Tempo de execucao do Quick Sort: %f segundos\n", quick_time);
        printf("Tempo de execucao do Merge Sort: %f segundos\n", merge_time);

        free(arr_bubble);
        free(arr_quick);
        free(arr_merge);
    }

    return 0;
}


// Função para trocar dois elementos em um array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para gerar um array aleatório
void generate_random_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000000;
    }
}

// Implementação do algoritmo Bubble Sort
void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Implementação do algoritmo Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Implementação do algoritmo Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(sizeof(int) * n1);
    int *R = (int *)malloc(sizeof(int) * n2);

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


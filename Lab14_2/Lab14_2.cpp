#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale>

int main() {
    setlocale(LC_ALL, "Ukr");

    int n;
    int i;

    printf("Введiть кiлькiсть елементiв масиву: ");
    scanf_s("%d", &n);

    if (n <= 0) {
        printf("Помилка: Розмiр масиву повинен бути бiльше 0.\n");
        return 1;
    }

    int* array = (int*)malloc(n * sizeof(int));

    if (n > 10) {
        // Заповнення та виведення рандомного масиву, якщо кількість елементів більше 10
        srand((unsigned int)time(NULL));
        printf("Рандомний масив:\n");
        for (i = 0; i < n; i++) {
            array[i] = rand() % 100;
            printf("%d ", array[i]);
        }
        printf("\n");
    }
    else {
        // Введення та виведення елементів масиву вручну, якщо кількість елементів не більше 10
        printf("Введiть елементи масиву:\n");
        for (i = 0; i < n; i++) {
            scanf_s("%d", &array[i]);
        }
    }

    // Вказівник для ітерації через масив та обчислення суми
    int* ptr = array;
    int sum = 0;

    for (i = 0; i < n; i++) {
        sum += *ptr;
        ptr++;
    }

    // Обчислення середнього значення
    double average = (double)sum / n;

    // Виведення результатів
    printf("Середнє значення елементiв масиву: %lf\n", average);

    return 0;
}

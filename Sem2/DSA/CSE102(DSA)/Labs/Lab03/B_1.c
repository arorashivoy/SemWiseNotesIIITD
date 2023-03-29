#include <stdio.h>

void MergeSorted(int array[], int start, int end);
void Merged(int array[], int start, int mid, int end);
int BinarySearch(int array[], int start, int end, int health, int count);
int check(int array[], int x, int health, int count);

int main()
{
    freopen("Helper/testB.txt", "r", stdin);
    freopen("Helper/ansB.txt", "w", stdout);
    int q;
    scanf("%i", &q);
    for (int counter = 0; counter < q; counter++)
    {
        int n, h;
        scanf("%i %i", &n, &h);
        int array[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%i", &array[i]);
        }
        MergeSorted(array, 0, n - 1);
        int k;
        if (n < h)
        {
            k = BinarySearch(array, 0, h, h, n);
        }
        else
        {
            k = 1;
        }
        printf("%i\n", k);
    }
}

void MergeSorted(int array[], int start, int end)
{
    if (start < end)
    {
        int mid;
        mid = (start + end) / 2;
        MergeSorted(array, start, mid);
        MergeSorted(array, mid + 1, end);
        Merged(array, start, mid, end);
    }
}

void Merged(int array[], int start, int mid, int end)
{
    int i, j, l, n1, n2;
    i = 0;
    j = 0;
    l = start;
    n1 = (mid - start + 1);
    n2 = (end - mid);
    int array_1[n1], array_2[n2];
    for (int hello = start; hello < mid + 1; hello++)
    {
        array_1[hello - start] = array[hello];
    }
    for (int yelloe = mid; yelloe < end; yelloe++)
    {
        array_2[yelloe - mid] = array[yelloe + 1];
    }
    while (i < n1 && j < n2)
    {
        if (array_1[i] <= array_2[j])
        {
            array[l] = array_1[i];
            i++;
            l++;
        }
        else
        {
            array[l] = array_2[j];
            j++;
            l++;
        }
    }
    while (i < n1)
    {
        array[l] = array_1[i];
        i++;
        l++;
    }
    while (j < n2)
    {
        array[l] = array_2[j];
        j++;
        l++;
    }
    return;
}

int BinarySearch(int array[], int start, int end, int health, int count)
{
    if (end >= start)
    {
        int mid = (start + end) / 2;
        if (check(array, mid, health, count) == 0)
        {
            return BinarySearch(array, start, mid - 1, health, count);
        }
        return BinarySearch(array, mid + 1, end, health, count);
    }
    return start;
}


int check(int array[], int x, int health, int count)
{
    int sum = x;
    for (int i = 0; i < count - 1; i++)
    {
        if (array[i + 1] - array[i] > x)
        {
            sum += x;
        }
        else
        {
            sum += array[i + 1] - array[i];
        }
    }
    if (sum >= health)
    {
        return 0;
    }
    return 1;
}
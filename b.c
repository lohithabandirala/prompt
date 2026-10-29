
#include <stdio.h>
int main() {
int p, r, i, j, count = 0, found;
int Max[10][10], Allocation[10][10], Need[10][10];
int Available[10], Work[10], Finish[10] = {0};
int SafeSequence[10];
printf("Enter processes and resources: ");
scanf("%d %d", &p, &r);
printf("Enter Maximum Matrix:\n");
for (i = 0; i < p; i++)
for (j = 0; j < r; j++)
scanf("%d", &Max[i][j]);
printf("Enter Allocation Matrix:\n");
for (i = 0; i < p; i++)
for (j = 0; j < r; j++)
scanf("%d", &Allocation[i][j]);
printf("Enter Available Resources    :\n");
for (j = 0; j < r; j++) {
scanf("%d", &Available[j]);
Work[j] = Available[j];
}
// Calculate Need
for (i = 0; i < p; i++)
for (j = 0; j < r; j++)
Need[i][j] = Max[i][j] - Allocation[i][j];
// Find safe sequence
while (count < p) {
found = 0;
for (i = 0; i < p; i++) {
if (Finish[i] == 0) {
for (j = 0; j < r; j++)
if (Need[i][j] > Work[j])
break;
if (j == r) {
for (j = 0; j < r; j++)
Work[j] += Allocation[i][j];
SafeSequence[count++] = i + 1;
Finish[i] = 1;
found = 1;
}
}
}
if (found == 0)
break;
}
if (count == p) {
printf("System is SAFE\nSequence: ");
for (i = 0; i < p; i++)
printf("P%d ", SafeSequence[i]);
} else {
printf("System is UNSAFE");
}
return 0;
}
e
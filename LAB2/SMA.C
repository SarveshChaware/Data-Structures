#include <stdio.h>

void calculateSMA(float prices[], int n, int period) {
    if (period > n) {
        printf("Error: Period cannot be greater than the number of prices.\n");
        return;
    }

    printf("Simple Moving Averages (SMA) for period %d:\n", period);
    for (int i = 0; i <= n - period; i++) {
        float sum = 0.0;

        for (int j = i; j < i + period; j++) {
            sum += prices[j];
        }

        float sma = sum / period;
        printf("SMA starting at day %d: %.2f\n", i + 1, sma);
    }
}

int main() {
    int n, period;

    printf("Enter the number of days: ");
    scanf("%d", &n);

    float prices[n];
    printf("Enter the closing prices for %d days:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &prices[i]);
    }

    printf("Enter the period for SMA: ");
    scanf("%d", &period);

    calculateSMA(prices, n, period);

    return 0;
}
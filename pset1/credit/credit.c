#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long long cc, cc_num_test_1, cc_num_test_2;

    //Prompt user for credit card number
    do
    {
        cc = get_long_long("Number: ");
    }
    while (cc < 0);


    int n1, n2, sum_of_n1, sum_of_n2_products;
    sum_of_n1 = 0;
    sum_of_n2_products = 0;

    cc_num_test_1 = cc;
    cc_num_test_2 = cc;

    //calculate checksum
    while (cc_num_test_1 > 0)
    {
        //get last num in cc
        n1 = cc_num_test_1 % 10;

        //add last num to counter
        sum_of_n1 += n1;

        //subtract last num from cc sequence
        cc_num_test_1 -= n1;

        //divide by 10 to elliminate last place
        cc_num_test_1 /= 10;

        //isolates last digit and set to n2
        n2 = cc_num_test_1 % 10;


        //if digit is more than 9 when multiplied, add digits individually

        if ((n2 * 2) > 9)
        {
            int n2_t2 = n2 * 2;
            sum_of_n2_products += n2_t2 % 10;
            sum_of_n2_products += n2_t2 / 10;
        }
        //multiply digit by 2 then add to sum of n2 products
        else
        {
            sum_of_n2_products += (n2 * 2);
        }

        cc_num_test_1 -= n2;
        cc_num_test_1 /= 10;
    }


    // distinguish cc company
    // validate number's length
    if ((sum_of_n1 + sum_of_n2_products) % 10 == 0)
    {
        bool amex, mc, visa, invalid;

        amex =

            (cc_num_test_2 >= 340000000000000 && cc_num_test_2 < 350000000000000) ||
            (cc_num_test_2 >= 370000000000000 && cc_num_test_2 < 380000000000000);

        mc =
            (cc_num_test_2 >= 5100000000000000 && cc_num_test_2 < 5600000000000000);

        visa =
            (cc_num_test_2 >= 4000000000000 && cc_num_test_2 < 5000000000000) ||
            (cc_num_test_2 >= 4000000000000000 && cc_num_test_2 < 5000000000000000);

        invalid =
            (cc_num_test_2 <= 3999999999999 || cc_num_test_2 >= 5600000000000000) ||
            (cc_num_test_2 >= 350000000000000 && cc_num_test_2 < 369999999999999);

        if (amex)
        {
            printf("AMEX\n");
        }
        else if (mc)
        {
            printf("MASTERCARD\n");
        }
        else if (visa)
        {
            printf("VISA\n");
        }
        else if (invalid)
        {
            printf("INVALID\n");
        }
    }
    else
        {
        printf("INVALID\n");
        }
}
#include <iostream>
#include <iomanip>

void program0()
{
    int count, num;
    std::cout << "Program for counting the number of digits from a number\nEnter the number: ";
    std::cin >> num;
    count = 0;

    // проверка, что были введены числа
    if (std::cin.fail()) // извлечение не производилось
    {
        std::cout << "\nInput error!!!";
        // сбрасываем биты состояния обратно в goodbit, чтобы мы могли использовать ignore()
        std::cin.clear();
        // очищаем недопустимый ввод из потока
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    if (num < 0)
    {
        num *= -1;
    }

    if (num == 0)
    {
        count = 1;
    }
    else
    {
        while (num > 0)
        {
            count++;
            num /= 10;
        }
    }

    std::cout << "There are " << count << " digits in your number.";
}

void program1()
{
    int sum, time;
    double cap, perc;

    std::cout << "Program for calculating the time to recieve a certain amount\nEnter your start capital, monthly percent, required amount, seperating by spaces: ";
    std::cin >> cap >> perc >> sum;

    // проверка, что были введены числа
    if (std::cin.fail()) // извлечение не производилось
    {
        std::cout << "\nInput error!!!";
        // сбрасываем биты состояния обратно в goodbit, чтобы мы могли использовать ignore()
        std::cin.clear();
        // очищаем недопустимый ввод из потока
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    // проверка что начальный капитал больше 0
    if (cap <= 0)
    {
        std::cout << "Your start capital must be more than 0!";
        return;
    }

    // проверка что процент больше 0
    if (perc <= 0)
    {
        std::cout << "Your percent must be > 0!";
        return;
    }

    // проверка что необходимая сумма больше начального капитала
    if (sum < cap)
    {
        std::cout << "Your amount cann't be < your start capital!";
        return;
    }

    time = 0;

    while (cap < sum)
    {
        cap += cap * (perc / 100);
        time++;
        std::cout << std::fixed;
        std::cout << std::setprecision(2);
        std::cout << "month " << time << " Capital: " << cap << "\n";
    }

    std::cout << "Need " << time << " month(s)";    

}

void program2()
{

    {
        std::cout << "Program for counting sign changing in sequence\nEntering sequence of numbers, ending by 0: ";
        int prev = 0, curr, count = 0;

        do
        {
            std::cin >> curr;

            // проверка, что были введены числа
            if (std::cin.fail()) // извлечение не производилось
    {
        std::cout << "\nInput error!!!";
        // сбрасываем биты состояния обратно в goodbit, чтобы мы могли использовать ignore()
        std::cin.clear();
        // очищаем недопустимый ввод из потока
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

            if (prev * curr < 0)
            {
                count++;
            }

            prev = curr;

        }
        while (curr != 0);
        {
        std::cout << "You changed sign " << count << " times";
        }
    }

}

void program3()
{
    int i, n, a;
    double average, sum;
    std::cout << "10 numbers   average\n";

    for (i = 0; i < 3; i++)
    {
        int count = 0;
            sum = 0;

        for (n = 0; n < 10; n++)
        {
            a = rand() % 10;
            sum += a;
            count++;

            std::cout << a << " ";
        }

        average = sum / count;
        std::cout << "  " << average << std::endl;
    }

}

void program4()
{
    int n;
    std::cout << "Output of all 3-digit numbers whose sum of digits is less then N.\nEnter N: ";
    std::cin >> n;

    // проверка, что были введены числа
    if (std::cin.fail()) // извлечение не производилось
    {
        std::cout << "\nInput error!!!";
        // сбрасываем биты состояния обратно в goodbit, чтобы мы могли использовать ignore()
        std::cin.clear();
        // очищаем недопустимый ввод из потока
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    for (int i = 100; i < 1000; i++)
    {
        int sum = i / 100 + i % 100 / 10 + i % 10;
        if (sum < n)
        {
            std::cout << i << " ";
        }
    }
    if (n <= 0)
    {
        std::cout << "Please enter valid number.";
        return;
    }
    else if (n < 2)
    {
        std::cout << "No required numbers.";
    }
}



int main()
{
    bool answer;

    //program0(); //21 []
    //program1(); //22 []
    //program2(); //23 []
    //program3(); //24 [
    //program4(); //25 [


    std::cout << "\nOne more? (1 - yes, 0 - no): ";
    std::cin >> answer;

    if (answer)
    {
        main();
    }
    return 0;
}

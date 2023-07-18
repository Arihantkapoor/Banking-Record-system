/*
Banking record system
author: Arihant Kapoor
Date: 09 - 02 - 2022
To-do: change methods like update record and make it more secure so that balance can't be changed, implement various edge cases in all the functions.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Account
{
private:
    long long int account_number;
    string first_name;
    string last_name;
    double balance;

public:
    Account()
    {
        account_number = 0;
        first_name = " ";
        last_name = " ";
        balance = 0.00;
    }
    void set_data(int acc_num, string f_name, string l_name, double bal)
    {
        account_number = acc_num;
        first_name = f_name;
        last_name = l_name;
        balance = bal;
    }
    void get_data()
    {
        cout << "Account number: " << account_number << endl;
        cout << "First Name: " << first_name << endl;
        cout << "Last Name: " << last_name << endl;
        cout << "Balance: " << balance << endl;
    }
    long long get_number()
    {
        return account_number;
    }
    double get_balance()
    {
        return balance;
    }
    void set_balance(double bal)
    {
        balance = bal;
    }
};

Account read_data()
{
    cout << "Enter the account number: ";
    long long int account_number;
    cin >> account_number;

    cout << "Enter First Name: ";
    string first_name;
    cin >> first_name;

    cout << "Enter Last Name: ";
    string last_name;
    cin >> last_name;

    cout << "Enter Balance: ";
    double balance;
    cin >> balance;

    Account A1;
    A1.set_data(account_number, first_name, last_name, balance);
    return A1;
}

void show_data(vector<Account> vec)
{
    cout << "There are " << vec.size() << " records." << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i].get_data();
        cout << endl;
    }
}

Account Search_result(vector<Account> vec)
{
    cout << "Enter Account number to search: ";
    long long account_num;
    cin >> account_num;
    Account a1;
    int flag = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i].get_number() == account_num)
        {
            a1 = vec[i];
            flag = 1;
            break;
        }
    }

    return a1;
}

int find_account(vector<Account> &vec, long long num)
{
    int index = -1;
    int flag = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i].get_number() == num)
        {
            index = i;
            flag = 1;
            break;
        }
    }
    return index;
}
void deposit_money(vector<Account> &vec)
{
    long long acc_num;
    cout << "Enter the account number: " << endl;
    cin >> acc_num;
    int index = find_account(vec, acc_num);
    double initial_amount = vec[index].get_balance();
    cout << "Enter the money to be deposited: ";
    double money;
    cin >> money;
    double final_amount = initial_amount + money;
    vec[index].set_balance(final_amount);
}

void withdraw_money(vector<Account> &vec)
{
    long long acc_num;
    cout << "Enter the account number: " << endl;
    cin >> acc_num;
    int index = find_account(vec, acc_num);
    double money;
    cout << "Enter the money to withdraw: ";
    cin >> money;
    double initial_amount = vec[index].get_balance();
    if (initial_amount >= money)
    {
        double final_amount = initial_amount - money;
        vec[index].set_balance(final_amount);
    }
    else
    {
        cout << "Sorry Insufficient balance" << endl;
    }
}

void update_record(vector<Account> &vec)
{
    cout << "Enter the account number: " << endl;
    long long acc_num;
    cin >> acc_num;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i].get_number() == acc_num)
        {
            cout << "Enter data to modify: " << endl;
            cout << "Enter the account number: ";
            long long int account_number;
            cin >> account_number;

            cout << "Enter First Name: ";
            string first_name;
            cin >> first_name;

            cout << "Enter Last Name: ";
            string last_name;
            cin >> last_name;

            cout << "Enter Balance: ";
            double balance;
            cin >> balance;

            vec[i].set_data(account_number, first_name, last_name, balance);
            break;
        }
    }
}

void delete_record(vector<Account> &vec)
{
    cout << "Enter the account number: " << endl;
    long long acc_num;
    cin >> acc_num;
    int index = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i].get_number() == acc_num)
        {
            index = i;
            break;
        }
    }

    vec.erase(vec.begin() + index);
}

int main()
{
    int count = 0;
    int choice = 0;

    vector<Account> vec;

    while (choice != 8)
    {
        cout << endl;
        cout << "Select one option: " << endl;
        cout << "1 -> Add record to a file" << endl;
        cout << "2 -> Show record from file" << endl;
        cout << "3 -> Search record from file" << endl;
        cout << "4 -> Deposit Money " << endl;
        cout << "5 -> Withdraw Money " << endl;
        cout << "6 -> Update record" << endl;
        cout << "7 -> Delete record" << endl;
        cout << "8 -> Quit Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            vec.push_back(read_data());
            break;

        case 2:
            show_data(vec);
            break;
        case 3:
        {
            Account a1 = Search_result(vec);
            a1.get_data();
        }
        break;
        case 4:
            deposit_money(vec);
            break;
        case 5:
            withdraw_money(vec);
            break;
        case 6:
            update_record(vec);
            break;
        case 7:
            delete_record(vec);
            break;
        case 8:
            cout << "Exiting." << endl;
            break;
        default:
            cout << "Wrong choice, please enter the correct option." << endl;
        }
    }
    return 0;
}
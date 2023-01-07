#include <iostream>
#include <getopt.h>

using namespace std;

int main(int argc, char *argv[])
{

	{ if (argc==1)
    {
        cout<<"КАЛЬКУЛЯТОР"<< endl<< "Чтобы выбрать действие, нужно ввести один из параметров:" << endl<< "-s — cложение всех введенных значений" << endl << "-m — вычетание первого значения из всех последующий введенных значений"<< endl << "Для того чтобы продолжить запустите программу еще раз с нужным параметром и введите значения через пробел"<< endl;
    }        

	int opt, i, result = 0, x, b ,t;
	while ((opt = getopt (argc, argv, "m:s:")) != -1)
        {
            switch (opt)
            {
                case 's':
        			for(i = 0; i<argc; i++)
        			{
            				cout<< i << ": "<< argv[i] << endl;
        			}			
        			for(i=2; i<argc; i++)
        			{
            			x = strtol(argv[i], NULL, 10);
            			result=result + x;
        			}
        		cout<< "Результат: "<< result<<endl;
               	break;
               	
               	case 'm':
    				for(i = 0; i<argc; i++)
   			 		{
        				cout<< i << ": "<< argv[i] << endl;
    				}	
    				b = 0;
    				for(i=2; i<argc; i++)
    				{
       					x = strtol(argv[i], NULL, 10);
          				t = strtol(argv[2], NULL, 10);
        				result=result + x;
        				b=result - t*2;
    				}
    			cout<< "Результат: "<< b <<endl;
                break;       
            }
        }
    }
}
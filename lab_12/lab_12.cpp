#include <iostream>
#include <fstream>
#include <iostream>


/*На первом шаге мы прочитаем S записей и отсортируем их с помощью подходящей внутренней сортировки. 
Этот набор уже отсортированных записей перепишем в файл А. Затем прочитаем еще S записей, отсортируем их и перепишем в файл В.
Этот процесс продолжается, причем отсортированные блоки записей пишутся попеременно то в файл А, то в файл В.

После того, как входной файл полностью разбит на отсортированные отрезки, мы готовы перейти ко второму шагу - - слиянию этих отрезков.
Каждый из файлов А и В содержит некоторую последова- тельность отсортированных отрезков, однако, как и в случае сортировки слиянием, 
мы ничего не можем сказать о порядке записей в двух различных отрезках. Поэтому мы начинаем с чтения половинок первых отрезков из файлов А и В. 
Читаем мы лишь по половине отрезков, поскольку мы уже выяснили, что в памяти может находиться одновременно лишь S записей,
а нам нужны записи из обоих файлов. Будем теперь сливать эти половинки отрезков в один отрезок файла С. После того, как одна из половинок 
закончится, мы прочтем вторую половинку из того же файла. Когда обработка одного из отрезков будет завершена, конец второго отрезка будет
переписан в файл С. После того, как слияние первых двух отрезков из файлов А и В будет завершено, следующие два отрезка сливаются в файл D. 
Этот процесс слияния отрезков продолжается с попеременной записью слитых отрезков в файлы С и D. По завершении мы получаем два файла, разбитых 
на отсортированные отрезки длины 2S. Затем процесс повторяется, причем отрезки читаются из файлов С и D, а слитые отрезки длины 4S записываются
в файлы А и В. Ясно, что в конце концов отрезки сольются в один отсортированный список в одном из файлов.
*/

void main() 
{
    const int s = 4;
    char mass[s];
    int ss = 0;
    int k, chet;
    chet = 0;
    char N;
    std::ifstream fin("mas.txt");
    std::ofstream aa("A.txt");
    std::ofstream bb("B.txt");

    if (fin.is_open())  //если есть файл
    {
        while (!fin.eof()) //пока он открыт
        {
            if (ss < 4) 
            {
                k = 0;
                // переносим 4 числа из файла в массив
                while (k < s)
                {
                    fin >> N;
                    mass[k] = N;
                    k++;
                }
                for (int i = 0; i < s; i++) 
                {
                    for (int j = i + 1; j < s; j++) 
                    {
                        //swap
                        if (mass[i] > mass[j]) 
                        {
                            char tmp;
                            tmp = mass[i];
                            mass[i] = mass[j];
                            mass[j] = tmp;
                        }
                    }
                }
                // если chet кратно 2, записываем массив в файл А, если нет, то в файл B
                if (chet % 2 == 0) 
                {
                    for (int i = 0; i < s; i++)
                    {
                        aa << mass[i];
                    }
                }
                else 
                {
                    for (int i = 0; i < s; i++) 
                    {
                        bb << mass[i];
                    }
                }
                chet++;
                ss++;;
            }
            else break;
        }
    }
    fin.close();
    aa.close();
    bb.close();

    k = 0;
    std::ofstream cc("C.txt");
    std::ofstream dd("D.txt");

    std::ifstream AA("A.txt");
    std::ifstream BB("B.txt");

    char mas[s];
    char ms[s];
    int dddd = 0;

    while (!AA.eof() && !BB.eof()) 
    {
        if (dddd < 2) 
        {
            k = 0;
            while (k < s)
            {
                AA >> N;
                mas[k++] = N;
            }
            k = 0;
            while (k < s)
            {
                BB >> N;
                ms[k++] = N;
            }

            int aaa, bbb;
            aaa = 0;
            bbb = 0;

            int ggg = 0;

            if (dddd % 4 == 0 || dddd % 4 == 2) 
            {
                while (ggg < 2 * s) 
                {
                    if (aaa < s && bbb < s) 
                    {
                        if (mas[aaa] > ms[bbb]) 
                        {
                            cc << ms[bbb];
                            bbb++;
                        }
                        else 
                        {
                            cc << mas[aaa];
                            aaa++;
                        }
                    }
                    else
                    {
                        if (aaa < s) 
                        {
                            cc << mas[aaa];
                            aaa++;
                        }
                        else if (bbb < s) 
                        {
                            cc << ms[bbb];
                            bbb++;
                        }
                    }
                    ggg++;
                }
            }
            else if (dddd % 4 == 1 || dddd % 4 == 3) 
            {
                while (ggg < 2 * s) 
                {

                    if (aaa < s && bbb < s) 
                    {
                        if (mas[aaa] > ms[bbb]) 
                        {
                            dd << ms[bbb];
                            bbb++;
                        }
                        else 
                        {
                            dd << mas[aaa];
                            aaa++;
                        }
                    }
                    else
                    {
                        if (aaa < s) 
                        {
                            dd << mas[aaa];
                            aaa++;
                        }
                        else if (bbb < s) 
                        {
                            dd << ms[bbb];
                            bbb++;
                        }
                    }
                    ggg++;
                }
            }
            dddd++;
        }
        else
            break;
    }

    cc.close();
    dd.close();
    int eee = 0;

    std::ifstream CC("C.txt");
    std::ifstream DD("D.txt");

    std::ofstream exx("Exit.txt");

    char masi[2 * s];
    char ma[2 * s];
    while (!DD.eof() && !CC.eof()) 
    {
        if (eee < 1)
        {
            k = 0;
            while (k < 2 * s)
            {
                CC >> N;
                masi[k++] = N;
            }
            k = 0;
            while (k < 2 * s)
            {
                DD >> N;
                ma[k++] = N;
            }

            int aaa, bbb;
            aaa = 0;
            bbb = 0;

            int ggg = 0;

            while (ggg < 4 * s) 
            {
                if (aaa < 2 * s && bbb < 2 * s)
                {
                    if (masi[aaa] > ma[bbb])
                    {
                        exx << ma[bbb];
                        bbb++;
                    }
                    else 
                    {
                        exx << masi[aaa];
                        aaa++;
                    }
                }
                else 
                {
                    if (aaa < 2 * s) 
                    {
                        exx << masi[aaa];
                        aaa++;
                    }
                    else if (bbb < 2 * s) 
                    {
                        exx << ma[bbb];
                        bbb++;
                    }
                }
                ggg++;
            }
        }
        else
            break;
        eee++;
    }

    AA.close();
    BB.close();
    CC.close();
    DD.close();
}
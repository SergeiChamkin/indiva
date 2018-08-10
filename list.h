#ifndef LIST_H
#define LIST_H


#include <iostream>
#include <QString>

using namespace std;

// Линейный двунаправленный список со вставкой элементов в начало
class tlist
{
public:
    tlist()
    {
        items = nullptr;
    }

private:
    struct element
    {
        QString data;
        element* prev;
        element* next;
        ~element()
        {
        }
    };
    // Указатель на начало списка
    element* items;
public:
    // Добавление нового элемента в конец списка
    void add(QString data)
    {
        if (items == nullptr)
        {
            items = new element;
            items->prev = nullptr;
            items->next = nullptr;
            items->data = data;
        }
        else
        {
            element* e = new element;
            e->data = data;
            element *items_tmp = items;

            while (items_tmp->next != nullptr) {
                items_tmp = items_tmp->next;
            }

            e->prev = items_tmp;
            e->next = nullptr;
            items_tmp->next = e;
        }
    }
    // Вставка элемента в список после элемента с индексом index
    bool insert(QString data, int index)
    {
        if (items != nullptr)
        {
            int last_index = get_amount() - 1;
            if (index <= last_index && index >= 0)
            {
                if (index == last_index)
                {
                    add(data);
                    return true;
                }
                else
                {
                    auto prev = find(index);
                    //auto next = find(index+1);
                    auto next = prev->next;
                    element* e = new element;
                    e->data = data;
                    e->prev = prev;
                    e->next = next;
                    prev->next = e;
                    next->prev = e;
                    return true;
                }
            }
            else return false;
        }
        else return false;
    }
    // Вывод всех элементов списка на экран
    void print()
    {
        if (items != nullptr)
        {
            element* e = items;
            while (e)
            {
                std::string current_locale_text = e->data.toLocal8Bit().constData();
                cout << current_locale_text << endl;
                e = e->next;
            }
        }
    }
    // Удаление всех элементов из списка
    void remove_all()
    {
        while (items)
        {
            element* temp = items->next;
            delete items;
            items = temp;
        }
    }
    // Удаление элемента из списка
    bool remove_item(int index)
    {
        if (items != nullptr)
        {
            if (index <= get_amount() - 1 && index >= 0)
            {
                auto e = find(index);
                if (e != nullptr)
                {
                    if (e->prev == nullptr) // Начало списка
                    {
                        items = items->next;
                        items->prev = nullptr;
                    }
                    else if (e->next == nullptr) // Конец списка
                    {
                        auto endtlist = find(get_amount() - 1);
                        endtlist = endtlist->prev;
                        endtlist->next = nullptr;
                    }
                    else // Середина списка
                    {
                        e->prev->next = e->next;
                        e->next->prev = e->prev;
                    }
                    delete e;
                    return true;
                }
                else return false;
            }
            else return false;
        }
        else return false;
    }
private:
    // Поиск элемента по его индексу
    element* find(int index) const
    {
        int amount = 0;
        element* e = items;
        while (e)
        {
            if (index == amount)
                return e;
            e = e->next;
            amount++;
        }
        return nullptr;
    }
public:
    // Общее количество элементов в списке
    int get_amount()
    {
        if (items != nullptr)
        {
            int amount = 0;
            element* e = items;
            while (e)
            {
                e = e->next;
                amount++;
            }
            return amount;
        }
        else
        {
            return 0;
        }
    }
    // Перегрузка оператора []
    QString& operator [] (const int& index) const
    {
        auto e = find(index);
        return e->data;
    }
    // Деструктор
    ~tlist()
    {
        remove_all();
    }
};

#endif // LIST_H


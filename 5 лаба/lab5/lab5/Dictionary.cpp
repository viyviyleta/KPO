#include "Dictionary.h"

namespace dictionary {

    // Функция Create создает новый экземпляр словаря с заданным именем и максимальным размером.
    Instance Create(const char name[DICTNAMEMAXSIZE], int size) {
        Instance newDict; // Создаем новый экземпляр структуры Instance для словаря
        if (strlen(name) > DICTNAMEMAXSIZE) { // Проверяем, не превышает ли длина имени словаря максимально допустимый размер
            throw(char*)THROW01; // Если превышает, выбрасываем исключение с соответствующим сообщением
        }
        for (int i = 0; i < strlen(name); i++) { // Копируем имя словаря в новый экземпляр
            newDict.name[i] = name[i];
        }
        newDict.name[strlen(name)] = '\0'; // Добавляем завершающий нулевой символ в конец имени
        if (size > DICTMAXSIZE) { // Проверяем, не превышает ли размер словаря максимально допустимый размер
            throw(char*)THROW02; // Если превышает, выбрасываем исключение с соответствующим сообщением
        }
        newDict.maxsize = size; // Устанавливаем максимально допустимый размер словаря
        newDict.size = 0; // Устанавливаем начальный размер словаря (нулевой, так как словарь пока пуст)
        return newDict; // Возвращаем созданный словарь
    }

    // Функция AddEntry добавляет новую запись в словарь.
    void AddEntry(Instance& inst, Entry ed) {
        if (inst.size == inst.maxsize) throw (char*)THROW03; // Проверяем, не превышает ли количество элементов максимально допустимый размер
        for (int i = 0; i < inst.size; i++) { // Перебираем все элементы словаря
            if (ed.id == inst.dictionary[i]->id) throw (char*)THROW04; // Проверяем, нет ли уже элемента с таким же идентификатором
        }
        inst.dictionary[inst.size] = new Entry(); // Выделяем память под новый элемент словаря
        inst.dictionary[inst.size]->id = ed.id; // Заполняем идентификатор нового элемента
        for (int i = 0; i < strlen(ed.name); i++) { // Копируем имя элемента в словарь
            inst.dictionary[inst.size]->name[i] = ed.name[i];
        }
        inst.dictionary[inst.size]->name[strlen(ed.name)] = '\0'; // Добавляем завершающий нулевой символ в конец имени
        inst.size++; // Увеличиваем размер словаря
    }

    // Функция DelEntry удаляет запись из словаря по заданному идентификатору.
    void DelEntry(Instance& inst, int id) {
        bool isFound = false; // Переменная для отслеживания найденности элемента
        for (int i = 0; i < inst.size; i++) { // Перебираем все элементы словаря
            if (inst.dictionary[i]->id == id) { // Если найден элемент с нужным идентификатором
                isFound = true; // Устанавливаем флаг найденности
                for (int j = i; j < inst.size; j++) { // Смещаем оставшиеся элементы на одну позицию влево
                    inst.dictionary[j] = inst.dictionary[j + 1];
                }
                inst.size--; // Уменьшаем размер словаря
                break; // Прерываем цикл
            }
        }
        if (!isFound) throw THROW06; // Если элемент не найден, выбрасываем исключение
    }

    // Функция GetEntry возвращает запись из словаря по заданному идентификатору.
    Entry GetEntry(Instance inst, int id) {
        Entry getElement; // Создаем объект для хранения найденного элемента
        for (int i = 0; i < inst.size; i++) { // Проходим по всем элементам словаря
            if (id == inst.dictionary[i]->id) { // Если найден элемент с нужным идентификатором
                getElement.id = inst.dictionary[i]->id; // Записываем идентификатор в объект
                for (int j = 0; j < strlen(inst.dictionary[i]->name); j++) // Копируем имя элемента
                    getElement.name[j] = inst.dictionary[i]->name[j];
                getElement.name[strlen(inst.dictionary[i]->name)] = '\0'; // Завершаем строку нулевым символом
                return getElement; // Возвращаем найденный элемент
            }
        }
        throw (char*)THROW05; // Если элемент не найден, выбрасываем исключение
    }

    // Функция UpdEntry обновляет запись в словаре по заданному идентификатору.
    void UpdEntry(Instance& inst, int id, Entry new_ed) {
        bool isFound = false; // Переменная для отслеживания наличия записи с указанным идентификатором
        for (int i = 0; i < inst.size; i++) { // Проходим по всем записям в словаре
            if (inst.dictionary[i]->id == id) { // Если нашли запись с идентификатором id
                for (int j = i; j < inst.size; j++) { // Проверяем, чтобы не было других записей с таким же новым идентификатором
                    if (new_ed.id == inst.dictionary[j]->id) { // Если нашли запись с таким же идентификатором, как новый
                        throw (char*)THROW08; // Вызываем исключение
                    }
                }
                isFound = true; // Устанавливаем флаг, что запись найдена
                // Обновляем данные записи с указанным идентификатором
                inst.dictionary[i]->id = new_ed.id;
                strcpy_s(inst.dictionary[i]->name, new_ed.name);
                break; // Завершаем цикл, так как запись уже найдена и обновлена
            }
            else if (new_ed.id == inst.dictionary[i]->id) { // Если новый идентификатор совпадает с другой записью
                throw (char*)THROW08; // Вызываем исключение
            }
        }
        // Если запись с указанным идентификатором не была найдена
        if (!isFound) {
            throw (char*)THROW07; // Вызываем исключение
        }
    }

    // Функция Delete освобождает память, выделенную для экземпляра словаря.
    void Delete(Instance& inst) {
        for (int i = 0; i < inst.size; i++) {
            delete[] inst.dictionary[i];
        }
        inst.size = 0;
    }

    // Функция Print выводит содержимое словаря в консоль.
    void Print(Instance inst) {
        std::cout << "*******" << inst.name << "*******" << std::endl;
        for (int i = 0; i < inst.size; i++) {
            std::cout << inst.dictionary[i]->id << ' ';
            for (int j = 0; j < strlen(inst.dictionary[i]->name); j++) {
                std::cout << inst.dictionary[i]->name[j];
            }
            std::cout << std::endl;
        }
    }
}

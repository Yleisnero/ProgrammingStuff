#include "queue.h"

    //intitialize next and size
    queue::queue() {
        this->next = nullptr;
        this->size = 0;
    }

    //elements can be inserted at specified index
    void queue::fill(int element, int index) {
        if (this->next == nullptr) {
            this->next = new queue();
            this->next->element = element;
            this->next->next = this->next;
            this->size++;
        } else if (index == -1) {
            queue *helper = next;
            for (int i = 0; i < this->size - 1; i++) {
                helper = helper->next;
            }
            auto *insert = new queue();
            insert->element = element;
            helper->next = insert;
            insert->next = this->next;
            this->size++;
        } else {
            queue *helper;
            if (index > 0)
                helper = this->next;
            else
                helper = this;
            for (int i = 0; i < index - 1; i++) {
                helper = helper->next;
            }
            auto *insert = new queue();
            insert->element = element;
            queue *help2 = helper->next;
            helper->next = insert;
            helper->next->next = help2;
            this->size++;
        }

    }

    //overwrite elements with new array
    void queue::overwrite(vector<int> arr) {
        sort(arr.begin(), arr.end());
        queue *helper = this->next;
        for (int i = 0; i < this->size; i++) {
            helper->element = arr[i];
            helper = helper->next;
        }
    }

    //while printing all elements per default, this function also serves as getter for elements at specified index
    vector<int> queue::print(bool output, int index) {
        queue *helper = this->next;
        vector<int> list;
        if (index == -1) {
            if (output)
                cout << "[";
            for (int i = 0; i < this->size; i++) {
                if (i < this->size - 1 && output) {
                    cout << helper->element << ", ";
                } else if (output) {
                    cout << helper->element;
                }
                list.push_back(helper->element);
                helper = helper->next;
            }
            if (output)
                cout << "]\n";
            return list;
        } else {
            if (output) {
                cout << "[";
                for (int i = 0; i < index; i++) {
                    helper = helper->next;
                }
                cout << helper->element << "]" << endl;
            }
            list[0] = helper->element;
            return list;
        }
    }

    //play some lotto
    void queue::play() {
        for (int j = 0; j < 6; j++) {
            queue *helper = this;
            for (int i = 0; i < rand() % 49; i++)
                helper = helper->next;
            queue *pre = helper;
            helper = helper->next;
            queue *target = helper->next;
            delete[] helper;
            this->size--;
            pre->next = target;
        }
    }

    int queue::get_size() {
        return this->size;
    }


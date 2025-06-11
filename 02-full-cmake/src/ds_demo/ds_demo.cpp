#include "ds_demo/ds_demo.h"
#include "ds/linked_list.h"
#include <fmt/core.h>

namespace ds_demo
{
    void ds_demo()
    {
        ds::DoublyLinkedList<int> list;

        // Append some elements
        list.append(1);
        list.append(2);
        list.append(3);

        // Prepend an element
        list.prepend(0);

        fmt::println("List after appending and prepending: {}", list.toString());
        for (auto it = list.begin(); it != list.end(); ++it)
        {
            fmt::println("Forward iteration: Element: {}", *it);
        }
        for(auto it = list.rbegin(); it != list.rend(); it--)
        {
            fmt::println("Reverse iteration: Element: {}", *it);
        }
    }
}
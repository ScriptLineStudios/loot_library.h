#include <stdio.h>

#define LOOT_LIBRARY
#include "src/loot_library.h"

int main(void) {
    LootTable table = init_desert_temple_loot_table();

    uint64_t loot_seed = 33333;

    LootItem items[64] = {0};
    size_t num_items;
    desert_temple_loot(&table, loot_seed, items, &num_items);

    for (size_t i = 0; i < num_items; i++) {
        printf("%s x %d\n", item_names[items[i].item], items[i].quantity);
        if (items[i].enchanted) {
            printf("   %s %d\n", enchant_names[items[i].enchant], items[i].enchant_level);
        }
    }

    return 0;
}
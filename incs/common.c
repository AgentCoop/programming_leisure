#ifdef DEBUG
FILE *__input;

void
init_debug()
{
    __input = fopen(DEBUG_INPUT, "r");    
}
#endif
    
#ifdef DEBUG
    #undef stdin
    #define stdin __input
#endif
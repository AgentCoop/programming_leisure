#ifdef DEBUG
    #undef stdin
    #define stdin input
    FILE *input;
#endif

void
init_debug()
{
    input = fopen(DEBUG_INPUT, "r");    
}
#undef assert
#undef __assert

#ifdef NDEBUG
#define assert(e) ((void)0)
#else
void __assert(const char *func, const char *file, int line, const char *expr);

#define assert(e)                                                              \
  ((e) ? ((void)0) : (__assert(__func__, __FILE__, __LINE__, #e)))
#endif

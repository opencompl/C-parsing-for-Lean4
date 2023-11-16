typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;
typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;
typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;
typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct {
  int __val[2];
} __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef long int __suseconds64_t;
typedef int __daddr_t;
typedef int __key_t;
typedef int __clockid_t;
typedef void *__timer_t;
typedef long int __blksize_t;
typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;
typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;
typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;
typedef long int __fsword_t;
typedef long int __ssize_t;
typedef long int __syscall_slong_t;
typedef unsigned long int __syscall_ulong_t;
typedef __off64_t __loff_t;
typedef char *__caddr_t;
typedef long int __intptr_t;
typedef unsigned int __socklen_t;
typedef int __sig_atomic_t;
static __uint16_t __bswap_16(__uint16_t __bsx) {
  return ((__uint16_t)((((__bsx) >> 8) & 255) | (((__bsx)&255) << 8)));
}
static __uint32_t __bswap_32(__uint32_t __bsx) {
  return ((((__bsx)&4278190080) >> 24) | (((__bsx)&16711680) >> 8) |
          (((__bsx)&65280) << 8) | (((__bsx)&255) << 24));
}
static __uint64_t __bswap_64(__uint64_t __bsx) {
  return ((((__bsx)&18374686479671623680) >> 56) |
          (((__bsx)&71776119061217280) >> 40) |
          (((__bsx)&280375465082880) >> 24) | (((__bsx)&1095216660480) >> 8) |
          (((__bsx)&4278190080) << 8) | (((__bsx)&16711680) << 24) |
          (((__bsx)&65280) << 40) | (((__bsx)&255) << 56));
}
typedef unsigned int u32;
typedef unsigned short int u16;
typedef long unsigned int size_t;
typedef int wchar_t;
typedef float _Float32;
typedef double _Float64;
typedef double _Float32x;
typedef long double _Float64x;
typedef struct {
  int quot;
  int rem;
} div_t;
typedef struct {
  long int quot;
  long int rem;
} ldiv_t;
typedef struct {
  long long int quot;
  long long int rem;
} lldiv_t;
extern size_t __ctype_get_mb_cur_max(void);
extern double atof(const char *__nptr);
extern int atoi(const char *__nptr);
extern long int atol(const char *__nptr);
extern long long int atoll(const char *__nptr);
extern double strtod(const char *__nptr, char **__endptr);
extern float strtof(const char *__nptr, char **__endptr);
extern long double strtold(const char *__nptr, char **__endptr);
extern long int strtol(const char *__nptr, char **__endptr, int __base);
extern unsigned long int strtoul(const char *__nptr, char **__endptr,
                                 int __base);
extern long long int strtoq(const char *__nptr, char **__endptr, int __base);
extern unsigned long long int strtouq(const char *__nptr, char **__endptr,
                                      int __base);
extern long long int strtoll(const char *__nptr, char **__endptr, int __base);
extern unsigned long long int strtoull(const char *__nptr, char **__endptr,
                                       int __base);
extern char *l64a(long int __n);
extern long int a64l(const char *__s);
typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;
typedef __loff_t loff_t;
typedef __ino_t ino_t;
typedef __dev_t dev_t;
typedef __gid_t gid_t;
typedef __mode_t mode_t;
typedef __nlink_t nlink_t;
typedef __uid_t uid_t;
typedef __off_t off_t;
typedef __pid_t pid_t;
typedef __id_t id_t;
typedef __ssize_t ssize_t;
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;
typedef __key_t key_t;
typedef __clock_t clock_t;
typedef __clockid_t clockid_t;
typedef __time_t time_t;
typedef __timer_t timer_t;
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;
typedef __uint8_t u_int8_t;
typedef __uint16_t u_int16_t;
typedef __uint32_t u_int32_t;
typedef __uint64_t u_int64_t;
typedef int register_t;
static __uint16_t __uint16_identity(__uint16_t __x) { return __x; }
static __uint32_t __uint32_identity(__uint32_t __x) { return __x; }
static __uint64_t __uint64_identity(__uint64_t __x) { return __x; }
typedef struct {
  unsigned long int __val[(1024 / (8 * sizeof(unsigned long int)))];
} __sigset_t;
typedef __sigset_t sigset_t;
struct timeval {
  __time_t tv_sec;
  __suseconds_t tv_usec;
};
struct timespec {
  __time_t tv_sec;
  __syscall_slong_t tv_nsec;
};
typedef __suseconds_t suseconds_t;
typedef long int __fd_mask;
typedef struct {
  __fd_mask __fds_bits[1024 / (8 * (int)sizeof(__fd_mask))];
} fd_set;
typedef __fd_mask fd_mask;
extern int select(int __nfds, fd_set *__readfds, fd_set *__writefds,
                  fd_set *__exceptfds, struct timeval *__timeout);
extern int pselect(int __nfds, fd_set *__readfds, fd_set *__writefds,
                   fd_set *__exceptfds, const struct timespec *__timeout,
                   const __sigset_t *__sigmask);
typedef __blksize_t blksize_t;
typedef __blkcnt_t blkcnt_t;
typedef __fsblkcnt_t fsblkcnt_t;
typedef __fsfilcnt_t fsfilcnt_t;
typedef union {
  unsigned long long int __value64;
  struct {
    unsigned int __low;
    unsigned int __high;
  } __value32;
} __atomic_wide_counter;
typedef struct __pthread_internal_list {
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;
typedef struct __pthread_internal_slist {
  struct __pthread_internal_slist *__next;
} __pthread_slist_t;
struct __pthread_mutex_s {
  int __lock;
  unsigned int __count;
  int __owner;
  unsigned int __nusers;
  int __kind;
  short __spins;
  short __elision;
  __pthread_list_t __list;
};
struct __pthread_rwlock_arch_t {
  unsigned int __readers;
  unsigned int __writers;
  unsigned int __wrphase_futex;
  unsigned int __writers_futex;
  unsigned int __pad3;
  unsigned int __pad4;
  int __cur_writer;
  int __shared;
  signed char __rwelision;
  unsigned char __pad1[7];
  unsigned long int __pad2;
  unsigned int __flags;
};
struct __pthread_cond_s {
  __atomic_wide_counter __wseq;
  __atomic_wide_counter __g1_start;
  unsigned int __g_refs[2];
  unsigned int __g_size[2];
  unsigned int __g1_orig_size;
  unsigned int __wrefs;
  unsigned int __g_signals[2];
};
typedef unsigned int __tss_t;
typedef unsigned long int __thrd_t;
typedef struct {
  int __data;
} __once_flag;
typedef unsigned long int pthread_t;
typedef union {
  char __size[4];
  int __align;
} pthread_mutexattr_t;
typedef union {
  char __size[4];
  int __align;
} pthread_condattr_t;
typedef unsigned int pthread_key_t;
typedef int pthread_once_t;
union pthread_attr_t {
  char __size[56];
  long int __align;
};
typedef union pthread_attr_t pthread_attr_t;
typedef union {
  struct __pthread_mutex_s __data;
  char __size[40];
  long int __align;
} pthread_mutex_t;
typedef union {
  struct __pthread_cond_s __data;
  char __size[48];
  long long int __align;
} pthread_cond_t;
typedef union {
  struct __pthread_rwlock_arch_t __data;
  char __size[56];
  long int __align;
} pthread_rwlock_t;
typedef union {
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;
typedef volatile int pthread_spinlock_t;
typedef union {
  char __size[32];
  long int __align;
} pthread_barrier_t;
typedef union {
  char __size[4];
  int __align;
} pthread_barrierattr_t;
extern long int random(void);
extern void srandom(unsigned int __seed);
extern char *initstate(unsigned int __seed, char *__statebuf,
                       size_t __statelen);
extern char *setstate(char *__statebuf);
struct random_data {
  int32_t *fptr;
  int32_t *rptr;
  int32_t *state;
  int rand_type;
  int rand_deg;
  int rand_sep;
  int32_t *end_ptr;
};
extern int random_r(struct random_data *__buf, int32_t *__result);
extern int srandom_r(unsigned int __seed, struct random_data *__buf);
extern int initstate_r(unsigned int __seed, char *__statebuf, size_t __statelen,
                       struct random_data *__buf);
extern int setstate_r(char *__statebuf, struct random_data *__buf);
extern int rand(void);
extern void srand(unsigned int __seed);
extern int rand_r(unsigned int *__seed);
extern double drand48(void);
extern double erand48(unsigned short int __xsubi[3]);
extern long int lrand48(void);
extern long int nrand48(unsigned short int __xsubi[3]);
extern long int mrand48(void);
extern long int jrand48(unsigned short int __xsubi[3]);
extern void srand48(long int __seedval);
extern unsigned short int *seed48(unsigned short int __seed16v[3]);
extern void lcong48(unsigned short int __param[7]);
struct drand48_data {
  unsigned short int __x[3];
  unsigned short int __old_x[3];
  unsigned short int __c;
  unsigned short int __init;
  unsigned long long int __a;
};
extern int drand48_r(struct drand48_data *__buffer, double *__result);
extern int erand48_r(unsigned short int __xsubi[3],
                     struct drand48_data *__buffer, double *__result);
extern int lrand48_r(struct drand48_data *__buffer, long int *__result);
extern int nrand48_r(unsigned short int __xsubi[3],
                     struct drand48_data *__buffer, long int *__result);
extern int mrand48_r(struct drand48_data *__buffer, long int *__result);
extern int jrand48_r(unsigned short int __xsubi[3],
                     struct drand48_data *__buffer, long int *__result);
extern int srand48_r(long int __seedval, struct drand48_data *__buffer);
extern int seed48_r(unsigned short int __seed16v[3],
                    struct drand48_data *__buffer);
extern int lcong48_r(unsigned short int __param[7],
                     struct drand48_data *__buffer);
extern __uint32_t arc4random(void);
extern void arc4random_buf(void *__buf, size_t __size);
extern __uint32_t arc4random_uniform(__uint32_t __upper_bound);
extern void *malloc(size_t __size);
extern void *calloc(size_t __nmemb, size_t __size);
extern void *realloc(void *__ptr, size_t __size);
extern void free(void *__ptr);
extern void *reallocarray(void *__ptr, size_t __nmemb, size_t __size);
extern void *reallocarray(void *__ptr, size_t __nmemb, size_t __size);
extern void *alloca(size_t __size);
extern void *valloc(size_t __size);
extern int posix_memalign(void **__memptr, size_t __alignment, size_t __size);
extern void *aligned_alloc(size_t __alignment, size_t __size);
extern void abort(void);
extern int atexit(void (*__func)(void));
extern int at_quick_exit(void (*__func)(void));
extern int on_exit(void (*__func)(int __status, void *__arg), void *__arg);
extern void exit(int __status);
extern void quick_exit(int __status);
extern void _Exit(int __status);
extern char *getenv(const char *__name);
extern int putenv(char *__string);
extern int setenv(const char *__name, const char *__value, int __replace);
extern int unsetenv(const char *__name);
extern int clearenv(void);
extern char *mktemp(char *__template);
extern int mkstemp(char *__template);
extern int mkstemps(char *__template, int __suffixlen);
extern char *mkdtemp(char *__template);
extern int system(const char *__command);
extern char *realpath(const char *__name, char *__resolved);
typedef int (*__compar_fn_t)(const void *, const void *);
extern void *bsearch(const void *__key, const void *__base, size_t __nmemb,
                     size_t __size, __compar_fn_t __compar);
extern void qsort(void *__base, size_t __nmemb, size_t __size,
                  __compar_fn_t __compar);
extern int abs(int __x);
extern long int labs(long int __x);
extern long long int llabs(long long int __x);
extern div_t div(int __numer, int __denom);
extern ldiv_t ldiv(long int __numer, long int __denom);
extern lldiv_t lldiv(long long int __numer, long long int __denom);
extern char *ecvt(double __value, int __ndigit, int *__decpt, int *__sign);
extern char *fcvt(double __value, int __ndigit, int *__decpt, int *__sign);
extern char *gcvt(double __value, int __ndigit, char *__buf);
extern char *qecvt(long double __value, int __ndigit, int *__decpt,
                   int *__sign);
extern char *qfcvt(long double __value, int __ndigit, int *__decpt,
                   int *__sign);
extern char *qgcvt(long double __value, int __ndigit, char *__buf);
extern int ecvt_r(double __value, int __ndigit, int *__decpt, int *__sign,
                  char *__buf, size_t __len);
extern int fcvt_r(double __value, int __ndigit, int *__decpt, int *__sign,
                  char *__buf, size_t __len);
extern int qecvt_r(long double __value, int __ndigit, int *__decpt, int *__sign,
                   char *__buf, size_t __len);
extern int qfcvt_r(long double __value, int __ndigit, int *__decpt, int *__sign,
                   char *__buf, size_t __len);
extern int mblen(const char *__s, size_t __n);
extern int mbtowc(wchar_t *__pwc, const char *__s, size_t __n);
extern int wctomb(char *__s, wchar_t __wchar);
extern size_t mbstowcs(wchar_t *__pwcs, const char *__s, size_t __n);
extern size_t wcstombs(char *__s, const wchar_t *__pwcs, size_t __n);
extern int rpmatch(const char *__response);
extern int getsubopt(char **__optionp, char *const *__tokens, char **__valuep);
extern int getloadavg(double __loadavg[], int __nelem);
extern void *memcpy(void *__dest, const void *__src, size_t __n);
extern void *memmove(void *__dest, const void *__src, size_t __n);
extern void *memccpy(void *__dest, const void *__src, int __c, size_t __n);
extern void *memset(void *__s, int __c, size_t __n);
extern int memcmp(const void *__s1, const void *__s2, size_t __n);
extern int __memcmpeq(const void *__s1, const void *__s2, size_t __n);
extern void *memchr(const void *__s, int __c, size_t __n);
extern char *strcpy(char *__dest, const char *__src);
extern char *strncpy(char *__dest, const char *__src, size_t __n);
extern char *strcat(char *__dest, const char *__src);
extern char *strncat(char *__dest, const char *__src, size_t __n);
extern int strcmp(const char *__s1, const char *__s2);
extern int strncmp(const char *__s1, const char *__s2, size_t __n);
extern int strcoll(const char *__s1, const char *__s2);
extern size_t strxfrm(char *__dest, const char *__src, size_t __n);
struct __locale_struct {
  struct __locale_data *__locales[13];
  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;
  const char *__names[13];
};
typedef struct __locale_struct *__locale_t;
typedef __locale_t locale_t;
extern int strcoll_l(const char *__s1, const char *__s2, locale_t __l);
extern size_t strxfrm_l(char *__dest, const char *__src, size_t __n,
                        locale_t __l);
extern char *strdup(const char *__s);
extern char *strndup(const char *__string, size_t __n);
extern char *strchr(const char *__s, int __c);
extern char *strrchr(const char *__s, int __c);
extern size_t strcspn(const char *__s, const char *__reject);
extern size_t strspn(const char *__s, const char *__accept);
extern char *strpbrk(const char *__s, const char *__accept);
extern char *strstr(const char *__haystack, const char *__needle);
extern char *strtok(char *__s, const char *__delim);
extern char *__strtok_r(char *__s, const char *__delim, char **__save_ptr);
extern char *strtok_r(char *__s, const char *__delim, char **__save_ptr);
extern size_t strlen(const char *__s);
extern size_t strnlen(const char *__string, size_t __maxlen);
extern char *strerror(int __errnum);
extern int strerror_r(int __errnum, char *__buf, size_t __buflen);
extern char *strerror_l(int __errnum, locale_t __l);
extern int bcmp(const void *__s1, const void *__s2, size_t __n);
extern void bcopy(const void *__src, void *__dest, size_t __n);
extern void bzero(void *__s, size_t __n);
extern char *index(const char *__s, int __c);
extern char *rindex(const char *__s, int __c);
extern int ffs(int __i);
extern int ffsl(long int __l);
extern int ffsll(long long int __ll);
extern int strcasecmp(const char *__s1, const char *__s2);
extern int strncasecmp(const char *__s1, const char *__s2, size_t __n);
extern int strcasecmp_l(const char *__s1, const char *__s2, locale_t __loc);
extern int strncasecmp_l(const char *__s1, const char *__s2, size_t __n,
                         locale_t __loc);
extern void explicit_bzero(void *__s, size_t __n);
extern char *strsep(char **__stringp, const char *__delim);
extern char *strsignal(int __sig);
extern char *__stpcpy(char *__dest, const char *__src);
extern char *stpcpy(char *__dest, const char *__src);
extern char *__stpncpy(char *__dest, const char *__src, size_t __n);
extern char *stpncpy(char *__dest, const char *__src, size_t __n);
typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;
typedef struct {
  int __count;
  union {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
typedef struct _G_fpos_t {
  __off_t __pos;
  __mbstate_t __state;
} __fpos_t;
typedef struct _G_fpos64_t {
  __off64_t __pos;
  __mbstate_t __state;
} __fpos64_t;
struct _IO_FILE;
typedef struct _IO_FILE __FILE;
struct _IO_FILE;
typedef struct _IO_FILE FILE;
struct _IO_FILE;
struct _IO_marker;
struct _IO_codecvt;
struct _IO_wide_data;
typedef void _IO_lock_t;
struct _IO_FILE {
  int _flags;
  char *_IO_read_ptr;
  char *_IO_read_end;
  char *_IO_read_base;
  char *_IO_write_base;
  char *_IO_write_ptr;
  char *_IO_write_end;
  char *_IO_buf_base;
  char *_IO_buf_end;
  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;
  struct _IO_marker *_markers;
  struct _IO_FILE *_chain;
  int _fileno;
  int _flags2;
  __off_t _old_offset;
  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];
  _IO_lock_t *_lock;
  __off64_t _offset;
  struct _IO_codecvt *_codecvt;
  struct _IO_wide_data *_wide_data;
  struct _IO_FILE *_freeres_list;
  void *_freeres_buf;
  size_t __pad5;
  int _mode;
  char _unused2[15 * sizeof(int) - 4 * sizeof(void *) - sizeof(size_t)];
};
typedef __gnuc_va_list va_list;
typedef __fpos_t fpos_t;
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
extern int remove(const char *__filename);
extern int rename(const char *__old, const char *__new);
extern int renameat(int __oldfd, const char *__old, int __newfd,
                    const char *__new);
extern int fclose(FILE *__stream);
extern FILE *tmpfile(void);
extern char *tmpnam(char[20]);
extern char *tmpnam_r(char __s[20]);
extern char *tempnam(const char *__dir, const char *__pfx);
extern int fflush(FILE *__stream);
extern int fflush_unlocked(FILE *__stream);
extern FILE *fopen(const char *__filename, const char *__modes);
extern FILE *freopen(const char *__filename, const char *__modes,
                     FILE *__stream);
extern FILE *fdopen(int __fd, const char *__modes);
extern FILE *fmemopen(void *__s, size_t __len, const char *__modes);
extern FILE *open_memstream(char **__bufloc, size_t *__sizeloc);
extern void setbuf(FILE *__stream, char *__buf);
extern int setvbuf(FILE *__stream, char *__buf, int __modes, size_t __n);
extern void setbuffer(FILE *__stream, char *__buf, size_t __size);
extern void setlinebuf(FILE *__stream);
extern int fprintf(FILE *__stream, const char *__format, ...);
extern int printf(const char *__format, ...);
extern int sprintf(char *__s, const char *__format, ...);
extern int vfprintf(FILE *__s, const char *__format, __gnuc_va_list __arg);
extern int vprintf(const char *__format, __gnuc_va_list __arg);
extern int vsprintf(char *__s, const char *__format, __gnuc_va_list __arg);
extern int snprintf(char *__s, size_t __maxlen, const char *__format, ...);
extern int vsnprintf(char *__s, size_t __maxlen, const char *__format,
                     __gnuc_va_list __arg);
extern int vdprintf(int __fd, const char *__fmt, __gnuc_va_list __arg);
extern int dprintf(int __fd, const char *__fmt, ...);
extern int fscanf(FILE *__stream, const char *__format, ...);
extern int scanf(const char *__format, ...);
extern int sscanf(const char *__s, const char *__format, ...);
extern int fscanf(FILE *__stream, const char *__format, ...);
extern int scanf(const char *__format, ...);
extern int sscanf(const char *__s, const char *__format, ...);
extern int vfscanf(FILE *__s, const char *__format, __gnuc_va_list __arg);
extern int vscanf(const char *__format, __gnuc_va_list __arg);
extern int vsscanf(const char *__s, const char *__format, __gnuc_va_list __arg);
extern int vfscanf(FILE *__s, const char *__format, __gnuc_va_list __arg);
extern int vscanf(const char *__format, __gnuc_va_list __arg);
extern int vsscanf(const char *__s, const char *__format, __gnuc_va_list __arg);
extern int fgetc(FILE *__stream);
extern int getc(FILE *__stream);
extern int getchar(void);
extern int getc_unlocked(FILE *__stream);
extern int getchar_unlocked(void);
extern int fgetc_unlocked(FILE *__stream);
extern int fputc(int __c, FILE *__stream);
extern int putc(int __c, FILE *__stream);
extern int putchar(int __c);
extern int fputc_unlocked(int __c, FILE *__stream);
extern int putc_unlocked(int __c, FILE *__stream);
extern int putchar_unlocked(int __c);
extern int getw(FILE *__stream);
extern int putw(int __w, FILE *__stream);
extern char *fgets(char *__s, int __n, FILE *__stream);
extern __ssize_t __getdelim(char **__lineptr, size_t *__n, int __delimiter,
                            FILE *__stream);
extern __ssize_t getdelim(char **__lineptr, size_t *__n, int __delimiter,
                          FILE *__stream);
extern __ssize_t getline(char **__lineptr, size_t *__n, FILE *__stream);
extern int fputs(const char *__s, FILE *__stream);
extern int puts(const char *__s);
extern int ungetc(int __c, FILE *__stream);
extern size_t fread(void *__ptr, size_t __size, size_t __n, FILE *__stream);
extern size_t fwrite(const void *__ptr, size_t __size, size_t __n, FILE *__s);
extern size_t fread_unlocked(void *__ptr, size_t __size, size_t __n,
                             FILE *__stream);
extern size_t fwrite_unlocked(const void *__ptr, size_t __size, size_t __n,
                              FILE *__stream);
extern int fseek(FILE *__stream, long int __off, int __whence);
extern long int ftell(FILE *__stream);
extern void rewind(FILE *__stream);
extern int fseeko(FILE *__stream, __off_t __off, int __whence);
extern __off_t ftello(FILE *__stream);
extern int fgetpos(FILE *__stream, fpos_t *__pos);
extern int fsetpos(FILE *__stream, const fpos_t *__pos);
extern void clearerr(FILE *__stream);
extern int feof(FILE *__stream);
extern int ferror(FILE *__stream);
extern void clearerr_unlocked(FILE *__stream);
extern int feof_unlocked(FILE *__stream);
extern int ferror_unlocked(FILE *__stream);
extern void perror(const char *__s);
extern int fileno(FILE *__stream);
extern int fileno_unlocked(FILE *__stream);
extern int pclose(FILE *__stream);
extern FILE *popen(const char *__command, const char *__modes);
extern char *ctermid(char *__s);
extern void flockfile(FILE *__stream);
extern int ftrylockfile(FILE *__stream);
extern void funlockfile(FILE *__stream);
extern int __uflow(FILE *);
extern int __overflow(FILE *, int);
extern void __assert_fail(const char *__assertion, const char *__file,
                          unsigned int __line, const char *__function);
extern void __assert_perror_fail(int __errnum, const char *__file,
                                 unsigned int __line, const char *__function);
extern void __assert(const char *__assertion, const char *__file, int __line);
typedef float float_t;
typedef double double_t;
extern int __fpclassify(double __value);
extern int __signbit(double __value);
extern int __isinf(double __value);
extern int __finite(double __value);
extern int __isnan(double __value);
extern int __iseqsig(double __x, double __y);
extern int __issignaling(double __value);
extern double acos(double __x);
extern double __acos(double __x);
extern double asin(double __x);
extern double __asin(double __x);
extern double atan(double __x);
extern double __atan(double __x);
extern double atan2(double __y, double __x);
extern double __atan2(double __y, double __x);
extern double cos(double __x);
extern double __cos(double __x);
extern double sin(double __x);
extern double __sin(double __x);
extern double tan(double __x);
extern double __tan(double __x);
extern double cosh(double __x);
extern double __cosh(double __x);
extern double sinh(double __x);
extern double __sinh(double __x);
extern double tanh(double __x);
extern double __tanh(double __x);
extern double acosh(double __x);
extern double __acosh(double __x);
extern double asinh(double __x);
extern double __asinh(double __x);
extern double atanh(double __x);
extern double __atanh(double __x);
extern double exp(double __x);
extern double __exp(double __x);
extern double frexp(double __x, int *__exponent);
extern double __frexp(double __x, int *__exponent);
extern double ldexp(double __x, int __exponent);
extern double __ldexp(double __x, int __exponent);
extern double log(double __x);
extern double __log(double __x);
extern double log10(double __x);
extern double __log10(double __x);
extern double modf(double __x, double *__iptr);
extern double __modf(double __x, double *__iptr);
extern double expm1(double __x);
extern double __expm1(double __x);
extern double log1p(double __x);
extern double __log1p(double __x);
extern double logb(double __x);
extern double __logb(double __x);
extern double exp2(double __x);
extern double __exp2(double __x);
extern double log2(double __x);
extern double __log2(double __x);
extern double pow(double __x, double __y);
extern double __pow(double __x, double __y);
extern double sqrt(double __x);
extern double __sqrt(double __x);
extern double hypot(double __x, double __y);
extern double __hypot(double __x, double __y);
extern double cbrt(double __x);
extern double __cbrt(double __x);
extern double ceil(double __x);
extern double __ceil(double __x);
extern double fabs(double __x);
extern double __fabs(double __x);
extern double floor(double __x);
extern double __floor(double __x);
extern double fmod(double __x, double __y);
extern double __fmod(double __x, double __y);
extern int isinf(double __value);
extern int finite(double __value);
extern double drem(double __x, double __y);
extern double __drem(double __x, double __y);
extern double significand(double __x);
extern double __significand(double __x);
extern double copysign(double __x, double __y);
extern double __copysign(double __x, double __y);
extern double nan(const char *__tagb);
extern double __nan(const char *__tagb);
extern int isnan(double __value);
extern double j0(double);
extern double __j0(double);
extern double j1(double);
extern double __j1(double);
extern double jn(int, double);
extern double __jn(int, double);
extern double y0(double);
extern double __y0(double);
extern double y1(double);
extern double __y1(double);
extern double yn(int, double);
extern double __yn(int, double);
extern double erf(double);
extern double __erf(double);
extern double erfc(double);
extern double __erfc(double);
extern double lgamma(double);
extern double __lgamma(double);
extern double tgamma(double);
extern double __tgamma(double);
extern double gamma(double);
extern double __gamma(double);
extern double lgamma_r(double, int *__signgamp);
extern double __lgamma_r(double, int *__signgamp);
extern double rint(double __x);
extern double __rint(double __x);
extern double nextafter(double __x, double __y);
extern double __nextafter(double __x, double __y);
extern double nexttoward(double __x, long double __y);
extern double __nexttoward(double __x, long double __y);
extern double remainder(double __x, double __y);
extern double __remainder(double __x, double __y);
extern double scalbn(double __x, int __n);
extern double __scalbn(double __x, int __n);
extern int ilogb(double __x);
extern int __ilogb(double __x);
extern double scalbln(double __x, long int __n);
extern double __scalbln(double __x, long int __n);
extern double nearbyint(double __x);
extern double __nearbyint(double __x);
extern double round(double __x);
extern double __round(double __x);
extern double trunc(double __x);
extern double __trunc(double __x);
extern double remquo(double __x, double __y, int *__quo);
extern double __remquo(double __x, double __y, int *__quo);
extern long int lrint(double __x);
extern long int __lrint(double __x);
extern long long int llrint(double __x);
extern long long int __llrint(double __x);
extern long int lround(double __x);
extern long int __lround(double __x);
extern long long int llround(double __x);
extern long long int __llround(double __x);
extern double fdim(double __x, double __y);
extern double __fdim(double __x, double __y);
extern double fmax(double __x, double __y);
extern double __fmax(double __x, double __y);
extern double fmin(double __x, double __y);
extern double __fmin(double __x, double __y);
extern double fma(double __x, double __y, double __z);
extern double __fma(double __x, double __y, double __z);
extern double scalb(double __x, double __n);
extern double __scalb(double __x, double __n);
extern int __fpclassifyf(float __value);
extern int __signbitf(float __value);
extern int __isinff(float __value);
extern int __finitef(float __value);
extern int __isnanf(float __value);
extern int __iseqsigf(float __x, float __y);
extern int __issignalingf(float __value);
extern float acosf(float __x);
extern float __acosf(float __x);
extern float asinf(float __x);
extern float __asinf(float __x);
extern float atanf(float __x);
extern float __atanf(float __x);
extern float atan2f(float __y, float __x);
extern float __atan2f(float __y, float __x);
extern float cosf(float __x);
extern float __cosf(float __x);
extern float sinf(float __x);
extern float __sinf(float __x);
extern float tanf(float __x);
extern float __tanf(float __x);
extern float coshf(float __x);
extern float __coshf(float __x);
extern float sinhf(float __x);
extern float __sinhf(float __x);
extern float tanhf(float __x);
extern float __tanhf(float __x);
extern float acoshf(float __x);
extern float __acoshf(float __x);
extern float asinhf(float __x);
extern float __asinhf(float __x);
extern float atanhf(float __x);
extern float __atanhf(float __x);
extern float expf(float __x);
extern float __expf(float __x);
extern float frexpf(float __x, int *__exponent);
extern float __frexpf(float __x, int *__exponent);
extern float ldexpf(float __x, int __exponent);
extern float __ldexpf(float __x, int __exponent);
extern float logf(float __x);
extern float __logf(float __x);
extern float log10f(float __x);
extern float __log10f(float __x);
extern float modff(float __x, float *__iptr);
extern float __modff(float __x, float *__iptr);
extern float expm1f(float __x);
extern float __expm1f(float __x);
extern float log1pf(float __x);
extern float __log1pf(float __x);
extern float logbf(float __x);
extern float __logbf(float __x);
extern float exp2f(float __x);
extern float __exp2f(float __x);
extern float log2f(float __x);
extern float __log2f(float __x);
extern float powf(float __x, float __y);
extern float __powf(float __x, float __y);
extern float sqrtf(float __x);
extern float __sqrtf(float __x);
extern float hypotf(float __x, float __y);
extern float __hypotf(float __x, float __y);
extern float cbrtf(float __x);
extern float __cbrtf(float __x);
extern float ceilf(float __x);
extern float __ceilf(float __x);
extern float fabsf(float __x);
extern float __fabsf(float __x);
extern float floorf(float __x);
extern float __floorf(float __x);
extern float fmodf(float __x, float __y);
extern float __fmodf(float __x, float __y);
extern int isinff(float __value);
extern int finitef(float __value);
extern float dremf(float __x, float __y);
extern float __dremf(float __x, float __y);
extern float significandf(float __x);
extern float __significandf(float __x);
extern float copysignf(float __x, float __y);
extern float __copysignf(float __x, float __y);
extern float nanf(const char *__tagb);
extern float __nanf(const char *__tagb);
extern int isnanf(float __value);
extern float j0f(float);
extern float __j0f(float);
extern float j1f(float);
extern float __j1f(float);
extern float jnf(int, float);
extern float __jnf(int, float);
extern float y0f(float);
extern float __y0f(float);
extern float y1f(float);
extern float __y1f(float);
extern float ynf(int, float);
extern float __ynf(int, float);
extern float erff(float);
extern float __erff(float);
extern float erfcf(float);
extern float __erfcf(float);
extern float lgammaf(float);
extern float __lgammaf(float);
extern float tgammaf(float);
extern float __tgammaf(float);
extern float gammaf(float);
extern float __gammaf(float);
extern float lgammaf_r(float, int *__signgamp);
extern float __lgammaf_r(float, int *__signgamp);
extern float rintf(float __x);
extern float __rintf(float __x);
extern float nextafterf(float __x, float __y);
extern float __nextafterf(float __x, float __y);
extern float nexttowardf(float __x, long double __y);
extern float __nexttowardf(float __x, long double __y);
extern float remainderf(float __x, float __y);
extern float __remainderf(float __x, float __y);
extern float scalbnf(float __x, int __n);
extern float __scalbnf(float __x, int __n);
extern int ilogbf(float __x);
extern int __ilogbf(float __x);
extern float scalblnf(float __x, long int __n);
extern float __scalblnf(float __x, long int __n);
extern float nearbyintf(float __x);
extern float __nearbyintf(float __x);
extern float roundf(float __x);
extern float __roundf(float __x);
extern float truncf(float __x);
extern float __truncf(float __x);
extern float remquof(float __x, float __y, int *__quo);
extern float __remquof(float __x, float __y, int *__quo);
extern long int lrintf(float __x);
extern long int __lrintf(float __x);
extern long long int llrintf(float __x);
extern long long int __llrintf(float __x);
extern long int lroundf(float __x);
extern long int __lroundf(float __x);
extern long long int llroundf(float __x);
extern long long int __llroundf(float __x);
extern float fdimf(float __x, float __y);
extern float __fdimf(float __x, float __y);
extern float fmaxf(float __x, float __y);
extern float __fmaxf(float __x, float __y);
extern float fminf(float __x, float __y);
extern float __fminf(float __x, float __y);
extern float fmaf(float __x, float __y, float __z);
extern float __fmaf(float __x, float __y, float __z);
extern float scalbf(float __x, float __n);
extern float __scalbf(float __x, float __n);
extern int __fpclassifyl(long double __value);
extern int __signbitl(long double __value);
extern int __isinfl(long double __value);
extern int __finitel(long double __value);
extern int __isnanl(long double __value);
extern int __iseqsigl(long double __x, long double __y);
extern int __issignalingl(long double __value);
extern long double acosl(long double __x);
extern long double __acosl(long double __x);
extern long double asinl(long double __x);
extern long double __asinl(long double __x);
extern long double atanl(long double __x);
extern long double __atanl(long double __x);
extern long double atan2l(long double __y, long double __x);
extern long double __atan2l(long double __y, long double __x);
extern long double cosl(long double __x);
extern long double __cosl(long double __x);
extern long double sinl(long double __x);
extern long double __sinl(long double __x);
extern long double tanl(long double __x);
extern long double __tanl(long double __x);
extern long double coshl(long double __x);
extern long double __coshl(long double __x);
extern long double sinhl(long double __x);
extern long double __sinhl(long double __x);
extern long double tanhl(long double __x);
extern long double __tanhl(long double __x);
extern long double acoshl(long double __x);
extern long double __acoshl(long double __x);
extern long double asinhl(long double __x);
extern long double __asinhl(long double __x);
extern long double atanhl(long double __x);
extern long double __atanhl(long double __x);
extern long double expl(long double __x);
extern long double __expl(long double __x);
extern long double frexpl(long double __x, int *__exponent);
extern long double __frexpl(long double __x, int *__exponent);
extern long double ldexpl(long double __x, int __exponent);
extern long double __ldexpl(long double __x, int __exponent);
extern long double logl(long double __x);
extern long double __logl(long double __x);
extern long double log10l(long double __x);
extern long double __log10l(long double __x);
extern long double modfl(long double __x, long double *__iptr);
extern long double __modfl(long double __x, long double *__iptr);
extern long double expm1l(long double __x);
extern long double __expm1l(long double __x);
extern long double log1pl(long double __x);
extern long double __log1pl(long double __x);
extern long double logbl(long double __x);
extern long double __logbl(long double __x);
extern long double exp2l(long double __x);
extern long double __exp2l(long double __x);
extern long double log2l(long double __x);
extern long double __log2l(long double __x);
extern long double powl(long double __x, long double __y);
extern long double __powl(long double __x, long double __y);
extern long double sqrtl(long double __x);
extern long double __sqrtl(long double __x);
extern long double hypotl(long double __x, long double __y);
extern long double __hypotl(long double __x, long double __y);
extern long double cbrtl(long double __x);
extern long double __cbrtl(long double __x);
extern long double ceill(long double __x);
extern long double __ceill(long double __x);
extern long double fabsl(long double __x);
extern long double __fabsl(long double __x);
extern long double floorl(long double __x);
extern long double __floorl(long double __x);
extern long double fmodl(long double __x, long double __y);
extern long double __fmodl(long double __x, long double __y);
extern int isinfl(long double __value);
extern int finitel(long double __value);
extern long double dreml(long double __x, long double __y);
extern long double __dreml(long double __x, long double __y);
extern long double significandl(long double __x);
extern long double __significandl(long double __x);
extern long double copysignl(long double __x, long double __y);
extern long double __copysignl(long double __x, long double __y);
extern long double nanl(const char *__tagb);
extern long double __nanl(const char *__tagb);
extern int isnanl(long double __value);
extern long double j0l(long double);
extern long double __j0l(long double);
extern long double j1l(long double);
extern long double __j1l(long double);
extern long double jnl(int, long double);
extern long double __jnl(int, long double);
extern long double y0l(long double);
extern long double __y0l(long double);
extern long double y1l(long double);
extern long double __y1l(long double);
extern long double ynl(int, long double);
extern long double __ynl(int, long double);
extern long double erfl(long double);
extern long double __erfl(long double);
extern long double erfcl(long double);
extern long double __erfcl(long double);
extern long double lgammal(long double);
extern long double __lgammal(long double);
extern long double tgammal(long double);
extern long double __tgammal(long double);
extern long double gammal(long double);
extern long double __gammal(long double);
extern long double lgammal_r(long double, int *__signgamp);
extern long double __lgammal_r(long double, int *__signgamp);
extern long double rintl(long double __x);
extern long double __rintl(long double __x);
extern long double nextafterl(long double __x, long double __y);
extern long double __nextafterl(long double __x, long double __y);
extern long double nexttowardl(long double __x, long double __y);
extern long double __nexttowardl(long double __x, long double __y);
extern long double remainderl(long double __x, long double __y);
extern long double __remainderl(long double __x, long double __y);
extern long double scalbnl(long double __x, int __n);
extern long double __scalbnl(long double __x, int __n);
extern int ilogbl(long double __x);
extern int __ilogbl(long double __x);
extern long double scalblnl(long double __x, long int __n);
extern long double __scalblnl(long double __x, long int __n);
extern long double nearbyintl(long double __x);
extern long double __nearbyintl(long double __x);
extern long double roundl(long double __x);
extern long double __roundl(long double __x);
extern long double truncl(long double __x);
extern long double __truncl(long double __x);
extern long double remquol(long double __x, long double __y, int *__quo);
extern long double __remquol(long double __x, long double __y, int *__quo);
extern long int lrintl(long double __x);
extern long int __lrintl(long double __x);
extern long long int llrintl(long double __x);
extern long long int __llrintl(long double __x);
extern long int lroundl(long double __x);
extern long int __lroundl(long double __x);
extern long long int llroundl(long double __x);
extern long long int __llroundl(long double __x);
extern long double fdiml(long double __x, long double __y);
extern long double __fdiml(long double __x, long double __y);
extern long double fmaxl(long double __x, long double __y);
extern long double __fmaxl(long double __x, long double __y);
extern long double fminl(long double __x, long double __y);
extern long double __fminl(long double __x, long double __y);
extern long double fmal(long double __x, long double __y, long double __z);
extern long double __fmal(long double __x, long double __y, long double __z);
extern long double scalbl(long double __x, long double __n);
extern long double __scalbl(long double __x, long double __n);
extern int signgam;
enum {
  FP_NAN = 0,
  FP_INFINITE = 1,
  FP_ZERO = 2,
  FP_SUBNORMAL = 3,
  FP_NORMAL = 4
};
extern const char sqlite3_version[];
const char *sqlite3_libversion(void);
const char *sqlite3_sourceid(void);
int sqlite3_libversion_number(void);
int sqlite3_compileoption_used(const char *zOptName);
const char *sqlite3_compileoption_get(int N);
int sqlite3_threadsafe(void);
typedef struct sqlite3 sqlite3;
typedef long long int sqlite_int64;
typedef unsigned long long int sqlite_uint64;
typedef sqlite_int64 sqlite3_int64;
typedef sqlite_uint64 sqlite3_uint64;
int sqlite3_close(sqlite3 *);
int sqlite3_close_v2(sqlite3 *);
typedef int (*sqlite3_callback)(void *, int, char **, char **);
int sqlite3_exec(sqlite3 *, const char *sql,
                 int (*callback)(void *, int, char **, char **), void *,
                 char **errmsg);
typedef struct sqlite3_file sqlite3_file;
struct sqlite3_file {
  const struct sqlite3_io_methods *pMethods;
};
typedef struct sqlite3_io_methods sqlite3_io_methods;
struct sqlite3_io_methods {
  int iVersion;
  int (*xClose)(sqlite3_file *);
  int (*xRead)(sqlite3_file *, void *, int iAmt, sqlite3_int64 iOfst);
  int (*xWrite)(sqlite3_file *, const void *, int iAmt, sqlite3_int64 iOfst);
  int (*xTruncate)(sqlite3_file *, sqlite3_int64 size);
  int (*xSync)(sqlite3_file *, int flags);
  int (*xFileSize)(sqlite3_file *, sqlite3_int64 *pSize);
  int (*xLock)(sqlite3_file *, int);
  int (*xUnlock)(sqlite3_file *, int);
  int (*xCheckReservedLock)(sqlite3_file *, int *pResOut);
  int (*xFileControl)(sqlite3_file *, int op, void *pArg);
  int (*xSectorSize)(sqlite3_file *);
  int (*xDeviceCharacteristics)(sqlite3_file *);
  int (*xShmMap)(sqlite3_file *, int iPg, int pgsz, int, void volatile **);
  int (*xShmLock)(sqlite3_file *, int offset, int n, int flags);
  void (*xShmBarrier)(sqlite3_file *);
  int (*xShmUnmap)(sqlite3_file *, int deleteFlag);
  int (*xFetch)(sqlite3_file *, sqlite3_int64 iOfst, int iAmt, void **pp);
  int (*xUnfetch)(sqlite3_file *, sqlite3_int64 iOfst, void *p);
};
typedef struct sqlite3_mutex sqlite3_mutex;
typedef struct sqlite3_api_routines sqlite3_api_routines;
typedef const char *sqlite3_filename;
typedef struct sqlite3_vfs sqlite3_vfs;
typedef void (*sqlite3_syscall_ptr)(void);
struct sqlite3_vfs {
  int iVersion;
  int szOsFile;
  int mxPathname;
  sqlite3_vfs *pNext;
  const char *zName;
  void *pAppData;
  int (*xOpen)(sqlite3_vfs *, sqlite3_filename zName, sqlite3_file *, int flags,
               int *pOutFlags);
  int (*xDelete)(sqlite3_vfs *, const char *zName, int syncDir);
  int (*xAccess)(sqlite3_vfs *, const char *zName, int flags, int *pResOut);
  int (*xFullPathname)(sqlite3_vfs *, const char *zName, int nOut, char *zOut);
  void *(*xDlOpen)(sqlite3_vfs *, const char *zFilename);
  void (*xDlError)(sqlite3_vfs *, int nByte, char *zErrMsg);
  void (*(*xDlSym)(sqlite3_vfs *, void *, const char *zSymbol))(void);
  void (*xDlClose)(sqlite3_vfs *, void *);
  int (*xRandomness)(sqlite3_vfs *, int nByte, char *zOut);
  int (*xSleep)(sqlite3_vfs *, int microseconds);
  int (*xCurrentTime)(sqlite3_vfs *, double *);
  int (*xGetLastError)(sqlite3_vfs *, int, char *);
  int (*xCurrentTimeInt64)(sqlite3_vfs *, sqlite3_int64 *);
  int (*xSetSystemCall)(sqlite3_vfs *, const char *zName, sqlite3_syscall_ptr);
  sqlite3_syscall_ptr (*xGetSystemCall)(sqlite3_vfs *, const char *zName);
  const char *(*xNextSystemCall)(sqlite3_vfs *, const char *zName);
};
int sqlite3_initialize(void);
int sqlite3_shutdown(void);
int sqlite3_os_init(void);
int sqlite3_os_end(void);
int sqlite3_config(int, ...);
int sqlite3_db_config(sqlite3 *, int op, ...);
typedef struct sqlite3_mem_methods sqlite3_mem_methods;
struct sqlite3_mem_methods {
  void *(*xMalloc)(int);
  void (*xFree)(void *);
  void *(*xRealloc)(void *, int);
  int (*xSize)(void *);
  int (*xRoundup)(int);
  int (*xInit)(void *);
  void (*xShutdown)(void *);
  void *pAppData;
};
int sqlite3_extended_result_codes(sqlite3 *, int onoff);
sqlite3_int64 sqlite3_last_insert_rowid(sqlite3 *);
void sqlite3_set_last_insert_rowid(sqlite3 *, sqlite3_int64);
int sqlite3_changes(sqlite3 *);
sqlite3_int64 sqlite3_changes64(sqlite3 *);
int sqlite3_total_changes(sqlite3 *);
sqlite3_int64 sqlite3_total_changes64(sqlite3 *);
void sqlite3_interrupt(sqlite3 *);
int sqlite3_is_interrupted(sqlite3 *);
int sqlite3_complete(const char *sql);
int sqlite3_complete16(const void *sql);
int sqlite3_busy_handler(sqlite3 *, int (*)(void *, int), void *);
int sqlite3_busy_timeout(sqlite3 *, int ms);
int sqlite3_get_table(sqlite3 *db, const char *zSql, char ***pazResult,
                      int *pnRow, int *pnColumn, char **pzErrmsg);
void sqlite3_free_table(char **result);
char *sqlite3_mprintf(const char *, ...);
char *sqlite3_vmprintf(const char *, va_list);
char *sqlite3_snprintf(int, char *, const char *, ...);
char *sqlite3_vsnprintf(int, char *, const char *, va_list);
void *sqlite3_malloc(int);
void *sqlite3_malloc64(sqlite3_uint64);
void *sqlite3_realloc(void *, int);
void *sqlite3_realloc64(void *, sqlite3_uint64);
void sqlite3_free(void *);
sqlite3_uint64 sqlite3_msize(void *);
sqlite3_int64 sqlite3_memory_used(void);
sqlite3_int64 sqlite3_memory_highwater(int resetFlag);
void sqlite3_randomness(int N, void *P);
int sqlite3_set_authorizer(sqlite3 *,
                           int (*xAuth)(void *, int, const char *, const char *,
                                        const char *, const char *),
                           void *pUserData);
void *sqlite3_trace(sqlite3 *, void (*xTrace)(void *, const char *), void *);
void *sqlite3_profile(sqlite3 *,
                      void (*xProfile)(void *, const char *, sqlite3_uint64),
                      void *);
int sqlite3_trace_v2(sqlite3 *, unsigned uMask,
                     int (*xCallback)(unsigned, void *, void *, void *),
                     void *pCtx);
void sqlite3_progress_handler(sqlite3 *, int, int (*)(void *), void *);
int sqlite3_open(const char *filename, sqlite3 **ppDb);
int sqlite3_open16(const void *filename, sqlite3 **ppDb);
int sqlite3_open_v2(const char *filename, sqlite3 **ppDb, int flags,
                    const char *zVfs);
const char *sqlite3_uri_parameter(sqlite3_filename z, const char *zParam);
int sqlite3_uri_boolean(sqlite3_filename z, const char *zParam, int bDefault);
sqlite3_int64 sqlite3_uri_int64(sqlite3_filename, const char *, sqlite3_int64);
const char *sqlite3_uri_key(sqlite3_filename z, int N);
const char *sqlite3_filename_database(sqlite3_filename);
const char *sqlite3_filename_journal(sqlite3_filename);
const char *sqlite3_filename_wal(sqlite3_filename);
sqlite3_file *sqlite3_database_file_object(const char *);
sqlite3_filename sqlite3_create_filename(const char *zDatabase,
                                         const char *zJournal, const char *zWal,
                                         int nParam, const char **azParam);
void sqlite3_free_filename(sqlite3_filename);
int sqlite3_errcode(sqlite3 *db);
int sqlite3_extended_errcode(sqlite3 *db);
const char *sqlite3_errmsg(sqlite3 *);
const void *sqlite3_errmsg16(sqlite3 *);
const char *sqlite3_errstr(int);
int sqlite3_error_offset(sqlite3 *db);
typedef struct sqlite3_stmt sqlite3_stmt;
int sqlite3_limit(sqlite3 *, int id, int newVal);
int sqlite3_prepare(sqlite3 *db, const char *zSql, int nByte,
                    sqlite3_stmt **ppStmt, const char **pzTail);
int sqlite3_prepare_v2(sqlite3 *db, const char *zSql, int nByte,
                       sqlite3_stmt **ppStmt, const char **pzTail);
int sqlite3_prepare_v3(sqlite3 *db, const char *zSql, int nByte,
                       unsigned int prepFlags, sqlite3_stmt **ppStmt,
                       const char **pzTail);
int sqlite3_prepare16(sqlite3 *db, const void *zSql, int nByte,
                      sqlite3_stmt **ppStmt, const void **pzTail);
int sqlite3_prepare16_v2(sqlite3 *db, const void *zSql, int nByte,
                         sqlite3_stmt **ppStmt, const void **pzTail);
int sqlite3_prepare16_v3(sqlite3 *db, const void *zSql, int nByte,
                         unsigned int prepFlags, sqlite3_stmt **ppStmt,
                         const void **pzTail);
const char *sqlite3_sql(sqlite3_stmt *pStmt);
char *sqlite3_expanded_sql(sqlite3_stmt *pStmt);
int sqlite3_stmt_readonly(sqlite3_stmt *pStmt);
int sqlite3_stmt_isexplain(sqlite3_stmt *pStmt);
int sqlite3_stmt_busy(sqlite3_stmt *);
typedef struct sqlite3_value sqlite3_value;
typedef struct sqlite3_context sqlite3_context;
int sqlite3_bind_blob(sqlite3_stmt *, int, const void *, int n,
                      void (*)(void *));
int sqlite3_bind_blob64(sqlite3_stmt *, int, const void *, sqlite3_uint64,
                        void (*)(void *));
int sqlite3_bind_double(sqlite3_stmt *, int, double);
int sqlite3_bind_int(sqlite3_stmt *, int, int);
int sqlite3_bind_int64(sqlite3_stmt *, int, sqlite3_int64);
int sqlite3_bind_null(sqlite3_stmt *, int);
int sqlite3_bind_text(sqlite3_stmt *, int, const char *, int, void (*)(void *));
int sqlite3_bind_text16(sqlite3_stmt *, int, const void *, int,
                        void (*)(void *));
int sqlite3_bind_text64(sqlite3_stmt *, int, const char *, sqlite3_uint64,
                        void (*)(void *), unsigned char encoding);
int sqlite3_bind_value(sqlite3_stmt *, int, const sqlite3_value *);
int sqlite3_bind_pointer(sqlite3_stmt *, int, void *, const char *,
                         void (*)(void *));
int sqlite3_bind_zeroblob(sqlite3_stmt *, int, int n);
int sqlite3_bind_zeroblob64(sqlite3_stmt *, int, sqlite3_uint64);
int sqlite3_bind_parameter_count(sqlite3_stmt *);
const char *sqlite3_bind_parameter_name(sqlite3_stmt *, int);
int sqlite3_bind_parameter_index(sqlite3_stmt *, const char *zName);
int sqlite3_clear_bindings(sqlite3_stmt *);
int sqlite3_column_count(sqlite3_stmt *pStmt);
const char *sqlite3_column_name(sqlite3_stmt *, int N);
const void *sqlite3_column_name16(sqlite3_stmt *, int N);
const char *sqlite3_column_database_name(sqlite3_stmt *, int);
const void *sqlite3_column_database_name16(sqlite3_stmt *, int);
const char *sqlite3_column_table_name(sqlite3_stmt *, int);
const void *sqlite3_column_table_name16(sqlite3_stmt *, int);
const char *sqlite3_column_origin_name(sqlite3_stmt *, int);
const void *sqlite3_column_origin_name16(sqlite3_stmt *, int);
const char *sqlite3_column_decltype(sqlite3_stmt *, int);
const void *sqlite3_column_decltype16(sqlite3_stmt *, int);
int sqlite3_step(sqlite3_stmt *);
int sqlite3_data_count(sqlite3_stmt *pStmt);
const void *sqlite3_column_blob(sqlite3_stmt *, int iCol);
double sqlite3_column_double(sqlite3_stmt *, int iCol);
int sqlite3_column_int(sqlite3_stmt *, int iCol);
sqlite3_int64 sqlite3_column_int64(sqlite3_stmt *, int iCol);
const unsigned char *sqlite3_column_text(sqlite3_stmt *, int iCol);
const void *sqlite3_column_text16(sqlite3_stmt *, int iCol);
sqlite3_value *sqlite3_column_value(sqlite3_stmt *, int iCol);
int sqlite3_column_bytes(sqlite3_stmt *, int iCol);
int sqlite3_column_bytes16(sqlite3_stmt *, int iCol);
int sqlite3_column_type(sqlite3_stmt *, int iCol);
int sqlite3_finalize(sqlite3_stmt *pStmt);
int sqlite3_reset(sqlite3_stmt *pStmt);
int sqlite3_create_function(
    sqlite3 *db, const char *zFunctionName, int nArg, int eTextRep, void *pApp,
    void (*xFunc)(sqlite3_context *, int, sqlite3_value **),
    void (*xStep)(sqlite3_context *, int, sqlite3_value **),
    void (*xFinal)(sqlite3_context *));
int sqlite3_create_function16(
    sqlite3 *db, const void *zFunctionName, int nArg, int eTextRep, void *pApp,
    void (*xFunc)(sqlite3_context *, int, sqlite3_value **),
    void (*xStep)(sqlite3_context *, int, sqlite3_value **),
    void (*xFinal)(sqlite3_context *));
int sqlite3_create_function_v2(
    sqlite3 *db, const char *zFunctionName, int nArg, int eTextRep, void *pApp,
    void (*xFunc)(sqlite3_context *, int, sqlite3_value **),
    void (*xStep)(sqlite3_context *, int, sqlite3_value **),
    void (*xFinal)(sqlite3_context *), void (*xDestroy)(void *));
int sqlite3_create_window_function(
    sqlite3 *db, const char *zFunctionName, int nArg, int eTextRep, void *pApp,
    void (*xStep)(sqlite3_context *, int, sqlite3_value **),
    void (*xFinal)(sqlite3_context *), void (*xValue)(sqlite3_context *),
    void (*xInverse)(sqlite3_context *, int, sqlite3_value **),
    void (*xDestroy)(void *));
int sqlite3_aggregate_count(sqlite3_context *);
int sqlite3_expired(sqlite3_stmt *);
int sqlite3_transfer_bindings(sqlite3_stmt *, sqlite3_stmt *);
int sqlite3_global_recover(void);
void sqlite3_thread_cleanup(void);
int sqlite3_memory_alarm(void (*)(void *, sqlite3_int64, int), void *,
                         sqlite3_int64);
const void *sqlite3_value_blob(sqlite3_value *);
double sqlite3_value_double(sqlite3_value *);
int sqlite3_value_int(sqlite3_value *);
sqlite3_int64 sqlite3_value_int64(sqlite3_value *);
void *sqlite3_value_pointer(sqlite3_value *, const char *);
const unsigned char *sqlite3_value_text(sqlite3_value *);
const void *sqlite3_value_text16(sqlite3_value *);
const void *sqlite3_value_text16le(sqlite3_value *);
const void *sqlite3_value_text16be(sqlite3_value *);
int sqlite3_value_bytes(sqlite3_value *);
int sqlite3_value_bytes16(sqlite3_value *);
int sqlite3_value_type(sqlite3_value *);
int sqlite3_value_numeric_type(sqlite3_value *);
int sqlite3_value_nochange(sqlite3_value *);
int sqlite3_value_frombind(sqlite3_value *);
int sqlite3_value_encoding(sqlite3_value *);
unsigned int sqlite3_value_subtype(sqlite3_value *);
sqlite3_value *sqlite3_value_dup(const sqlite3_value *);
void sqlite3_value_free(sqlite3_value *);
void *sqlite3_aggregate_context(sqlite3_context *, int nBytes);
void *sqlite3_user_data(sqlite3_context *);
sqlite3 *sqlite3_context_db_handle(sqlite3_context *);
void *sqlite3_get_auxdata(sqlite3_context *, int N);
void sqlite3_set_auxdata(sqlite3_context *, int N, void *, void (*)(void *));
typedef void (*sqlite3_destructor_type)(void *);
void sqlite3_result_blob(sqlite3_context *, const void *, int,
                         void (*)(void *));
void sqlite3_result_blob64(sqlite3_context *, const void *, sqlite3_uint64,
                           void (*)(void *));
void sqlite3_result_double(sqlite3_context *, double);
void sqlite3_result_error(sqlite3_context *, const char *, int);
void sqlite3_result_error16(sqlite3_context *, const void *, int);
void sqlite3_result_error_toobig(sqlite3_context *);
void sqlite3_result_error_nomem(sqlite3_context *);
void sqlite3_result_error_code(sqlite3_context *, int);
void sqlite3_result_int(sqlite3_context *, int);
void sqlite3_result_int64(sqlite3_context *, sqlite3_int64);
void sqlite3_result_null(sqlite3_context *);
void sqlite3_result_text(sqlite3_context *, const char *, int,
                         void (*)(void *));
void sqlite3_result_text64(sqlite3_context *, const char *, sqlite3_uint64,
                           void (*)(void *), unsigned char encoding);
void sqlite3_result_text16(sqlite3_context *, const void *, int,
                           void (*)(void *));
void sqlite3_result_text16le(sqlite3_context *, const void *, int,
                             void (*)(void *));
void sqlite3_result_text16be(sqlite3_context *, const void *, int,
                             void (*)(void *));
void sqlite3_result_value(sqlite3_context *, sqlite3_value *);
void sqlite3_result_pointer(sqlite3_context *, void *, const char *,
                            void (*)(void *));
void sqlite3_result_zeroblob(sqlite3_context *, int n);
int sqlite3_result_zeroblob64(sqlite3_context *, sqlite3_uint64 n);
void sqlite3_result_subtype(sqlite3_context *, unsigned int);
int sqlite3_create_collation(sqlite3 *, const char *zName, int eTextRep,
                             void *pArg,
                             int (*xCompare)(void *, int, const void *, int,
                                             const void *));
int sqlite3_create_collation_v2(sqlite3 *, const char *zName, int eTextRep,
                                void *pArg,
                                int (*xCompare)(void *, int, const void *, int,
                                                const void *),
                                void (*xDestroy)(void *));
int sqlite3_create_collation16(sqlite3 *, const void *zName, int eTextRep,
                               void *pArg,
                               int (*xCompare)(void *, int, const void *, int,
                                               const void *));
int sqlite3_collation_needed(sqlite3 *, void *,
                             void (*)(void *, sqlite3 *, int eTextRep,
                                      const char *));
int sqlite3_collation_needed16(sqlite3 *, void *,
                               void (*)(void *, sqlite3 *, int eTextRep,
                                        const void *));
int sqlite3_sleep(int);
extern char *sqlite3_temp_directory;
extern char *sqlite3_data_directory;
int sqlite3_win32_set_directory(unsigned long type, void *zValue);
int sqlite3_win32_set_directory8(unsigned long type, const char *zValue);
int sqlite3_win32_set_directory16(unsigned long type, const void *zValue);
int sqlite3_get_autocommit(sqlite3 *);
sqlite3 *sqlite3_db_handle(sqlite3_stmt *);
const char *sqlite3_db_name(sqlite3 *db, int N);
sqlite3_filename sqlite3_db_filename(sqlite3 *db, const char *zDbName);
int sqlite3_db_readonly(sqlite3 *db, const char *zDbName);
int sqlite3_txn_state(sqlite3 *, const char *zSchema);
sqlite3_stmt *sqlite3_next_stmt(sqlite3 *pDb, sqlite3_stmt *pStmt);
void *sqlite3_commit_hook(sqlite3 *, int (*)(void *), void *);
void *sqlite3_rollback_hook(sqlite3 *, void (*)(void *), void *);
int sqlite3_autovacuum_pages(sqlite3 *db,
                             unsigned int (*)(void *, const char *,
                                              unsigned int, unsigned int,
                                              unsigned int),
                             void *, void (*)(void *));
void *sqlite3_update_hook(sqlite3 *,
                          void (*)(void *, int, char const *, char const *,
                                   sqlite3_int64),
                          void *);
int sqlite3_enable_shared_cache(int);
int sqlite3_release_memory(int);
int sqlite3_db_release_memory(sqlite3 *);
sqlite3_int64 sqlite3_soft_heap_limit64(sqlite3_int64 N);
sqlite3_int64 sqlite3_hard_heap_limit64(sqlite3_int64 N);
void sqlite3_soft_heap_limit(int N);
int sqlite3_table_column_metadata(sqlite3 *db, const char *zDbName,
                                  const char *zTableName,
                                  const char *zColumnName,
                                  char const **pzDataType,
                                  char const **pzCollSeq, int *pNotNull,
                                  int *pPrimaryKey, int *pAutoinc);
int sqlite3_load_extension(sqlite3 *db, const char *zFile, const char *zProc,
                           char **pzErrMsg);
int sqlite3_enable_load_extension(sqlite3 *db, int onoff);
int sqlite3_auto_extension(void (*xEntryPoint)(void));
int sqlite3_cancel_auto_extension(void (*xEntryPoint)(void));
void sqlite3_reset_auto_extension(void);
typedef struct sqlite3_vtab sqlite3_vtab;
typedef struct sqlite3_index_info sqlite3_index_info;
typedef struct sqlite3_vtab_cursor sqlite3_vtab_cursor;
typedef struct sqlite3_module sqlite3_module;
struct sqlite3_module {
  int iVersion;
  int (*xCreate)(sqlite3 *, void *pAux, int argc, const char *const *argv,
                 sqlite3_vtab **ppVTab, char **);
  int (*xConnect)(sqlite3 *, void *pAux, int argc, const char *const *argv,
                  sqlite3_vtab **ppVTab, char **);
  int (*xBestIndex)(sqlite3_vtab *pVTab, sqlite3_index_info *);
  int (*xDisconnect)(sqlite3_vtab *pVTab);
  int (*xDestroy)(sqlite3_vtab *pVTab);
  int (*xOpen)(sqlite3_vtab *pVTab, sqlite3_vtab_cursor **ppCursor);
  int (*xClose)(sqlite3_vtab_cursor *);
  int (*xFilter)(sqlite3_vtab_cursor *, int idxNum, const char *idxStr,
                 int argc, sqlite3_value **argv);
  int (*xNext)(sqlite3_vtab_cursor *);
  int (*xEof)(sqlite3_vtab_cursor *);
  int (*xColumn)(sqlite3_vtab_cursor *, sqlite3_context *, int);
  int (*xRowid)(sqlite3_vtab_cursor *, sqlite3_int64 *pRowid);
  int (*xUpdate)(sqlite3_vtab *, int, sqlite3_value **, sqlite3_int64 *);
  int (*xBegin)(sqlite3_vtab *pVTab);
  int (*xSync)(sqlite3_vtab *pVTab);
  int (*xCommit)(sqlite3_vtab *pVTab);
  int (*xRollback)(sqlite3_vtab *pVTab);
  int (*xFindFunction)(sqlite3_vtab *pVtab, int nArg, const char *zName,
                       void (**pxFunc)(sqlite3_context *, int,
                                       sqlite3_value **),
                       void **ppArg);
  int (*xRename)(sqlite3_vtab *pVtab, const char *zNew);
  int (*xSavepoint)(sqlite3_vtab *pVTab, int);
  int (*xRelease)(sqlite3_vtab *pVTab, int);
  int (*xRollbackTo)(sqlite3_vtab *pVTab, int);
  int (*xShadowName)(const char *);
};
struct sqlite3_index_info {
  int nConstraint;
  struct sqlite3_index_constraint {
    int iColumn;
    unsigned char op;
    unsigned char usable;
    int iTermOffset;
  } *aConstraint;
  int nOrderBy;
  struct sqlite3_index_orderby {
    int iColumn;
    unsigned char desc;
  } *aOrderBy;
  struct sqlite3_index_constraint_usage {
    int argvIndex;
    unsigned char omit;
  } *aConstraintUsage;
  int idxNum;
  char *idxStr;
  int needToFreeIdxStr;
  int orderByConsumed;
  double estimatedCost;
  sqlite3_int64 estimatedRows;
  int idxFlags;
  sqlite3_uint64 colUsed;
};
int sqlite3_create_module(sqlite3 *db, const char *zName,
                          const sqlite3_module *p, void *pClientData);
int sqlite3_create_module_v2(sqlite3 *db, const char *zName,
                             const sqlite3_module *p, void *pClientData,
                             void (*xDestroy)(void *));
int sqlite3_drop_modules(sqlite3 *db, const char **azKeep);
struct sqlite3_vtab {
  const sqlite3_module *pModule;
  int nRef;
  char *zErrMsg;
};
struct sqlite3_vtab_cursor {
  sqlite3_vtab *pVtab;
};
int sqlite3_declare_vtab(sqlite3 *, const char *zSQL);
int sqlite3_overload_function(sqlite3 *, const char *zFuncName, int nArg);
typedef struct sqlite3_blob sqlite3_blob;
int sqlite3_blob_open(sqlite3 *, const char *zDb, const char *zTable,
                      const char *zColumn, sqlite3_int64 iRow, int flags,
                      sqlite3_blob **ppBlob);
int sqlite3_blob_reopen(sqlite3_blob *, sqlite3_int64);
int sqlite3_blob_close(sqlite3_blob *);
int sqlite3_blob_bytes(sqlite3_blob *);
int sqlite3_blob_read(sqlite3_blob *, void *Z, int N, int iOffset);
int sqlite3_blob_write(sqlite3_blob *, const void *z, int n, int iOffset);
sqlite3_vfs *sqlite3_vfs_find(const char *zVfsName);
int sqlite3_vfs_register(sqlite3_vfs *, int makeDflt);
int sqlite3_vfs_unregister(sqlite3_vfs *);
sqlite3_mutex *sqlite3_mutex_alloc(int);
void sqlite3_mutex_free(sqlite3_mutex *);
void sqlite3_mutex_enter(sqlite3_mutex *);
int sqlite3_mutex_try(sqlite3_mutex *);
void sqlite3_mutex_leave(sqlite3_mutex *);
typedef struct sqlite3_mutex_methods sqlite3_mutex_methods;
struct sqlite3_mutex_methods {
  int (*xMutexInit)(void);
  int (*xMutexEnd)(void);
  sqlite3_mutex *(*xMutexAlloc)(int);
  void (*xMutexFree)(sqlite3_mutex *);
  void (*xMutexEnter)(sqlite3_mutex *);
  int (*xMutexTry)(sqlite3_mutex *);
  void (*xMutexLeave)(sqlite3_mutex *);
  int (*xMutexHeld)(sqlite3_mutex *);
  int (*xMutexNotheld)(sqlite3_mutex *);
};
int sqlite3_mutex_held(sqlite3_mutex *);
int sqlite3_mutex_notheld(sqlite3_mutex *);
sqlite3_mutex *sqlite3_db_mutex(sqlite3 *);
int sqlite3_file_control(sqlite3 *, const char *zDbName, int op, void *);
int sqlite3_test_control(int op, ...);
int sqlite3_keyword_count(void);
int sqlite3_keyword_name(int, const char **, int *);
int sqlite3_keyword_check(const char *, int);
typedef struct sqlite3_str sqlite3_str;
sqlite3_str *sqlite3_str_new(sqlite3 *);
char *sqlite3_str_finish(sqlite3_str *);
void sqlite3_str_appendf(sqlite3_str *, const char *zFormat, ...);
void sqlite3_str_vappendf(sqlite3_str *, const char *zFormat, va_list);
void sqlite3_str_append(sqlite3_str *, const char *zIn, int N);
void sqlite3_str_appendall(sqlite3_str *, const char *zIn);
void sqlite3_str_appendchar(sqlite3_str *, int N, char C);
void sqlite3_str_reset(sqlite3_str *);
int sqlite3_str_errcode(sqlite3_str *);
int sqlite3_str_length(sqlite3_str *);
char *sqlite3_str_value(sqlite3_str *);
int sqlite3_status(int op, int *pCurrent, int *pHighwater, int resetFlag);
int sqlite3_status64(int op, sqlite3_int64 *pCurrent, sqlite3_int64 *pHighwater,
                     int resetFlag);
int sqlite3_db_status(sqlite3 *, int op, int *pCur, int *pHiwtr, int resetFlg);
int sqlite3_stmt_status(sqlite3_stmt *, int op, int resetFlg);
typedef struct sqlite3_pcache sqlite3_pcache;
typedef struct sqlite3_pcache_page sqlite3_pcache_page;
struct sqlite3_pcache_page {
  void *pBuf;
  void *pExtra;
};
typedef struct sqlite3_pcache_methods2 sqlite3_pcache_methods2;
struct sqlite3_pcache_methods2 {
  int iVersion;
  void *pArg;
  int (*xInit)(void *);
  void (*xShutdown)(void *);
  sqlite3_pcache *(*xCreate)(int szPage, int szExtra, int bPurgeable);
  void (*xCachesize)(sqlite3_pcache *, int nCachesize);
  int (*xPagecount)(sqlite3_pcache *);
  sqlite3_pcache_page *(*xFetch)(sqlite3_pcache *, unsigned key,
                                 int createFlag);
  void (*xUnpin)(sqlite3_pcache *, sqlite3_pcache_page *, int discard);
  void (*xRekey)(sqlite3_pcache *, sqlite3_pcache_page *, unsigned oldKey,
                 unsigned newKey);
  void (*xTruncate)(sqlite3_pcache *, unsigned iLimit);
  void (*xDestroy)(sqlite3_pcache *);
  void (*xShrink)(sqlite3_pcache *);
};
typedef struct sqlite3_pcache_methods sqlite3_pcache_methods;
struct sqlite3_pcache_methods {
  void *pArg;
  int (*xInit)(void *);
  void (*xShutdown)(void *);
  sqlite3_pcache *(*xCreate)(int szPage, int bPurgeable);
  void (*xCachesize)(sqlite3_pcache *, int nCachesize);
  int (*xPagecount)(sqlite3_pcache *);
  void *(*xFetch)(sqlite3_pcache *, unsigned key, int createFlag);
  void (*xUnpin)(sqlite3_pcache *, void *, int discard);
  void (*xRekey)(sqlite3_pcache *, void *, unsigned oldKey, unsigned newKey);
  void (*xTruncate)(sqlite3_pcache *, unsigned iLimit);
  void (*xDestroy)(sqlite3_pcache *);
};
typedef struct sqlite3_backup sqlite3_backup;
sqlite3_backup *sqlite3_backup_init(sqlite3 *pDest, const char *zDestName,
                                    sqlite3 *pSource, const char *zSourceName);
int sqlite3_backup_step(sqlite3_backup *p, int nPage);
int sqlite3_backup_finish(sqlite3_backup *p);
int sqlite3_backup_remaining(sqlite3_backup *p);
int sqlite3_backup_pagecount(sqlite3_backup *p);
int sqlite3_unlock_notify(sqlite3 *pBlocked,
                          void (*xNotify)(void **apArg, int nArg),
                          void *pNotifyArg);
int sqlite3_stricmp(const char *, const char *);
int sqlite3_strnicmp(const char *, const char *, int);
int sqlite3_strglob(const char *zGlob, const char *zStr);
int sqlite3_strlike(const char *zGlob, const char *zStr, unsigned int cEsc);
void sqlite3_log(int iErrCode, const char *zFormat, ...);
void *sqlite3_wal_hook(sqlite3 *, int (*)(void *, sqlite3 *, const char *, int),
                       void *);
int sqlite3_wal_autocheckpoint(sqlite3 *db, int N);
int sqlite3_wal_checkpoint(sqlite3 *db, const char *zDb);
int sqlite3_wal_checkpoint_v2(sqlite3 *db, const char *zDb, int eMode,
                              int *pnLog, int *pnCkpt);
int sqlite3_vtab_config(sqlite3 *, int op, ...);
int sqlite3_vtab_on_conflict(sqlite3 *);
int sqlite3_vtab_nochange(sqlite3_context *);
const char *sqlite3_vtab_collation(sqlite3_index_info *, int);
int sqlite3_vtab_distinct(sqlite3_index_info *);
int sqlite3_vtab_in(sqlite3_index_info *, int iCons, int bHandle);
int sqlite3_vtab_in_first(sqlite3_value *pVal, sqlite3_value **ppOut);
int sqlite3_vtab_in_next(sqlite3_value *pVal, sqlite3_value **ppOut);
int sqlite3_vtab_rhs_value(sqlite3_index_info *, int, sqlite3_value **ppVal);
int sqlite3_stmt_scanstatus(sqlite3_stmt *pStmt, int idx, int iScanStatusOp,
                            void *pOut);
int sqlite3_stmt_scanstatus_v2(sqlite3_stmt *pStmt, int idx, int iScanStatusOp,
                               int flags, void *pOut);
void sqlite3_stmt_scanstatus_reset(sqlite3_stmt *);
int sqlite3_db_cacheflush(sqlite3 *);
int sqlite3_system_errno(sqlite3 *);
typedef struct sqlite3_snapshot {
  unsigned char hidden[48];
} sqlite3_snapshot;
int sqlite3_snapshot_get(sqlite3 *db, const char *zSchema,
                         sqlite3_snapshot **ppSnapshot);
int sqlite3_snapshot_open(sqlite3 *db, const char *zSchema,
                          sqlite3_snapshot *pSnapshot);
void sqlite3_snapshot_free(sqlite3_snapshot *);
int sqlite3_snapshot_cmp(sqlite3_snapshot *p1, sqlite3_snapshot *p2);
int sqlite3_snapshot_recover(sqlite3 *db, const char *zDb);
unsigned char *sqlite3_serialize(sqlite3 *db, const char *zSchema,
                                 sqlite3_int64 *piSize, unsigned int mFlags);
int sqlite3_deserialize(sqlite3 *db, const char *zSchema, unsigned char *pData,
                        sqlite3_int64 szDb, sqlite3_int64 szBuf,
                        unsigned mFlags);
typedef struct sqlite3_rtree_geometry sqlite3_rtree_geometry;
typedef struct sqlite3_rtree_query_info sqlite3_rtree_query_info;
typedef double sqlite3_rtree_dbl;
int sqlite3_rtree_geometry_callback(sqlite3 *db, const char *zGeom,
                                    int (*xGeom)(sqlite3_rtree_geometry *, int,
                                                 sqlite3_rtree_dbl *, int *),
                                    void *pContext);
struct sqlite3_rtree_geometry {
  void *pContext;
  int nParam;
  sqlite3_rtree_dbl *aParam;
  void *pUser;
  void (*xDelUser)(void *);
};
int sqlite3_rtree_query_callback(sqlite3 *db, const char *zQueryFunc,
                                 int (*xQueryFunc)(sqlite3_rtree_query_info *),
                                 void *pContext, void (*xDestructor)(void *));
struct sqlite3_rtree_query_info {
  void *pContext;
  int nParam;
  sqlite3_rtree_dbl *aParam;
  void *pUser;
  void (*xDelUser)(void *);
  sqlite3_rtree_dbl *aCoord;
  unsigned int *anQueue;
  int nCoord;
  int iLevel;
  int mxLevel;
  sqlite3_int64 iRowid;
  sqlite3_rtree_dbl rParentScore;
  int eParentWithin;
  int eWithin;
  sqlite3_rtree_dbl rScore;
  sqlite3_value **apSqlParam;
};
typedef struct Fts5ExtensionApi Fts5ExtensionApi;
typedef struct Fts5Context Fts5Context;
typedef struct Fts5PhraseIter Fts5PhraseIter;
typedef void (*fts5_extension_function)(const Fts5ExtensionApi *pApi,
                                        Fts5Context *pFts,
                                        sqlite3_context *pCtx, int nVal,
                                        sqlite3_value **apVal);
struct Fts5PhraseIter {
  const unsigned char *a;
  const unsigned char *b;
};
struct Fts5ExtensionApi {
  int iVersion;
  void *(*xUserData)(Fts5Context *);
  int (*xColumnCount)(Fts5Context *);
  int (*xRowCount)(Fts5Context *, sqlite3_int64 *pnRow);
  int (*xColumnTotalSize)(Fts5Context *, int iCol, sqlite3_int64 *pnToken);
  int (*xTokenize)(Fts5Context *, const char *pText, int nText, void *pCtx,
                   int (*xToken)(void *, int, const char *, int, int, int));
  int (*xPhraseCount)(Fts5Context *);
  int (*xPhraseSize)(Fts5Context *, int iPhrase);
  int (*xInstCount)(Fts5Context *, int *pnInst);
  int (*xInst)(Fts5Context *, int iIdx, int *piPhrase, int *piCol, int *piOff);
  sqlite3_int64 (*xRowid)(Fts5Context *);
  int (*xColumnText)(Fts5Context *, int iCol, const char **pz, int *pn);
  int (*xColumnSize)(Fts5Context *, int iCol, int *pnToken);
  int (*xQueryPhrase)(Fts5Context *, int iPhrase, void *pUserData,
                      int (*)(const Fts5ExtensionApi *, Fts5Context *, void *));
  int (*xSetAuxdata)(Fts5Context *, void *pAux, void (*xDelete)(void *));
  void *(*xGetAuxdata)(Fts5Context *, int bClear);
  int (*xPhraseFirst)(Fts5Context *, int iPhrase, Fts5PhraseIter *, int *,
                      int *);
  void (*xPhraseNext)(Fts5Context *, Fts5PhraseIter *, int *piCol, int *piOff);
  int (*xPhraseFirstColumn)(Fts5Context *, int iPhrase, Fts5PhraseIter *,
                            int *);
  void (*xPhraseNextColumn)(Fts5Context *, Fts5PhraseIter *, int *piCol);
};
typedef struct Fts5Tokenizer Fts5Tokenizer;
typedef struct fts5_tokenizer fts5_tokenizer;
struct fts5_tokenizer {
  int (*xCreate)(void *, const char **azArg, int nArg, Fts5Tokenizer **ppOut);
  void (*xDelete)(Fts5Tokenizer *);
  int (*xTokenize)(Fts5Tokenizer *, void *pCtx, int flags, const char *pText,
                   int nText,
                   int (*xToken)(void *pCtx, int tflags, const char *pToken,
                                 int nToken, int iStart, int iEnd));
};
typedef struct fts5_api fts5_api;
struct fts5_api {
  int iVersion;
  int (*xCreateTokenizer)(fts5_api *pApi, const char *zName, void *pContext,
                          fts5_tokenizer *pTokenizer, void (*xDestroy)(void *));
  int (*xFindTokenizer)(fts5_api *pApi, const char *zName, void **ppContext,
                        fts5_tokenizer *pTokenizer);
  int (*xCreateFunction)(fts5_api *pApi, const char *zName, void *pContext,
                         fts5_extension_function xFunction,
                         void (*xDestroy)(void *));
};
typedef sqlite3_int64 i64;
typedef sqlite3_uint64 u64;
typedef unsigned char u8;
enum {
  _ISupper = ((0) < 8 ? ((1 << (0)) << 8) : ((1 << (0)) >> 8)),
  _ISlower = ((1) < 8 ? ((1 << (1)) << 8) : ((1 << (1)) >> 8)),
  _ISalpha = ((2) < 8 ? ((1 << (2)) << 8) : ((1 << (2)) >> 8)),
  _ISdigit = ((3) < 8 ? ((1 << (3)) << 8) : ((1 << (3)) >> 8)),
  _ISxdigit = ((4) < 8 ? ((1 << (4)) << 8) : ((1 << (4)) >> 8)),
  _ISspace = ((5) < 8 ? ((1 << (5)) << 8) : ((1 << (5)) >> 8)),
  _ISprint = ((6) < 8 ? ((1 << (6)) << 8) : ((1 << (6)) >> 8)),
  _ISgraph = ((7) < 8 ? ((1 << (7)) << 8) : ((1 << (7)) >> 8)),
  _ISblank = ((8) < 8 ? ((1 << (8)) << 8) : ((1 << (8)) >> 8)),
  _IScntrl = ((9) < 8 ? ((1 << (9)) << 8) : ((1 << (9)) >> 8)),
  _ISpunct = ((10) < 8 ? ((1 << (10)) << 8) : ((1 << (10)) >> 8)),
  _ISalnum = ((11) < 8 ? ((1 << (11)) << 8) : ((1 << (11)) >> 8))
};
extern const unsigned short int **__ctype_b_loc(void);
extern const __int32_t **__ctype_tolower_loc(void);
extern const __int32_t **__ctype_toupper_loc(void);
extern int isalnum(int);
extern int isalpha(int);
extern int iscntrl(int);
extern int isdigit(int);
extern int islower(int);
extern int isgraph(int);
extern int isprint(int);
extern int ispunct(int);
extern int isspace(int);
extern int isupper(int);
extern int isxdigit(int);
extern int tolower(int __c);
extern int toupper(int __c);
extern int isblank(int);
extern int isascii(int __c);
extern int toascii(int __c);
extern int _toupper(int);
extern int _tolower(int);
extern int isalnum_l(int, locale_t);
extern int isalpha_l(int, locale_t);
extern int iscntrl_l(int, locale_t);
extern int isdigit_l(int, locale_t);
extern int islower_l(int, locale_t);
extern int isgraph_l(int, locale_t);
extern int isprint_l(int, locale_t);
extern int ispunct_l(int, locale_t);
extern int isspace_l(int, locale_t);
extern int isupper_l(int, locale_t);
extern int isxdigit_l(int, locale_t);
extern int isblank_l(int, locale_t);
extern int __tolower_l(int __c, locale_t __l);
extern int tolower_l(int __c, locale_t __l);
extern int __toupper_l(int __c, locale_t __l);
extern int toupper_l(int __c, locale_t __l);
typedef __sig_atomic_t sig_atomic_t;
union sigval {
  int sival_int;
  void *sival_ptr;
};
typedef union sigval __sigval_t;
typedef struct {
  int si_signo;
  int si_errno;
  int si_code;
  int __pad0;
  union {
    int _pad[((128 / sizeof(int)) - 4)];
    struct {
      __pid_t si_pid;
      __uid_t si_uid;
    } _kill;
    struct {
      int si_tid;
      int si_overrun;
      __sigval_t si_sigval;
    } _timer;
    struct {
      __pid_t si_pid;
      __uid_t si_uid;
      __sigval_t si_sigval;
    } _rt;
    struct {
      __pid_t si_pid;
      __uid_t si_uid;
      int si_status;
      __clock_t si_utime;
      __clock_t si_stime;
    } _sigchld;
    struct {
      void *si_addr;
      short int si_addr_lsb;
      union {
        struct {
          void *_lower;
          void *_upper;
        } _addr_bnd;
        __uint32_t _pkey;
      } _bounds;
    } _sigfault;
    struct {
      long int si_band;
      int si_fd;
    } _sigpoll;
    struct {
      void *_call_addr;
      int _syscall;
      unsigned int _arch;
    } _sigsys;
  } _sifields;
} siginfo_t;
enum {
  SI_ASYNCNL = -60,
  SI_DETHREAD = -7,
  SI_TKILL,
  SI_SIGIO,
  SI_ASYNCIO,
  SI_MESGQ,
  SI_TIMER,
  SI_QUEUE,
  SI_USER,
  SI_KERNEL = 128
};
enum {
  ILL_ILLOPC = 1,
  ILL_ILLOPN,
  ILL_ILLADR,
  ILL_ILLTRP,
  ILL_PRVOPC,
  ILL_PRVREG,
  ILL_COPROC,
  ILL_BADSTK,
  ILL_BADIADDR
};
enum {
  FPE_INTDIV = 1,
  FPE_INTOVF,
  FPE_FLTDIV,
  FPE_FLTOVF,
  FPE_FLTUND,
  FPE_FLTRES,
  FPE_FLTINV,
  FPE_FLTSUB,
  FPE_FLTUNK = 14,
  FPE_CONDTRAP
};
enum {
  SEGV_MAPERR = 1,
  SEGV_ACCERR,
  SEGV_BNDERR,
  SEGV_PKUERR,
  SEGV_ACCADI,
  SEGV_ADIDERR,
  SEGV_ADIPERR,
  SEGV_MTEAERR,
  SEGV_MTESERR
};
enum { BUS_ADRALN = 1, BUS_ADRERR, BUS_OBJERR, BUS_MCEERR_AR, BUS_MCEERR_AO };
enum {
  CLD_EXITED = 1,
  CLD_KILLED,
  CLD_DUMPED,
  CLD_TRAPPED,
  CLD_STOPPED,
  CLD_CONTINUED
};
enum { POLL_IN = 1, POLL_OUT, POLL_MSG, POLL_ERR, POLL_PRI, POLL_HUP };
typedef __sigval_t sigval_t;
typedef struct sigevent {
  __sigval_t sigev_value;
  int sigev_signo;
  int sigev_notify;
  union {
    int _pad[((64 / sizeof(int)) - 4)];
    __pid_t _tid;
    struct {
      void (*_function)(__sigval_t);
      pthread_attr_t *_attribute;
    } _sigev_thread;
  } _sigev_un;
} sigevent_t;
enum { SIGEV_SIGNAL = 0, SIGEV_NONE, SIGEV_THREAD, SIGEV_THREAD_ID = 4 };
typedef void (*__sighandler_t)(int);
extern __sighandler_t __sysv_signal(int __sig, __sighandler_t __handler);
extern __sighandler_t signal(int __sig, __sighandler_t __handler);
extern int kill(__pid_t __pid, int __sig);
extern int killpg(__pid_t __pgrp, int __sig);
extern int raise(int __sig);
extern __sighandler_t ssignal(int __sig, __sighandler_t __handler);
extern int gsignal(int __sig);
extern void psignal(int __sig, const char *__s);
extern void psiginfo(const siginfo_t *__pinfo, const char *__s);
extern int sigblock(int __mask);
extern int sigsetmask(int __mask);
extern int siggetmask(void);
typedef __sighandler_t sig_t;
extern int sigemptyset(sigset_t *__set);
extern int sigfillset(sigset_t *__set);
extern int sigaddset(sigset_t *__set, int __signo);
extern int sigdelset(sigset_t *__set, int __signo);
extern int sigismember(const sigset_t *__set, int __signo);
struct sigaction {
  union {
    __sighandler_t sa_handler;
    void (*sa_sigaction)(int, siginfo_t *, void *);
  } __sigaction_handler;
  __sigset_t sa_mask;
  int sa_flags;
  void (*sa_restorer)(void);
};
extern int sigprocmask(int __how, const sigset_t *__set, sigset_t *__oset);
extern int sigsuspend(const sigset_t *__set);
extern int sigaction(int __sig, const struct sigaction *__act,
                     struct sigaction *__oact);
extern int sigpending(sigset_t *__set);
extern int sigwait(const sigset_t *__set, int *__sig);
extern int sigwaitinfo(const sigset_t *__set, siginfo_t *__info);
extern int sigtimedwait(const sigset_t *__set, siginfo_t *__info,
                        const struct timespec *__timeout);
extern int sigqueue(__pid_t __pid, int __sig, const union sigval __val);
struct _fpx_sw_bytes {
  __uint32_t magic1;
  __uint32_t extended_size;
  __uint64_t xstate_bv;
  __uint32_t xstate_size;
  __uint32_t __glibc_reserved1[7];
};
struct _fpreg {
  unsigned short significand[4];
  unsigned short exponent;
};
struct _fpxreg {
  unsigned short significand[4];
  unsigned short exponent;
  unsigned short __glibc_reserved1[3];
};
struct _xmmreg {
  __uint32_t element[4];
};
struct _fpstate {
  __uint16_t cwd;
  __uint16_t swd;
  __uint16_t ftw;
  __uint16_t fop;
  __uint64_t rip;
  __uint64_t rdp;
  __uint32_t mxcsr;
  __uint32_t mxcr_mask;
  struct _fpxreg _st[8];
  struct _xmmreg _xmm[16];
  __uint32_t __glibc_reserved1[24];
};
struct sigcontext {
  __uint64_t r8;
  __uint64_t r9;
  __uint64_t r10;
  __uint64_t r11;
  __uint64_t r12;
  __uint64_t r13;
  __uint64_t r14;
  __uint64_t r15;
  __uint64_t rdi;
  __uint64_t rsi;
  __uint64_t rbp;
  __uint64_t rbx;
  __uint64_t rdx;
  __uint64_t rax;
  __uint64_t rcx;
  __uint64_t rsp;
  __uint64_t rip;
  __uint64_t eflags;
  unsigned short cs;
  unsigned short gs;
  unsigned short fs;
  unsigned short __pad0;
  __uint64_t err;
  __uint64_t trapno;
  __uint64_t oldmask;
  __uint64_t cr2;
  union {
    struct _fpstate *fpstate;
    __uint64_t __fpstate_word;
  };
  __uint64_t __reserved1[8];
};
struct _xsave_hdr {
  __uint64_t xstate_bv;
  __uint64_t __glibc_reserved1[2];
  __uint64_t __glibc_reserved2[5];
};
struct _ymmh_state {
  __uint32_t ymmh_space[64];
};
struct _xstate {
  struct _fpstate fpstate;
  struct _xsave_hdr xstate_hdr;
  struct _ymmh_state ymmh;
};
extern int sigreturn(struct sigcontext *__scp);
typedef struct {
  void *ss_sp;
  int ss_flags;
  size_t ss_size;
} stack_t;
typedef long long int greg_t;
typedef greg_t gregset_t[23];
struct _libc_fpxreg {
  unsigned short int significand[4];
  unsigned short int exponent;
  unsigned short int __glibc_reserved1[3];
};
struct _libc_xmmreg {
  __uint32_t element[4];
};
struct _libc_fpstate {
  __uint16_t cwd;
  __uint16_t swd;
  __uint16_t ftw;
  __uint16_t fop;
  __uint64_t rip;
  __uint64_t rdp;
  __uint32_t mxcsr;
  __uint32_t mxcr_mask;
  struct _libc_fpxreg _st[8];
  struct _libc_xmmreg _xmm[16];
  __uint32_t __glibc_reserved1[24];
};
typedef struct _libc_fpstate *fpregset_t;
typedef struct {
  gregset_t gregs;
  fpregset_t fpregs;
  unsigned long long __reserved1[8];
} mcontext_t;
typedef struct ucontext_t {
  unsigned long int uc_flags;
  struct ucontext_t *uc_link;
  stack_t uc_stack;
  mcontext_t uc_mcontext;
  sigset_t uc_sigmask;
  struct _libc_fpstate __fpregs_mem;
  unsigned long long int __ssp[4];
} ucontext_t;
extern int siginterrupt(int __sig, int __interrupt);
enum { SS_ONSTACK = 1, SS_DISABLE };
extern int sigaltstack(const stack_t *__ss, stack_t *__oss);
struct sigstack {
  void *ss_sp;
  int ss_onstack;
};
extern int sigstack(struct sigstack *__ss, struct sigstack *__oss);
extern int pthread_sigmask(int __how, const __sigset_t *__newmask,
                           __sigset_t *__oldmask);
extern int pthread_kill(pthread_t __threadid, int __signo);
extern int __libc_current_sigrtmin(void);
extern int __libc_current_sigrtmax(void);
struct passwd {
  char *pw_name;
  char *pw_passwd;
  __uid_t pw_uid;
  __gid_t pw_gid;
  char *pw_gecos;
  char *pw_dir;
  char *pw_shell;
};
extern void setpwent(void);
extern void endpwent(void);
extern struct passwd *getpwent(void);
extern struct passwd *fgetpwent(FILE *__stream);
extern int putpwent(const struct passwd *__p, FILE *__f);
extern struct passwd *getpwuid(__uid_t __uid);
extern struct passwd *getpwnam(const char *__name);
extern int getpwent_r(struct passwd *__resultbuf, char *__buffer,
                      size_t __buflen, struct passwd **__result);
extern int getpwuid_r(__uid_t __uid, struct passwd *__resultbuf, char *__buffer,
                      size_t __buflen, struct passwd **__result);
extern int getpwnam_r(const char *__name, struct passwd *__resultbuf,
                      char *__buffer, size_t __buflen,
                      struct passwd **__result);
extern int fgetpwent_r(FILE *__stream, struct passwd *__resultbuf,
                       char *__buffer, size_t __buflen,
                       struct passwd **__result);
typedef __useconds_t useconds_t;
typedef __intptr_t intptr_t;
typedef __socklen_t socklen_t;
extern int access(const char *__name, int __type);
extern int faccessat(int __fd, const char *__file, int __type, int __flag);
extern __off_t lseek(int __fd, __off_t __offset, int __whence);
extern int close(int __fd);
extern void closefrom(int __lowfd);
extern ssize_t read(int __fd, void *__buf, size_t __nbytes);
extern ssize_t write(int __fd, const void *__buf, size_t __n);
extern ssize_t pread(int __fd, void *__buf, size_t __nbytes, __off_t __offset);
extern ssize_t pwrite(int __fd, const void *__buf, size_t __n,
                      __off_t __offset);
extern int pipe(int __pipedes[2]);
extern unsigned int alarm(unsigned int __seconds);
extern unsigned int sleep(unsigned int __seconds);
extern __useconds_t ualarm(__useconds_t __value, __useconds_t __interval);
extern int usleep(__useconds_t __useconds);
extern int pause(void);
extern int chown(const char *__file, __uid_t __owner, __gid_t __group);
extern int fchown(int __fd, __uid_t __owner, __gid_t __group);
extern int lchown(const char *__file, __uid_t __owner, __gid_t __group);
extern int fchownat(int __fd, const char *__file, __uid_t __owner,
                    __gid_t __group, int __flag);
extern int chdir(const char *__path);
extern int fchdir(int __fd);
extern char *getcwd(char *__buf, size_t __size);
extern char *getwd(char *__buf);
extern int dup(int __fd);
extern int dup2(int __fd, int __fd2);
extern char **__environ;
extern int execve(const char *__path, char *const __argv[],
                  char *const __envp[]);
extern int fexecve(int __fd, char *const __argv[], char *const __envp[]);
extern int execv(const char *__path, char *const __argv[]);
extern int execle(const char *__path, const char *__arg, ...);
extern int execl(const char *__path, const char *__arg, ...);
extern int execvp(const char *__file, char *const __argv[]);
extern int execlp(const char *__file, const char *__arg, ...);
extern int nice(int __inc);
extern void _exit(int __status);
enum {
  _PC_LINK_MAX,
  _PC_MAX_CANON,
  _PC_MAX_INPUT,
  _PC_NAME_MAX,
  _PC_PATH_MAX,
  _PC_PIPE_BUF,
  _PC_CHOWN_RESTRICTED,
  _PC_NO_TRUNC,
  _PC_VDISABLE,
  _PC_SYNC_IO,
  _PC_ASYNC_IO,
  _PC_PRIO_IO,
  _PC_SOCK_MAXBUF,
  _PC_FILESIZEBITS,
  _PC_REC_INCR_XFER_SIZE,
  _PC_REC_MAX_XFER_SIZE,
  _PC_REC_MIN_XFER_SIZE,
  _PC_REC_XFER_ALIGN,
  _PC_ALLOC_SIZE_MIN,
  _PC_SYMLINK_MAX,
  _PC_2_SYMLINKS
};
enum {
  _SC_ARG_MAX,
  _SC_CHILD_MAX,
  _SC_CLK_TCK,
  _SC_NGROUPS_MAX,
  _SC_OPEN_MAX,
  _SC_STREAM_MAX,
  _SC_TZNAME_MAX,
  _SC_JOB_CONTROL,
  _SC_SAVED_IDS,
  _SC_REALTIME_SIGNALS,
  _SC_PRIORITY_SCHEDULING,
  _SC_TIMERS,
  _SC_ASYNCHRONOUS_IO,
  _SC_PRIORITIZED_IO,
  _SC_SYNCHRONIZED_IO,
  _SC_FSYNC,
  _SC_MAPPED_FILES,
  _SC_MEMLOCK,
  _SC_MEMLOCK_RANGE,
  _SC_MEMORY_PROTECTION,
  _SC_MESSAGE_PASSING,
  _SC_SEMAPHORES,
  _SC_SHARED_MEMORY_OBJECTS,
  _SC_AIO_LISTIO_MAX,
  _SC_AIO_MAX,
  _SC_AIO_PRIO_DELTA_MAX,
  _SC_DELAYTIMER_MAX,
  _SC_MQ_OPEN_MAX,
  _SC_MQ_PRIO_MAX,
  _SC_VERSION,
  _SC_PAGESIZE,
  _SC_RTSIG_MAX,
  _SC_SEM_NSEMS_MAX,
  _SC_SEM_VALUE_MAX,
  _SC_SIGQUEUE_MAX,
  _SC_TIMER_MAX,
  _SC_BC_BASE_MAX,
  _SC_BC_DIM_MAX,
  _SC_BC_SCALE_MAX,
  _SC_BC_STRING_MAX,
  _SC_COLL_WEIGHTS_MAX,
  _SC_EQUIV_CLASS_MAX,
  _SC_EXPR_NEST_MAX,
  _SC_LINE_MAX,
  _SC_RE_DUP_MAX,
  _SC_CHARCLASS_NAME_MAX,
  _SC_2_VERSION,
  _SC_2_C_BIND,
  _SC_2_C_DEV,
  _SC_2_FORT_DEV,
  _SC_2_FORT_RUN,
  _SC_2_SW_DEV,
  _SC_2_LOCALEDEF,
  _SC_PII,
  _SC_PII_XTI,
  _SC_PII_SOCKET,
  _SC_PII_INTERNET,
  _SC_PII_OSI,
  _SC_POLL,
  _SC_SELECT,
  _SC_UIO_MAXIOV,
  _SC_IOV_MAX = _SC_UIO_MAXIOV,
  _SC_PII_INTERNET_STREAM,
  _SC_PII_INTERNET_DGRAM,
  _SC_PII_OSI_COTS,
  _SC_PII_OSI_CLTS,
  _SC_PII_OSI_M,
  _SC_T_IOV_MAX,
  _SC_THREADS,
  _SC_THREAD_SAFE_FUNCTIONS,
  _SC_GETGR_R_SIZE_MAX,
  _SC_GETPW_R_SIZE_MAX,
  _SC_LOGIN_NAME_MAX,
  _SC_TTY_NAME_MAX,
  _SC_THREAD_DESTRUCTOR_ITERATIONS,
  _SC_THREAD_KEYS_MAX,
  _SC_THREAD_STACK_MIN,
  _SC_THREAD_THREADS_MAX,
  _SC_THREAD_ATTR_STACKADDR,
  _SC_THREAD_ATTR_STACKSIZE,
  _SC_THREAD_PRIORITY_SCHEDULING,
  _SC_THREAD_PRIO_INHERIT,
  _SC_THREAD_PRIO_PROTECT,
  _SC_THREAD_PROCESS_SHARED,
  _SC_NPROCESSORS_CONF,
  _SC_NPROCESSORS_ONLN,
  _SC_PHYS_PAGES,
  _SC_AVPHYS_PAGES,
  _SC_ATEXIT_MAX,
  _SC_PASS_MAX,
  _SC_XOPEN_VERSION,
  _SC_XOPEN_XCU_VERSION,
  _SC_XOPEN_UNIX,
  _SC_XOPEN_CRYPT,
  _SC_XOPEN_ENH_I18N,
  _SC_XOPEN_SHM,
  _SC_2_CHAR_TERM,
  _SC_2_C_VERSION,
  _SC_2_UPE,
  _SC_XOPEN_XPG2,
  _SC_XOPEN_XPG3,
  _SC_XOPEN_XPG4,
  _SC_CHAR_BIT,
  _SC_CHAR_MAX,
  _SC_CHAR_MIN,
  _SC_INT_MAX,
  _SC_INT_MIN,
  _SC_LONG_BIT,
  _SC_WORD_BIT,
  _SC_MB_LEN_MAX,
  _SC_NZERO,
  _SC_SSIZE_MAX,
  _SC_SCHAR_MAX,
  _SC_SCHAR_MIN,
  _SC_SHRT_MAX,
  _SC_SHRT_MIN,
  _SC_UCHAR_MAX,
  _SC_UINT_MAX,
  _SC_ULONG_MAX,
  _SC_USHRT_MAX,
  _SC_NL_ARGMAX,
  _SC_NL_LANGMAX,
  _SC_NL_MSGMAX,
  _SC_NL_NMAX,
  _SC_NL_SETMAX,
  _SC_NL_TEXTMAX,
  _SC_XBS5_ILP32_OFF32,
  _SC_XBS5_ILP32_OFFBIG,
  _SC_XBS5_LP64_OFF64,
  _SC_XBS5_LPBIG_OFFBIG,
  _SC_XOPEN_LEGACY,
  _SC_XOPEN_REALTIME,
  _SC_XOPEN_REALTIME_THREADS,
  _SC_ADVISORY_INFO,
  _SC_BARRIERS,
  _SC_BASE,
  _SC_C_LANG_SUPPORT,
  _SC_C_LANG_SUPPORT_R,
  _SC_CLOCK_SELECTION,
  _SC_CPUTIME,
  _SC_THREAD_CPUTIME,
  _SC_DEVICE_IO,
  _SC_DEVICE_SPECIFIC,
  _SC_DEVICE_SPECIFIC_R,
  _SC_FD_MGMT,
  _SC_FIFO,
  _SC_PIPE,
  _SC_FILE_ATTRIBUTES,
  _SC_FILE_LOCKING,
  _SC_FILE_SYSTEM,
  _SC_MONOTONIC_CLOCK,
  _SC_MULTI_PROCESS,
  _SC_SINGLE_PROCESS,
  _SC_NETWORKING,
  _SC_READER_WRITER_LOCKS,
  _SC_SPIN_LOCKS,
  _SC_REGEXP,
  _SC_REGEX_VERSION,
  _SC_SHELL,
  _SC_SIGNALS,
  _SC_SPAWN,
  _SC_SPORADIC_SERVER,
  _SC_THREAD_SPORADIC_SERVER,
  _SC_SYSTEM_DATABASE,
  _SC_SYSTEM_DATABASE_R,
  _SC_TIMEOUTS,
  _SC_TYPED_MEMORY_OBJECTS,
  _SC_USER_GROUPS,
  _SC_USER_GROUPS_R,
  _SC_2_PBS,
  _SC_2_PBS_ACCOUNTING,
  _SC_2_PBS_LOCATE,
  _SC_2_PBS_MESSAGE,
  _SC_2_PBS_TRACK,
  _SC_SYMLOOP_MAX,
  _SC_STREAMS,
  _SC_2_PBS_CHECKPOINT,
  _SC_V6_ILP32_OFF32,
  _SC_V6_ILP32_OFFBIG,
  _SC_V6_LP64_OFF64,
  _SC_V6_LPBIG_OFFBIG,
  _SC_HOST_NAME_MAX,
  _SC_TRACE,
  _SC_TRACE_EVENT_FILTER,
  _SC_TRACE_INHERIT,
  _SC_TRACE_LOG,
  _SC_LEVEL1_ICACHE_SIZE,
  _SC_LEVEL1_ICACHE_ASSOC,
  _SC_LEVEL1_ICACHE_LINESIZE,
  _SC_LEVEL1_DCACHE_SIZE,
  _SC_LEVEL1_DCACHE_ASSOC,
  _SC_LEVEL1_DCACHE_LINESIZE,
  _SC_LEVEL2_CACHE_SIZE,
  _SC_LEVEL2_CACHE_ASSOC,
  _SC_LEVEL2_CACHE_LINESIZE,
  _SC_LEVEL3_CACHE_SIZE,
  _SC_LEVEL3_CACHE_ASSOC,
  _SC_LEVEL3_CACHE_LINESIZE,
  _SC_LEVEL4_CACHE_SIZE,
  _SC_LEVEL4_CACHE_ASSOC,
  _SC_LEVEL4_CACHE_LINESIZE,
  _SC_IPV6 = _SC_LEVEL1_ICACHE_SIZE + 50,
  _SC_RAW_SOCKETS,
  _SC_V7_ILP32_OFF32,
  _SC_V7_ILP32_OFFBIG,
  _SC_V7_LP64_OFF64,
  _SC_V7_LPBIG_OFFBIG,
  _SC_SS_REPL_MAX,
  _SC_TRACE_EVENT_NAME_MAX,
  _SC_TRACE_NAME_MAX,
  _SC_TRACE_SYS_MAX,
  _SC_TRACE_USER_EVENT_MAX,
  _SC_XOPEN_STREAMS,
  _SC_THREAD_ROBUST_PRIO_INHERIT,
  _SC_THREAD_ROBUST_PRIO_PROTECT,
  _SC_MINSIGSTKSZ,
  _SC_SIGSTKSZ
};
enum {
  _CS_PATH,
  _CS_V6_WIDTH_RESTRICTED_ENVS,
  _CS_GNU_LIBC_VERSION,
  _CS_GNU_LIBPTHREAD_VERSION,
  _CS_V5_WIDTH_RESTRICTED_ENVS,
  _CS_V7_WIDTH_RESTRICTED_ENVS,
  _CS_LFS_CFLAGS = 1000,
  _CS_LFS_LDFLAGS,
  _CS_LFS_LIBS,
  _CS_LFS_LINTFLAGS,
  _CS_LFS64_CFLAGS,
  _CS_LFS64_LDFLAGS,
  _CS_LFS64_LIBS,
  _CS_LFS64_LINTFLAGS,
  _CS_XBS5_ILP32_OFF32_CFLAGS = 1100,
  _CS_XBS5_ILP32_OFF32_LDFLAGS,
  _CS_XBS5_ILP32_OFF32_LIBS,
  _CS_XBS5_ILP32_OFF32_LINTFLAGS,
  _CS_XBS5_ILP32_OFFBIG_CFLAGS,
  _CS_XBS5_ILP32_OFFBIG_LDFLAGS,
  _CS_XBS5_ILP32_OFFBIG_LIBS,
  _CS_XBS5_ILP32_OFFBIG_LINTFLAGS,
  _CS_XBS5_LP64_OFF64_CFLAGS,
  _CS_XBS5_LP64_OFF64_LDFLAGS,
  _CS_XBS5_LP64_OFF64_LIBS,
  _CS_XBS5_LP64_OFF64_LINTFLAGS,
  _CS_XBS5_LPBIG_OFFBIG_CFLAGS,
  _CS_XBS5_LPBIG_OFFBIG_LDFLAGS,
  _CS_XBS5_LPBIG_OFFBIG_LIBS,
  _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS,
  _CS_POSIX_V6_ILP32_OFF32_CFLAGS,
  _CS_POSIX_V6_ILP32_OFF32_LDFLAGS,
  _CS_POSIX_V6_ILP32_OFF32_LIBS,
  _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS,
  _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS,
  _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS,
  _CS_POSIX_V6_ILP32_OFFBIG_LIBS,
  _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS,
  _CS_POSIX_V6_LP64_OFF64_CFLAGS,
  _CS_POSIX_V6_LP64_OFF64_LDFLAGS,
  _CS_POSIX_V6_LP64_OFF64_LIBS,
  _CS_POSIX_V6_LP64_OFF64_LINTFLAGS,
  _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS,
  _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS,
  _CS_POSIX_V6_LPBIG_OFFBIG_LIBS,
  _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS,
  _CS_POSIX_V7_ILP32_OFF32_CFLAGS,
  _CS_POSIX_V7_ILP32_OFF32_LDFLAGS,
  _CS_POSIX_V7_ILP32_OFF32_LIBS,
  _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS,
  _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS,
  _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS,
  _CS_POSIX_V7_ILP32_OFFBIG_LIBS,
  _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS,
  _CS_POSIX_V7_LP64_OFF64_CFLAGS,
  _CS_POSIX_V7_LP64_OFF64_LDFLAGS,
  _CS_POSIX_V7_LP64_OFF64_LIBS,
  _CS_POSIX_V7_LP64_OFF64_LINTFLAGS,
  _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS,
  _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS,
  _CS_POSIX_V7_LPBIG_OFFBIG_LIBS,
  _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS,
  _CS_V6_ENV,
  _CS_V7_ENV
};
extern long int pathconf(const char *__path, int __name);
extern long int fpathconf(int __fd, int __name);
extern long int sysconf(int __name);
extern size_t confstr(int __name, char *__buf, size_t __len);
extern __pid_t getpid(void);
extern __pid_t getppid(void);
extern __pid_t getpgrp(void);
extern __pid_t __getpgid(__pid_t __pid);
extern __pid_t getpgid(__pid_t __pid);
extern int setpgid(__pid_t __pid, __pid_t __pgid);
extern int setpgrp(void);
extern __pid_t setsid(void);
extern __pid_t getsid(__pid_t __pid);
extern __uid_t getuid(void);
extern __uid_t geteuid(void);
extern __gid_t getgid(void);
extern __gid_t getegid(void);
extern int getgroups(int __size, __gid_t __list[]);
extern int setuid(__uid_t __uid);
extern int setreuid(__uid_t __ruid, __uid_t __euid);
extern int seteuid(__uid_t __uid);
extern int setgid(__gid_t __gid);
extern int setregid(__gid_t __rgid, __gid_t __egid);
extern int setegid(__gid_t __gid);
extern __pid_t fork(void);
extern __pid_t vfork(void);
extern char *ttyname(int __fd);
extern int ttyname_r(int __fd, char *__buf, size_t __buflen);
extern int isatty(int __fd);
extern int ttyslot(void);
extern int link(const char *__from, const char *__to);
extern int linkat(int __fromfd, const char *__from, int __tofd,
                  const char *__to, int __flags);
extern int symlink(const char *__from, const char *__to);
extern ssize_t readlink(const char *__path, char *__buf, size_t __len);
extern int symlinkat(const char *__from, int __tofd, const char *__to);
extern ssize_t readlinkat(int __fd, const char *__path, char *__buf,
                          size_t __len);
extern int unlink(const char *__name);
extern int unlinkat(int __fd, const char *__name, int __flag);
extern int rmdir(const char *__path);
extern __pid_t tcgetpgrp(int __fd);
extern int tcsetpgrp(int __fd, __pid_t __pgrp_id);
extern char *getlogin(void);
extern int getlogin_r(char *__name, size_t __name_len);
extern int setlogin(const char *__name);
extern char *optarg;
extern int optind;
extern int opterr;
extern int optopt;
extern int getopt(int ___argc, char *const *___argv, const char *__shortopts);
extern int gethostname(char *__name, size_t __len);
extern int sethostname(const char *__name, size_t __len);
extern int sethostid(long int __id);
extern int getdomainname(char *__name, size_t __len);
extern int setdomainname(const char *__name, size_t __len);
extern int vhangup(void);
extern int revoke(const char *__file);
extern int profil(unsigned short int *__sample_buffer, size_t __size,
                  size_t __offset, unsigned int __scale);
extern int acct(const char *__name);
extern char *getusershell(void);
extern void endusershell(void);
extern void setusershell(void);
extern int daemon(int __nochdir, int __noclose);
extern int chroot(const char *__path);
extern char *getpass(const char *__prompt);
extern int fsync(int __fd);
extern long int gethostid(void);
extern void sync(void);
extern int getpagesize(void);
extern int getdtablesize(void);
extern int truncate(const char *__file, __off_t __length);
extern int ftruncate(int __fd, __off_t __length);
extern int brk(void *__addr);
extern void *sbrk(intptr_t __delta);
extern long int syscall(long int __sysno, ...);
extern int lockf(int __fd, int __cmd, __off_t __len);
extern int fdatasync(int __fildes);
extern char *crypt(const char *__key, const char *__salt);
int getentropy(void *__buffer, size_t __length);
struct dirent {
  __ino_t d_ino;
  __off_t d_off;
  unsigned short int d_reclen;
  unsigned char d_type;
  char d_name[256];
};
enum {
  DT_UNKNOWN = 0,
  DT_FIFO = 1,
  DT_CHR = 2,
  DT_DIR = 4,
  DT_BLK = 6,
  DT_REG = 8,
  DT_LNK = 10,
  DT_SOCK = 12,
  DT_WHT = 14
};
typedef struct __dirstream DIR;
extern int closedir(DIR *__dirp);
extern DIR *opendir(const char *__name);
extern DIR *fdopendir(int __fd);
extern struct dirent *readdir(DIR *__dirp);
extern int readdir_r(DIR *__dirp, struct dirent *__entry,
                     struct dirent **__result);
extern void rewinddir(DIR *__dirp);
extern void seekdir(DIR *__dirp, long int __pos);
extern long int telldir(DIR *__dirp);
extern int dirfd(DIR *__dirp);
extern int scandir(const char *__dir, struct dirent ***__namelist,
                   int (*__selector)(const struct dirent *),
                   int (*__cmp)(const struct dirent **,
                                const struct dirent **));
extern int alphasort(const struct dirent **__e1, const struct dirent **__e2);
extern __ssize_t getdirentries(int __fd, char *__buf, size_t __nbytes,
                               __off_t *__basep);
struct stat {
  __dev_t st_dev;
  __ino_t st_ino;
  __nlink_t st_nlink;
  __mode_t st_mode;
  __uid_t st_uid;
  __gid_t st_gid;
  int __pad0;
  __dev_t st_rdev;
  __off_t st_size;
  __blksize_t st_blksize;
  __blkcnt_t st_blocks;
  struct timespec st_atim;
  struct timespec st_mtim;
  struct timespec st_ctim;
  __syscall_slong_t __glibc_reserved[3];
};
extern int stat(const char *__file, struct stat *__buf);
extern int fstat(int __fd, struct stat *__buf);
extern int fstatat(int __fd, const char *__file, struct stat *__buf,
                   int __flag);
extern int lstat(const char *__file, struct stat *__buf);
extern int chmod(const char *__file, __mode_t __mode);
extern int lchmod(const char *__file, __mode_t __mode);
extern int fchmod(int __fd, __mode_t __mode);
extern int fchmodat(int __fd, const char *__file, __mode_t __mode, int __flag);
extern __mode_t umask(__mode_t __mask);
extern int mkdir(const char *__path, __mode_t __mode);
extern int mkdirat(int __fd, const char *__path, __mode_t __mode);
extern int mknod(const char *__path, __mode_t __mode, __dev_t __dev);
extern int mknodat(int __fd, const char *__path, __mode_t __mode,
                   __dev_t __dev);
extern int mkfifo(const char *__path, __mode_t __mode);
extern int mkfifoat(int __fd, const char *__path, __mode_t __mode);
extern int utimensat(int __fd, const char *__path,
                     const struct timespec __times[2], int __flags);
extern int futimens(int __fd, const struct timespec __times[2]);
extern int isatty(int);
extern FILE *popen(const char *, const char *);
extern int pclose(FILE *);
static int enableTimer = 0;
static int cli_strcmp(const char *a, const char *b) {
  if (a == 0)
    a = "";
  if (b == 0)
    b = "";
  return strcmp(a, b);
}
static int cli_strncmp(const char *a, const char *b, size_t n) {
  if (a == 0)
    a = "";
  if (b == 0)
    b = "";
  return strncmp(a, b, n);
}
static sqlite3_int64 timeOfDay(void) {
  static sqlite3_vfs *clockVfs = 0;
  sqlite3_int64 t;
  if (clockVfs == 0)
    clockVfs = sqlite3_vfs_find(0);
  if (clockVfs == 0)
    return 0;
  if (clockVfs->iVersion >= 2 && clockVfs->xCurrentTimeInt64 != 0) {
    clockVfs->xCurrentTimeInt64(clockVfs, &t);
  } else {
    double r;
    clockVfs->xCurrentTime(clockVfs, &r);
    t = (sqlite3_int64)(r * 86400000.000000);
  }
  return t;
}
struct timezone {
  int tz_minuteswest;
  int tz_dsttime;
};
extern int gettimeofday(struct timeval *__tv, void *__tz);
extern int settimeofday(const struct timeval *__tv,
                        const struct timezone *__tz);
extern int adjtime(const struct timeval *__delta, struct timeval *__olddelta);
enum __itimer_which { ITIMER_REAL = 0, ITIMER_VIRTUAL = 1, ITIMER_PROF = 2 };
struct itimerval {
  struct timeval it_interval;
  struct timeval it_value;
};
typedef int __itimer_which_t;
extern int getitimer(__itimer_which_t __which, struct itimerval *__value);
extern int setitimer(__itimer_which_t __which, const struct itimerval *__new,
                     struct itimerval *__old);
extern int utimes(const char *__file, const struct timeval __tvp[2]);
extern int lutimes(const char *__file, const struct timeval __tvp[2]);
extern int futimes(int __fd, const struct timeval __tvp[2]);
enum __rlimit_resource {
  RLIMIT_CPU = 0,
  RLIMIT_FSIZE = 1,
  RLIMIT_DATA = 2,
  RLIMIT_STACK = 3,
  RLIMIT_CORE = 4,
  __RLIMIT_RSS = 5,
  RLIMIT_NOFILE = 7,
  __RLIMIT_OFILE = RLIMIT_NOFILE,
  RLIMIT_AS = 9,
  __RLIMIT_NPROC = 6,
  __RLIMIT_MEMLOCK = 8,
  __RLIMIT_LOCKS = 10,
  __RLIMIT_SIGPENDING = 11,
  __RLIMIT_MSGQUEUE = 12,
  __RLIMIT_NICE = 13,
  __RLIMIT_RTPRIO = 14,
  __RLIMIT_RTTIME = 15,
  __RLIMIT_NLIMITS = 16,
  __RLIM_NLIMITS = __RLIMIT_NLIMITS
};
typedef __rlim_t rlim_t;
struct rlimit {
  rlim_t rlim_cur;
  rlim_t rlim_max;
};
enum __rusage_who { RUSAGE_SELF = 0, RUSAGE_CHILDREN = -1 };
struct rusage {
  struct timeval ru_utime;
  struct timeval ru_stime;
  union {
    long int ru_maxrss;
    __syscall_slong_t __ru_maxrss_word;
  };
  union {
    long int ru_ixrss;
    __syscall_slong_t __ru_ixrss_word;
  };
  union {
    long int ru_idrss;
    __syscall_slong_t __ru_idrss_word;
  };
  union {
    long int ru_isrss;
    __syscall_slong_t __ru_isrss_word;
  };
  union {
    long int ru_minflt;
    __syscall_slong_t __ru_minflt_word;
  };
  union {
    long int ru_majflt;
    __syscall_slong_t __ru_majflt_word;
  };
  union {
    long int ru_nswap;
    __syscall_slong_t __ru_nswap_word;
  };
  union {
    long int ru_inblock;
    __syscall_slong_t __ru_inblock_word;
  };
  union {
    long int ru_oublock;
    __syscall_slong_t __ru_oublock_word;
  };
  union {
    long int ru_msgsnd;
    __syscall_slong_t __ru_msgsnd_word;
  };
  union {
    long int ru_msgrcv;
    __syscall_slong_t __ru_msgrcv_word;
  };
  union {
    long int ru_nsignals;
    __syscall_slong_t __ru_nsignals_word;
  };
  union {
    long int ru_nvcsw;
    __syscall_slong_t __ru_nvcsw_word;
  };
  union {
    long int ru_nivcsw;
    __syscall_slong_t __ru_nivcsw_word;
  };
};
enum __priority_which { PRIO_PROCESS = 0, PRIO_PGRP = 1, PRIO_USER = 2 };
typedef int __rlimit_resource_t;
typedef int __rusage_who_t;
typedef int __priority_which_t;
extern int getrlimit(__rlimit_resource_t __resource, struct rlimit *__rlimits);
extern int setrlimit(__rlimit_resource_t __resource,
                     const struct rlimit *__rlimits);
extern int getrusage(__rusage_who_t __who, struct rusage *__usage);
extern int getpriority(__priority_which_t __which, id_t __who);
extern int setpriority(__priority_which_t __which, id_t __who, int __prio);
static struct rusage sBegin;
static sqlite3_int64 iBegin;
static void beginTimer(void) {
  if (enableTimer) {
    getrusage(RUSAGE_SELF, &sBegin);
    iBegin = timeOfDay();
  }
}
static double timeDiff(struct timeval *pStart, struct timeval *pEnd) {
  return (pEnd->tv_usec - pStart->tv_usec) * 0.000001 +
         (double)(pEnd->tv_sec - pStart->tv_sec);
}
static void endTimer(void) {
  if (enableTimer) {
    sqlite3_int64 iEnd = timeOfDay();
    struct rusage sEnd;
    getrusage(RUSAGE_SELF, &sEnd);
    printf("Run Time: real %.3f user %f sys %f\n", (iEnd - iBegin) * 0.001000,
           timeDiff(&sBegin.ru_utime, &sEnd.ru_utime),
           timeDiff(&sBegin.ru_stime, &sEnd.ru_stime));
  }
}
static int bail_on_error = 0;
static int stdin_is_interactive = 1;
static int stdout_is_console = 1;
static sqlite3 *globalDb = 0;
static volatile int seenInterrupt = 0;
static char *Argv0;
static char mainPrompt[20];
static char continuePrompt[20];
static char *shell_strncpy(char *dest, const char *src, size_t n) {
  size_t i;
  for (i = 0; i < n - 1 && src[i] != 0; i++)
    dest[i] = src[i];
  dest[i] = 0;
  return dest;
}
typedef struct DynaPrompt *t_DynaPromptRef;
static struct DynaPrompt {
  char dynamicPrompt[20];
  char acAwait[2];
  int inParenLevel;
  char *zScannerAwaits;
} dynPrompt = {{0}, {0}, 0, 0};
static void trackParenLevel(struct DynaPrompt *p, int ni) {
  p->inParenLevel += ni;
  if (ni == 0)
    p->inParenLevel = 0;
  p->zScannerAwaits = 0;
}
static void setLexemeOpen(struct DynaPrompt *p, char *s, char c) {
  if (s != 0 || c == 0) {
    p->zScannerAwaits = s;
    p->acAwait[0] = 0;
  } else {
    p->acAwait[0] = c;
    p->zScannerAwaits = p->acAwait;
  }
}
static char *dynamicContinuePrompt(void) {
  if (continuePrompt[0] == 0 ||
      (dynPrompt.zScannerAwaits == 0 && dynPrompt.inParenLevel == 0)) {
    return continuePrompt;
  } else {
    if (dynPrompt.zScannerAwaits) {
      size_t ncp = strlen(continuePrompt);
      size_t ndp = strlen(dynPrompt.zScannerAwaits);
      if (ndp > ncp - 3)
        return continuePrompt;
      strcpy(dynPrompt.dynamicPrompt, dynPrompt.zScannerAwaits);
      while (ndp < 3)
        dynPrompt.dynamicPrompt[ndp++] = ' ';
      shell_strncpy(dynPrompt.dynamicPrompt + 3, continuePrompt + 3, 20 - 4);
    } else {
      if (dynPrompt.inParenLevel > 9) {
        shell_strncpy(dynPrompt.dynamicPrompt, "(..", 4);
      } else if (dynPrompt.inParenLevel < 0) {
        shell_strncpy(dynPrompt.dynamicPrompt, ")x!", 4);
      } else {
        shell_strncpy(dynPrompt.dynamicPrompt, "(x.", 4);
        dynPrompt.dynamicPrompt[2] = (char)('0' + dynPrompt.inParenLevel);
      }
      shell_strncpy(dynPrompt.dynamicPrompt + 3, continuePrompt + 3, 20 - 4);
    }
  }
  return dynPrompt.dynamicPrompt;
}
static void shell_out_of_memory(void) {
  fprintf(stderr, "Error: out of memory\n");
  exit(1);
}
static void shell_check_oom(const void *p) {
  if (p == 0)
    shell_out_of_memory();
}
static void utf8_width_print(FILE *pOut, int w, const char *zUtf) {
  int i;
  int n;
  int aw = w < 0 ? -w : w;
  if (zUtf == 0)
    zUtf = "";
  for (i = n = 0; zUtf[i]; i++) {
    if ((zUtf[i] & 192) != 128) {
      n++;
      if (n == aw) {
        do {
          i++;
        } while ((zUtf[i] & 192) == 128);
        break;
      }
    }
  }
  if (n >= aw) {
    fprintf(pOut, "%.*s", i, zUtf);
  } else if (w < 0) {
    fprintf(pOut, "%*s%s", aw - n, "", zUtf);
  } else {
    fprintf(pOut, "%s%*s", zUtf, aw - n, "");
  }
}
static int isNumber(const char *z, int *realnum) {
  if (*z == '-' || *z == '+')
    z++;
  if (!((*__ctype_b_loc())[(int)(((unsigned char)*z))] &
        (unsigned short int)_ISdigit)) {
    return 0;
  }
  z++;
  if (realnum)
    *realnum = 0;
  while (((*__ctype_b_loc())[(int)(((unsigned char)*z))] &
          (unsigned short int)_ISdigit)) {
    z++;
  }
  if (*z == '.') {
    z++;
    if (!((*__ctype_b_loc())[(int)(((unsigned char)*z))] &
          (unsigned short int)_ISdigit))
      return 0;
    while (((*__ctype_b_loc())[(int)(((unsigned char)*z))] &
            (unsigned short int)_ISdigit)) {
      z++;
    }
    if (realnum)
      *realnum = 1;
  }
  if (*z == 'e' || *z == 'E') {
    z++;
    if (*z == '+' || *z == '-')
      z++;
    if (!((*__ctype_b_loc())[(int)(((unsigned char)*z))] &
          (unsigned short int)_ISdigit))
      return 0;
    while (((*__ctype_b_loc())[(int)(((unsigned char)*z))] &
            (unsigned short int)_ISdigit)) {
      z++;
    }
    if (realnum)
      *realnum = 1;
  }
  return *z == 0;
}
static int strlen30(const char *z) {
  const char *z2 = z;
  while (*z2) {
    z2++;
  }
  return 1073741823 & (int)(z2 - z);
}
static int strlenChar(const char *z) {
  int n = 0;
  while (*z) {
    if ((192 & *(z++)) != 128)
      n++;
  }
  return n;
}
static FILE *openChrSource(const char *zFile) {
  struct stat x = {0};
  int rc = stat(zFile, &x);
  if (rc != 0)
    return 0;
  if ((((((x.st_mode)) & 170000) == (100000)) ||
       ((((x.st_mode)) & 170000) == (10000)) ||
       ((((x.st_mode)) & 170000) == (20000)))) {
    return fopen(zFile, "rb");
  } else {
    return 0;
  }
}
static char *local_getline(char *zLine, FILE *in) {
  int nLine = zLine == 0 ? 0 : 100;
  int n = 0;
  while (1) {
    if (n + 100 > nLine) {
      nLine = nLine * 2 + 100;
      zLine = realloc(zLine, nLine);
      shell_check_oom(zLine);
    }
    if (fgets(&zLine[n], nLine - n, in) == 0) {
      if (n == 0) {
        free(zLine);
        return 0;
      }
      zLine[n] = 0;
      break;
    }
    while (zLine[n])
      n++;
    if (n > 0 && zLine[n - 1] == '\n') {
      n--;
      if (n > 0 && zLine[n - 1] == '\x0d')
        n--;
      zLine[n] = 0;
      break;
    }
  }
  return zLine;
}
static char *one_input_line(FILE *in, char *zPrior, int isContinuation) {
  char *zPrompt;
  char *zResult;
  if (in != 0) {
    zResult = local_getline(zPrior, in);
  } else {
    zPrompt = isContinuation ? dynamicContinuePrompt() : mainPrompt;
    printf("%s", zPrompt);
    fflush(stdout);
    do {
      zResult = local_getline(zPrior, stdin);
      zPrior = 0;
      if (zResult == 0)
        sqlite3_sleep(50);
    } while (zResult == 0 && seenInterrupt > 0);
  }
  return zResult;
}
static int hexDigitValue(char c) {
  if (c >= '0' && c <= '9')
    return c - '0';
  if (c >= 'a' && c <= 'f')
    return c - 'a' + 10;
  if (c >= 'A' && c <= 'F')
    return c - 'A' + 10;
  return -1;
}
static sqlite3_int64 integerValue(const char *zArg) {
  sqlite3_int64 v = 0;
  static const struct {
    char *zSuffix;
    int iMult;
  } aMult[] = {{"KiB", 1024}, {"MiB", 1024 * 1024}, {"GiB", 1024 * 1024 * 1024},
               {"KB", 1000},  {"MB", 1000000},      {"GB", 1000000000},
               {"K", 1000},   {"M", 1000000},       {"G", 1000000000}};
  int i;
  int isNeg = 0;
  if (zArg[0] == '-') {
    isNeg = 1;
    zArg++;
  } else if (zArg[0] == '+') {
    zArg++;
  }
  if (zArg[0] == '0' && zArg[1] == 'x') {
    int x;
    zArg += 2;
    while ((x = hexDigitValue(zArg[0])) >= 0) {
      v = (v << 4) + x;
      zArg++;
    }
  } else {
    while (((*__ctype_b_loc())[(int)(((unsigned char)zArg[0]))] &
            (unsigned short int)_ISdigit)) {
      v = v * 10 + zArg[0] - '0';
      zArg++;
    }
  }
  for (i = 0; i < (int)(sizeof(aMult) / sizeof(aMult[0])); i++) {
    if (sqlite3_stricmp(aMult[i].zSuffix, zArg) == 0) {
      v *= aMult[i].iMult;
      break;
    }
  }
  return isNeg ? -v : v;
}
typedef struct ShellText ShellText;
struct ShellText {
  char *z;
  int n;
  int nAlloc;
};
static void initText(ShellText *p) { memset(p, 0, sizeof(*p)); }
static void freeText(ShellText *p) {
  free(p->z);
  initText(p);
}
static void appendText(ShellText *p, const char *zAppend, char quote) {
  i64 len;
  i64 i;
  i64 nAppend = strlen30(zAppend);
  len = nAppend + p->n + 1;
  if (quote) {
    len += 2;
    for (i = 0; i < nAppend; i++) {
      if (zAppend[i] == quote)
        len++;
    }
  }
  if (p->z == 0 || p->n + len >= p->nAlloc) {
    p->nAlloc = p->nAlloc * 2 + len + 20;
    p->z = realloc(p->z, p->nAlloc);
    shell_check_oom(p->z);
  }
  if (quote) {
    char *zCsr = p->z + p->n;
    *zCsr++ = quote;
    for (i = 0; i < nAppend; i++) {
      *zCsr++ = zAppend[i];
      if (zAppend[i] == quote)
        *zCsr++ = quote;
    }
    *zCsr++ = quote;
    p->n = (int)(zCsr - p->z);
    *zCsr = 'A';
  } else {
    memcpy(p->z + p->n, zAppend, nAppend);
    p->n += nAppend;
    p->z[p->n] = 'A';
  }
}
static char quoteChar(const char *zName) {
  int i;
  if (zName == 0)
    return '\"';
  if (!((*__ctype_b_loc())[(int)(((unsigned char)zName[0]))] &
        (unsigned short int)_ISalpha) &&
      zName[0] != '_')
    return '\"';
  for (i = 0; zName[i]; i++) {
    if (!((*__ctype_b_loc())[(int)(((unsigned char)zName[i]))] &
          (unsigned short int)_ISalnum) &&
        zName[i] != '_')
      return '\"';
  }
  return sqlite3_keyword_check(zName, i) ? '\"' : 0;
}
static char *shellFakeSchema(sqlite3 *db, const char *zSchema,
                             const char *zName) {
  sqlite3_stmt *pStmt = 0;
  char *zSql;
  ShellText s;
  char cQuote;
  char *zDiv = "(";
  int nRow = 0;
  zSql = sqlite3_mprintf("PRAGMA \"%w\".table_info=%Q;",
                         zSchema ? zSchema : "main", zName);
  shell_check_oom(zSql);
  sqlite3_prepare_v2(db, zSql, -1, &pStmt, 0);
  sqlite3_free(zSql);
  initText(&s);
  if (zSchema) {
    cQuote = quoteChar(zSchema);
    if (cQuote && sqlite3_stricmp(zSchema, "temp") == 0)
      cQuote = 0;
    appendText(&s, zSchema, cQuote);
    appendText(&s, ".", 0);
  }
  cQuote = quoteChar(zName);
  appendText(&s, zName, cQuote);
  while (sqlite3_step(pStmt) == 100) {
    const char *zCol = (const char *)sqlite3_column_text(pStmt, 1);
    nRow++;
    appendText(&s, zDiv, 0);
    zDiv = ",";
    if (zCol == 0)
      zCol = "";
    cQuote = quoteChar(zCol);
    appendText(&s, zCol, cQuote);
  }
  appendText(&s, ")", 0);
  sqlite3_finalize(pStmt);
  if (nRow == 0) {
    freeText(&s);
    s.z = 0;
  }
  return s.z;
}
static void shellModuleSchema(sqlite3_context *pCtx, int nVal,
                              sqlite3_value **apVal) {
  const char *zName;
  char *zFake;
  (void)(nVal);
  zName = (const char *)sqlite3_value_text(apVal[0]);
  zFake =
      zName ? shellFakeSchema(sqlite3_context_db_handle(pCtx), 0, zName) : 0;
  if (zFake) {
    sqlite3_result_text(pCtx, sqlite3_mprintf("/* %s */", zFake), -1,
                        sqlite3_free);
    free(zFake);
  }
}
static void shellAddSchemaName(sqlite3_context *pCtx, int nVal,
                               sqlite3_value **apVal) {
  static const char *aPrefix[] = {"TABLE", "INDEX",   "UNIQUE INDEX",
                                  "VIEW",  "TRIGGER", "VIRTUAL TABLE"};
  int i = 0;
  const char *zIn = (const char *)sqlite3_value_text(apVal[0]);
  const char *zSchema = (const char *)sqlite3_value_text(apVal[1]);
  const char *zName = (const char *)sqlite3_value_text(apVal[2]);
  sqlite3 *db = sqlite3_context_db_handle(pCtx);
  (void)(nVal);
  if (zIn != 0 && cli_strncmp(zIn, "CREATE ", 7) == 0) {
    for (i = 0; i < (int)(sizeof(aPrefix) / sizeof(aPrefix[0])); i++) {
      int n = strlen30(aPrefix[i]);
      if (cli_strncmp(zIn + 7, aPrefix[i], n) == 0 && zIn[n + 7] == ' ') {
        char *z = 0;
        char *zFake = 0;
        if (zSchema) {
          char cQuote = quoteChar(zSchema);
          if (cQuote && sqlite3_stricmp(zSchema, "temp") != 0) {
            z = sqlite3_mprintf("%.*s \"%w\".%s", n + 7, zIn, zSchema,
                                zIn + n + 8);
          } else {
            z = sqlite3_mprintf("%.*s %s.%s", n + 7, zIn, zSchema, zIn + n + 8);
          }
        }
        if (zName && aPrefix[i][0] == 'V' &&
            (zFake = shellFakeSchema(db, zSchema, zName)) != 0) {
          if (z == 0) {
            z = sqlite3_mprintf("%s\n/* %s */", zIn, zFake);
          } else {
            z = sqlite3_mprintf("%z\n/* %s */", z, zFake);
          }
          free(zFake);
        }
        if (z) {
          sqlite3_result_text(pCtx, z, -1, sqlite3_free);
          return;
        }
      }
    }
  }
  sqlite3_result_value(pCtx, apVal[0]);
}
static sqlite3_mem_methods memtraceBase;
static FILE *memtraceOut;
static void *memtraceMalloc(int n) {
  if (memtraceOut) {
    fprintf(memtraceOut, "MEMTRACE: allocate %d bytes\n",
            memtraceBase.xRoundup(n));
  }
  return memtraceBase.xMalloc(n);
}
static void memtraceFree(void *p) {
  if (p == 0)
    return;
  if (memtraceOut) {
    fprintf(memtraceOut, "MEMTRACE: free %d bytes\n", memtraceBase.xSize(p));
  }
  memtraceBase.xFree(p);
}
static void *memtraceRealloc(void *p, int n) {
  if (p == 0)
    return memtraceMalloc(n);
  if (n == 0) {
    memtraceFree(p);
    return 0;
  }
  if (memtraceOut) {
    fprintf(memtraceOut, "MEMTRACE: resize %d -> %d bytes\n",
            memtraceBase.xSize(p), memtraceBase.xRoundup(n));
  }
  return memtraceBase.xRealloc(p, n);
}
static int memtraceSize(void *p) { return memtraceBase.xSize(p); }
static int memtraceRoundup(int n) { return memtraceBase.xRoundup(n); }
static int memtraceInit(void *p) { return memtraceBase.xInit(p); }
static void memtraceShutdown(void *p) { memtraceBase.xShutdown(p); }
static sqlite3_mem_methods ersaztMethods = {
    memtraceMalloc,  memtraceFree, memtraceRealloc,  memtraceSize,
    memtraceRoundup, memtraceInit, memtraceShutdown, 0};
int sqlite3MemTraceActivate(FILE *out) {
  int rc = 0;
  if (memtraceBase.xMalloc == 0) {
    rc = sqlite3_config(5, &memtraceBase);
    if (rc == 0) {
      rc = sqlite3_config(4, &ersaztMethods);
    }
  }
  memtraceOut = out;
  return rc;
}
int sqlite3MemTraceDeactivate(void) {
  int rc = 0;
  if (memtraceBase.xMalloc != 0) {
    rc = sqlite3_config(4, &memtraceBase);
    if (rc == 0) {
      memset(&memtraceBase, 0, sizeof(memtraceBase));
    }
  }
  memtraceOut = 0;
  return rc;
}
typedef struct SHA3Context SHA3Context;
struct SHA3Context {
  union {
    u64 s[25];
    unsigned char x[1600];
  } u;
  unsigned nRate;
  unsigned nLoaded;
  unsigned ixMask;
};
static void KeccakF1600Step(SHA3Context *p) {
  int i;
  u64 b0, b1, b2, b3, b4;
  u64 c0, c1, c2, c3, c4;
  u64 d0, d1, d2, d3, d4;
  static const u64 RC[] = {1,
                           32898,
                           9223372036854808714,
                           9223372039002292224,
                           32907,
                           2147483649,
                           9223372039002292353,
                           9223372036854808585,
                           138,
                           136,
                           2147516425,
                           2147483658,
                           2147516555,
                           9223372036854775947,
                           9223372036854808713,
                           9223372036854808579,
                           9223372036854808578,
                           9223372036854775936,
                           32778,
                           9223372039002259466,
                           9223372039002292353,
                           9223372036854808704,
                           2147483649,
                           9223372039002292232};
  for (i = 0; i < 24; i += 4) {
    c0 = (p->u.s[0]) ^ (p->u.s[5]) ^ (p->u.s[10]) ^ (p->u.s[15]) ^ (p->u.s[20]);
    c1 = (p->u.s[1]) ^ (p->u.s[6]) ^ (p->u.s[11]) ^ (p->u.s[16]) ^ (p->u.s[21]);
    c2 = (p->u.s[2]) ^ (p->u.s[7]) ^ (p->u.s[12]) ^ (p->u.s[17]) ^ (p->u.s[22]);
    c3 = (p->u.s[3]) ^ (p->u.s[8]) ^ (p->u.s[13]) ^ (p->u.s[18]) ^ (p->u.s[23]);
    c4 = (p->u.s[4]) ^ (p->u.s[9]) ^ (p->u.s[14]) ^ (p->u.s[19]) ^ (p->u.s[24]);
    d0 = c4 ^ ((c1 << 1) | (c1 >> (64 - 1)));
    d1 = c0 ^ ((c2 << 1) | (c2 >> (64 - 1)));
    d2 = c1 ^ ((c3 << 1) | (c3 >> (64 - 1)));
    d3 = c2 ^ ((c4 << 1) | (c4 >> (64 - 1)));
    d4 = c3 ^ ((c0 << 1) | (c0 >> (64 - 1)));
    b0 = ((p->u.s[0]) ^ d0);
    b1 = ((((p->u.s[6]) ^ d1) << 44) | (((p->u.s[6]) ^ d1) >> (64 - 44)));
    b2 = ((((p->u.s[12]) ^ d2) << 43) | (((p->u.s[12]) ^ d2) >> (64 - 43)));
    b3 = ((((p->u.s[18]) ^ d3) << 21) | (((p->u.s[18]) ^ d3) >> (64 - 21)));
    b4 = ((((p->u.s[24]) ^ d4) << 14) | (((p->u.s[24]) ^ d4) >> (64 - 14)));
    (p->u.s[0]) = b0 ^ ((~b1) & b2);
    (p->u.s[0]) ^= RC[i];
    (p->u.s[6]) = b1 ^ ((~b2) & b3);
    (p->u.s[12]) = b2 ^ ((~b3) & b4);
    (p->u.s[18]) = b3 ^ ((~b4) & b0);
    (p->u.s[24]) = b4 ^ ((~b0) & b1);
    b2 = ((((p->u.s[10]) ^ d0) << 3) | (((p->u.s[10]) ^ d0) >> (64 - 3)));
    b3 = ((((p->u.s[16]) ^ d1) << 45) | (((p->u.s[16]) ^ d1) >> (64 - 45)));
    b4 = ((((p->u.s[22]) ^ d2) << 61) | (((p->u.s[22]) ^ d2) >> (64 - 61)));
    b0 = ((((p->u.s[3]) ^ d3) << 28) | (((p->u.s[3]) ^ d3) >> (64 - 28)));
    b1 = ((((p->u.s[9]) ^ d4) << 20) | (((p->u.s[9]) ^ d4) >> (64 - 20)));
    (p->u.s[10]) = b0 ^ ((~b1) & b2);
    (p->u.s[16]) = b1 ^ ((~b2) & b3);
    (p->u.s[22]) = b2 ^ ((~b3) & b4);
    (p->u.s[3]) = b3 ^ ((~b4) & b0);
    (p->u.s[9]) = b4 ^ ((~b0) & b1);
    b4 = ((((p->u.s[20]) ^ d0) << 18) | (((p->u.s[20]) ^ d0) >> (64 - 18)));
    b0 = ((((p->u.s[1]) ^ d1) << 1) | (((p->u.s[1]) ^ d1) >> (64 - 1)));
    b1 = ((((p->u.s[7]) ^ d2) << 6) | (((p->u.s[7]) ^ d2) >> (64 - 6)));
    b2 = ((((p->u.s[13]) ^ d3) << 25) | (((p->u.s[13]) ^ d3) >> (64 - 25)));
    b3 = ((((p->u.s[19]) ^ d4) << 8) | (((p->u.s[19]) ^ d4) >> (64 - 8)));
    (p->u.s[20]) = b0 ^ ((~b1) & b2);
    (p->u.s[1]) = b1 ^ ((~b2) & b3);
    (p->u.s[7]) = b2 ^ ((~b3) & b4);
    (p->u.s[13]) = b3 ^ ((~b4) & b0);
    (p->u.s[19]) = b4 ^ ((~b0) & b1);
    b1 = ((((p->u.s[5]) ^ d0) << 36) | (((p->u.s[5]) ^ d0) >> (64 - 36)));
    b2 = ((((p->u.s[11]) ^ d1) << 10) | (((p->u.s[11]) ^ d1) >> (64 - 10)));
    b3 = ((((p->u.s[17]) ^ d2) << 15) | (((p->u.s[17]) ^ d2) >> (64 - 15)));
    b4 = ((((p->u.s[23]) ^ d3) << 56) | (((p->u.s[23]) ^ d3) >> (64 - 56)));
    b0 = ((((p->u.s[4]) ^ d4) << 27) | (((p->u.s[4]) ^ d4) >> (64 - 27)));
    (p->u.s[5]) = b0 ^ ((~b1) & b2);
    (p->u.s[11]) = b1 ^ ((~b2) & b3);
    (p->u.s[17]) = b2 ^ ((~b3) & b4);
    (p->u.s[23]) = b3 ^ ((~b4) & b0);
    (p->u.s[4]) = b4 ^ ((~b0) & b1);
    b3 = ((((p->u.s[15]) ^ d0) << 41) | (((p->u.s[15]) ^ d0) >> (64 - 41)));
    b4 = ((((p->u.s[21]) ^ d1) << 2) | (((p->u.s[21]) ^ d1) >> (64 - 2)));
    b0 = ((((p->u.s[2]) ^ d2) << 62) | (((p->u.s[2]) ^ d2) >> (64 - 62)));
    b1 = ((((p->u.s[8]) ^ d3) << 55) | (((p->u.s[8]) ^ d3) >> (64 - 55)));
    b2 = ((((p->u.s[14]) ^ d4) << 39) | (((p->u.s[14]) ^ d4) >> (64 - 39)));
    (p->u.s[15]) = b0 ^ ((~b1) & b2);
    (p->u.s[21]) = b1 ^ ((~b2) & b3);
    (p->u.s[2]) = b2 ^ ((~b3) & b4);
    (p->u.s[8]) = b3 ^ ((~b4) & b0);
    (p->u.s[14]) = b4 ^ ((~b0) & b1);
    c0 = (p->u.s[0]) ^ (p->u.s[10]) ^ (p->u.s[20]) ^ (p->u.s[5]) ^ (p->u.s[15]);
    c1 = (p->u.s[6]) ^ (p->u.s[16]) ^ (p->u.s[1]) ^ (p->u.s[11]) ^ (p->u.s[21]);
    c2 = (p->u.s[12]) ^ (p->u.s[22]) ^ (p->u.s[7]) ^ (p->u.s[17]) ^ (p->u.s[2]);
    c3 = (p->u.s[18]) ^ (p->u.s[3]) ^ (p->u.s[13]) ^ (p->u.s[23]) ^ (p->u.s[8]);
    c4 = (p->u.s[24]) ^ (p->u.s[9]) ^ (p->u.s[19]) ^ (p->u.s[4]) ^ (p->u.s[14]);
    d0 = c4 ^ ((c1 << 1) | (c1 >> (64 - 1)));
    d1 = c0 ^ ((c2 << 1) | (c2 >> (64 - 1)));
    d2 = c1 ^ ((c3 << 1) | (c3 >> (64 - 1)));
    d3 = c2 ^ ((c4 << 1) | (c4 >> (64 - 1)));
    d4 = c3 ^ ((c0 << 1) | (c0 >> (64 - 1)));
    b0 = ((p->u.s[0]) ^ d0);
    b1 = ((((p->u.s[16]) ^ d1) << 44) | (((p->u.s[16]) ^ d1) >> (64 - 44)));
    b2 = ((((p->u.s[7]) ^ d2) << 43) | (((p->u.s[7]) ^ d2) >> (64 - 43)));
    b3 = ((((p->u.s[23]) ^ d3) << 21) | (((p->u.s[23]) ^ d3) >> (64 - 21)));
    b4 = ((((p->u.s[14]) ^ d4) << 14) | (((p->u.s[14]) ^ d4) >> (64 - 14)));
    (p->u.s[0]) = b0 ^ ((~b1) & b2);
    (p->u.s[0]) ^= RC[i + 1];
    (p->u.s[16]) = b1 ^ ((~b2) & b3);
    (p->u.s[7]) = b2 ^ ((~b3) & b4);
    (p->u.s[23]) = b3 ^ ((~b4) & b0);
    (p->u.s[14]) = b4 ^ ((~b0) & b1);
    b2 = ((((p->u.s[20]) ^ d0) << 3) | (((p->u.s[20]) ^ d0) >> (64 - 3)));
    b3 = ((((p->u.s[11]) ^ d1) << 45) | (((p->u.s[11]) ^ d1) >> (64 - 45)));
    b4 = ((((p->u.s[2]) ^ d2) << 61) | (((p->u.s[2]) ^ d2) >> (64 - 61)));
    b0 = ((((p->u.s[18]) ^ d3) << 28) | (((p->u.s[18]) ^ d3) >> (64 - 28)));
    b1 = ((((p->u.s[9]) ^ d4) << 20) | (((p->u.s[9]) ^ d4) >> (64 - 20)));
    (p->u.s[20]) = b0 ^ ((~b1) & b2);
    (p->u.s[11]) = b1 ^ ((~b2) & b3);
    (p->u.s[2]) = b2 ^ ((~b3) & b4);
    (p->u.s[18]) = b3 ^ ((~b4) & b0);
    (p->u.s[9]) = b4 ^ ((~b0) & b1);
    b4 = ((((p->u.s[15]) ^ d0) << 18) | (((p->u.s[15]) ^ d0) >> (64 - 18)));
    b0 = ((((p->u.s[6]) ^ d1) << 1) | (((p->u.s[6]) ^ d1) >> (64 - 1)));
    b1 = ((((p->u.s[22]) ^ d2) << 6) | (((p->u.s[22]) ^ d2) >> (64 - 6)));
    b2 = ((((p->u.s[13]) ^ d3) << 25) | (((p->u.s[13]) ^ d3) >> (64 - 25)));
    b3 = ((((p->u.s[4]) ^ d4) << 8) | (((p->u.s[4]) ^ d4) >> (64 - 8)));
    (p->u.s[15]) = b0 ^ ((~b1) & b2);
    (p->u.s[6]) = b1 ^ ((~b2) & b3);
    (p->u.s[22]) = b2 ^ ((~b3) & b4);
    (p->u.s[13]) = b3 ^ ((~b4) & b0);
    (p->u.s[4]) = b4 ^ ((~b0) & b1);
    b1 = ((((p->u.s[10]) ^ d0) << 36) | (((p->u.s[10]) ^ d0) >> (64 - 36)));
    b2 = ((((p->u.s[1]) ^ d1) << 10) | (((p->u.s[1]) ^ d1) >> (64 - 10)));
    b3 = ((((p->u.s[17]) ^ d2) << 15) | (((p->u.s[17]) ^ d2) >> (64 - 15)));
    b4 = ((((p->u.s[8]) ^ d3) << 56) | (((p->u.s[8]) ^ d3) >> (64 - 56)));
    b0 = ((((p->u.s[24]) ^ d4) << 27) | (((p->u.s[24]) ^ d4) >> (64 - 27)));
    (p->u.s[10]) = b0 ^ ((~b1) & b2);
    (p->u.s[1]) = b1 ^ ((~b2) & b3);
    (p->u.s[17]) = b2 ^ ((~b3) & b4);
    (p->u.s[8]) = b3 ^ ((~b4) & b0);
    (p->u.s[24]) = b4 ^ ((~b0) & b1);
    b3 = ((((p->u.s[5]) ^ d0) << 41) | (((p->u.s[5]) ^ d0) >> (64 - 41)));
    b4 = ((((p->u.s[21]) ^ d1) << 2) | (((p->u.s[21]) ^ d1) >> (64 - 2)));
    b0 = ((((p->u.s[12]) ^ d2) << 62) | (((p->u.s[12]) ^ d2) >> (64 - 62)));
    b1 = ((((p->u.s[3]) ^ d3) << 55) | (((p->u.s[3]) ^ d3) >> (64 - 55)));
    b2 = ((((p->u.s[19]) ^ d4) << 39) | (((p->u.s[19]) ^ d4) >> (64 - 39)));
    (p->u.s[5]) = b0 ^ ((~b1) & b2);
    (p->u.s[21]) = b1 ^ ((~b2) & b3);
    (p->u.s[12]) = b2 ^ ((~b3) & b4);
    (p->u.s[3]) = b3 ^ ((~b4) & b0);
    (p->u.s[19]) = b4 ^ ((~b0) & b1);
    c0 = (p->u.s[0]) ^ (p->u.s[20]) ^ (p->u.s[15]) ^ (p->u.s[10]) ^ (p->u.s[5]);
    c1 = (p->u.s[16]) ^ (p->u.s[11]) ^ (p->u.s[6]) ^ (p->u.s[1]) ^ (p->u.s[21]);
    c2 = (p->u.s[7]) ^ (p->u.s[2]) ^ (p->u.s[22]) ^ (p->u.s[17]) ^ (p->u.s[12]);
    c3 = (p->u.s[23]) ^ (p->u.s[18]) ^ (p->u.s[13]) ^ (p->u.s[8]) ^ (p->u.s[3]);
    c4 = (p->u.s[14]) ^ (p->u.s[9]) ^ (p->u.s[4]) ^ (p->u.s[24]) ^ (p->u.s[19]);
    d0 = c4 ^ ((c1 << 1) | (c1 >> (64 - 1)));
    d1 = c0 ^ ((c2 << 1) | (c2 >> (64 - 1)));
    d2 = c1 ^ ((c3 << 1) | (c3 >> (64 - 1)));
    d3 = c2 ^ ((c4 << 1) | (c4 >> (64 - 1)));
    d4 = c3 ^ ((c0 << 1) | (c0 >> (64 - 1)));
    b0 = ((p->u.s[0]) ^ d0);
    b1 = ((((p->u.s[11]) ^ d1) << 44) | (((p->u.s[11]) ^ d1) >> (64 - 44)));
    b2 = ((((p->u.s[22]) ^ d2) << 43) | (((p->u.s[22]) ^ d2) >> (64 - 43)));
    b3 = ((((p->u.s[8]) ^ d3) << 21) | (((p->u.s[8]) ^ d3) >> (64 - 21)));
    b4 = ((((p->u.s[19]) ^ d4) << 14) | (((p->u.s[19]) ^ d4) >> (64 - 14)));
    (p->u.s[0]) = b0 ^ ((~b1) & b2);
    (p->u.s[0]) ^= RC[i + 2];
    (p->u.s[11]) = b1 ^ ((~b2) & b3);
    (p->u.s[22]) = b2 ^ ((~b3) & b4);
    (p->u.s[8]) = b3 ^ ((~b4) & b0);
    (p->u.s[19]) = b4 ^ ((~b0) & b1);
    b2 = ((((p->u.s[15]) ^ d0) << 3) | (((p->u.s[15]) ^ d0) >> (64 - 3)));
    b3 = ((((p->u.s[1]) ^ d1) << 45) | (((p->u.s[1]) ^ d1) >> (64 - 45)));
    b4 = ((((p->u.s[12]) ^ d2) << 61) | (((p->u.s[12]) ^ d2) >> (64 - 61)));
    b0 = ((((p->u.s[23]) ^ d3) << 28) | (((p->u.s[23]) ^ d3) >> (64 - 28)));
    b1 = ((((p->u.s[9]) ^ d4) << 20) | (((p->u.s[9]) ^ d4) >> (64 - 20)));
    (p->u.s[15]) = b0 ^ ((~b1) & b2);
    (p->u.s[1]) = b1 ^ ((~b2) & b3);
    (p->u.s[12]) = b2 ^ ((~b3) & b4);
    (p->u.s[23]) = b3 ^ ((~b4) & b0);
    (p->u.s[9]) = b4 ^ ((~b0) & b1);
    b4 = ((((p->u.s[5]) ^ d0) << 18) | (((p->u.s[5]) ^ d0) >> (64 - 18)));
    b0 = ((((p->u.s[16]) ^ d1) << 1) | (((p->u.s[16]) ^ d1) >> (64 - 1)));
    b1 = ((((p->u.s[2]) ^ d2) << 6) | (((p->u.s[2]) ^ d2) >> (64 - 6)));
    b2 = ((((p->u.s[13]) ^ d3) << 25) | (((p->u.s[13]) ^ d3) >> (64 - 25)));
    b3 = ((((p->u.s[24]) ^ d4) << 8) | (((p->u.s[24]) ^ d4) >> (64 - 8)));
    (p->u.s[5]) = b0 ^ ((~b1) & b2);
    (p->u.s[16]) = b1 ^ ((~b2) & b3);
    (p->u.s[2]) = b2 ^ ((~b3) & b4);
    (p->u.s[13]) = b3 ^ ((~b4) & b0);
    (p->u.s[24]) = b4 ^ ((~b0) & b1);
    b1 = ((((p->u.s[20]) ^ d0) << 36) | (((p->u.s[20]) ^ d0) >> (64 - 36)));
    b2 = ((((p->u.s[6]) ^ d1) << 10) | (((p->u.s[6]) ^ d1) >> (64 - 10)));
    b3 = ((((p->u.s[17]) ^ d2) << 15) | (((p->u.s[17]) ^ d2) >> (64 - 15)));
    b4 = ((((p->u.s[3]) ^ d3) << 56) | (((p->u.s[3]) ^ d3) >> (64 - 56)));
    b0 = ((((p->u.s[14]) ^ d4) << 27) | (((p->u.s[14]) ^ d4) >> (64 - 27)));
    (p->u.s[20]) = b0 ^ ((~b1) & b2);
    (p->u.s[6]) = b1 ^ ((~b2) & b3);
    (p->u.s[17]) = b2 ^ ((~b3) & b4);
    (p->u.s[3]) = b3 ^ ((~b4) & b0);
    (p->u.s[14]) = b4 ^ ((~b0) & b1);
    b3 = ((((p->u.s[10]) ^ d0) << 41) | (((p->u.s[10]) ^ d0) >> (64 - 41)));
    b4 = ((((p->u.s[21]) ^ d1) << 2) | (((p->u.s[21]) ^ d1) >> (64 - 2)));
    b0 = ((((p->u.s[7]) ^ d2) << 62) | (((p->u.s[7]) ^ d2) >> (64 - 62)));
    b1 = ((((p->u.s[18]) ^ d3) << 55) | (((p->u.s[18]) ^ d3) >> (64 - 55)));
    b2 = ((((p->u.s[4]) ^ d4) << 39) | (((p->u.s[4]) ^ d4) >> (64 - 39)));
    (p->u.s[10]) = b0 ^ ((~b1) & b2);
    (p->u.s[21]) = b1 ^ ((~b2) & b3);
    (p->u.s[7]) = b2 ^ ((~b3) & b4);
    (p->u.s[18]) = b3 ^ ((~b4) & b0);
    (p->u.s[4]) = b4 ^ ((~b0) & b1);
    c0 = (p->u.s[0]) ^ (p->u.s[15]) ^ (p->u.s[5]) ^ (p->u.s[20]) ^ (p->u.s[10]);
    c1 = (p->u.s[11]) ^ (p->u.s[1]) ^ (p->u.s[16]) ^ (p->u.s[6]) ^ (p->u.s[21]);
    c2 = (p->u.s[22]) ^ (p->u.s[12]) ^ (p->u.s[2]) ^ (p->u.s[17]) ^ (p->u.s[7]);
    c3 = (p->u.s[8]) ^ (p->u.s[23]) ^ (p->u.s[13]) ^ (p->u.s[3]) ^ (p->u.s[18]);
    c4 = (p->u.s[19]) ^ (p->u.s[9]) ^ (p->u.s[24]) ^ (p->u.s[14]) ^ (p->u.s[4]);
    d0 = c4 ^ ((c1 << 1) | (c1 >> (64 - 1)));
    d1 = c0 ^ ((c2 << 1) | (c2 >> (64 - 1)));
    d2 = c1 ^ ((c3 << 1) | (c3 >> (64 - 1)));
    d3 = c2 ^ ((c4 << 1) | (c4 >> (64 - 1)));
    d4 = c3 ^ ((c0 << 1) | (c0 >> (64 - 1)));
    b0 = ((p->u.s[0]) ^ d0);
    b1 = ((((p->u.s[1]) ^ d1) << 44) | (((p->u.s[1]) ^ d1) >> (64 - 44)));
    b2 = ((((p->u.s[2]) ^ d2) << 43) | (((p->u.s[2]) ^ d2) >> (64 - 43)));
    b3 = ((((p->u.s[3]) ^ d3) << 21) | (((p->u.s[3]) ^ d3) >> (64 - 21)));
    b4 = ((((p->u.s[4]) ^ d4) << 14) | (((p->u.s[4]) ^ d4) >> (64 - 14)));
    (p->u.s[0]) = b0 ^ ((~b1) & b2);
    (p->u.s[0]) ^= RC[i + 3];
    (p->u.s[1]) = b1 ^ ((~b2) & b3);
    (p->u.s[2]) = b2 ^ ((~b3) & b4);
    (p->u.s[3]) = b3 ^ ((~b4) & b0);
    (p->u.s[4]) = b4 ^ ((~b0) & b1);
    b2 = ((((p->u.s[5]) ^ d0) << 3) | (((p->u.s[5]) ^ d0) >> (64 - 3)));
    b3 = ((((p->u.s[6]) ^ d1) << 45) | (((p->u.s[6]) ^ d1) >> (64 - 45)));
    b4 = ((((p->u.s[7]) ^ d2) << 61) | (((p->u.s[7]) ^ d2) >> (64 - 61)));
    b0 = ((((p->u.s[8]) ^ d3) << 28) | (((p->u.s[8]) ^ d3) >> (64 - 28)));
    b1 = ((((p->u.s[9]) ^ d4) << 20) | (((p->u.s[9]) ^ d4) >> (64 - 20)));
    (p->u.s[5]) = b0 ^ ((~b1) & b2);
    (p->u.s[6]) = b1 ^ ((~b2) & b3);
    (p->u.s[7]) = b2 ^ ((~b3) & b4);
    (p->u.s[8]) = b3 ^ ((~b4) & b0);
    (p->u.s[9]) = b4 ^ ((~b0) & b1);
    b4 = ((((p->u.s[10]) ^ d0) << 18) | (((p->u.s[10]) ^ d0) >> (64 - 18)));
    b0 = ((((p->u.s[11]) ^ d1) << 1) | (((p->u.s[11]) ^ d1) >> (64 - 1)));
    b1 = ((((p->u.s[12]) ^ d2) << 6) | (((p->u.s[12]) ^ d2) >> (64 - 6)));
    b2 = ((((p->u.s[13]) ^ d3) << 25) | (((p->u.s[13]) ^ d3) >> (64 - 25)));
    b3 = ((((p->u.s[14]) ^ d4) << 8) | (((p->u.s[14]) ^ d4) >> (64 - 8)));
    (p->u.s[10]) = b0 ^ ((~b1) & b2);
    (p->u.s[11]) = b1 ^ ((~b2) & b3);
    (p->u.s[12]) = b2 ^ ((~b3) & b4);
    (p->u.s[13]) = b3 ^ ((~b4) & b0);
    (p->u.s[14]) = b4 ^ ((~b0) & b1);
    b1 = ((((p->u.s[15]) ^ d0) << 36) | (((p->u.s[15]) ^ d0) >> (64 - 36)));
    b2 = ((((p->u.s[16]) ^ d1) << 10) | (((p->u.s[16]) ^ d1) >> (64 - 10)));
    b3 = ((((p->u.s[17]) ^ d2) << 15) | (((p->u.s[17]) ^ d2) >> (64 - 15)));
    b4 = ((((p->u.s[18]) ^ d3) << 56) | (((p->u.s[18]) ^ d3) >> (64 - 56)));
    b0 = ((((p->u.s[19]) ^ d4) << 27) | (((p->u.s[19]) ^ d4) >> (64 - 27)));
    (p->u.s[15]) = b0 ^ ((~b1) & b2);
    (p->u.s[16]) = b1 ^ ((~b2) & b3);
    (p->u.s[17]) = b2 ^ ((~b3) & b4);
    (p->u.s[18]) = b3 ^ ((~b4) & b0);
    (p->u.s[19]) = b4 ^ ((~b0) & b1);
    b3 = ((((p->u.s[20]) ^ d0) << 41) | (((p->u.s[20]) ^ d0) >> (64 - 41)));
    b4 = ((((p->u.s[21]) ^ d1) << 2) | (((p->u.s[21]) ^ d1) >> (64 - 2)));
    b0 = ((((p->u.s[22]) ^ d2) << 62) | (((p->u.s[22]) ^ d2) >> (64 - 62)));
    b1 = ((((p->u.s[23]) ^ d3) << 55) | (((p->u.s[23]) ^ d3) >> (64 - 55)));
    b2 = ((((p->u.s[24]) ^ d4) << 39) | (((p->u.s[24]) ^ d4) >> (64 - 39)));
    (p->u.s[20]) = b0 ^ ((~b1) & b2);
    (p->u.s[21]) = b1 ^ ((~b2) & b3);
    (p->u.s[22]) = b2 ^ ((~b3) & b4);
    (p->u.s[23]) = b3 ^ ((~b4) & b0);
    (p->u.s[24]) = b4 ^ ((~b0) & b1);
  }
}
static void SHA3Init(SHA3Context *p, int iSize) {
  memset(p, 0, sizeof(*p));
  if (iSize >= 128 && iSize <= 512) {
    p->nRate = (1600 - ((iSize + 31) & ~31) * 2) / 8;
  } else {
    p->nRate = (1600 - 2 * 256) / 8;
  }
}
static void SHA3Update(SHA3Context *p, const unsigned char *aData,
                       unsigned int nData) {
  unsigned int i = 0;
  if (aData == 0)
    return;
  if ((p->nLoaded % 8) == 0 && ((aData - (const unsigned char *)0) & 7) == 0) {
    for (; i + 7 < nData; i += 8) {
      p->u.s[p->nLoaded / 8] ^= *(u64 *)&aData[i];
      p->nLoaded += 8;
      if (p->nLoaded >= p->nRate) {
        KeccakF1600Step(p);
        p->nLoaded = 0;
      }
    }
  }
  for (; i < nData; i++) {
    p->u.x[p->nLoaded] ^= aData[i];
    p->nLoaded++;
    if (p->nLoaded == p->nRate) {
      KeccakF1600Step(p);
      p->nLoaded = 0;
    }
  }
}
static unsigned char *SHA3Final(SHA3Context *p) {
  unsigned int i;
  if (p->nLoaded == p->nRate - 1) {
    const unsigned char c1 = 134;
    SHA3Update(p, &c1, 1);
  } else {
    const unsigned char c2 = 6;
    const unsigned char c3 = 128;
    SHA3Update(p, &c2, 1);
    p->nLoaded = p->nRate - 1;
    SHA3Update(p, &c3, 1);
  }
  for (i = 0; i < p->nRate; i++) {
    p->u.x[i + p->nRate] = p->u.x[i ^ p->ixMask];
  }
  return &p->u.x[p->nRate];
}
static void sha3Func(sqlite3_context *context, int argc, sqlite3_value **argv) {
  SHA3Context cx;
  int eType = sqlite3_value_type(argv[0]);
  int nByte = sqlite3_value_bytes(argv[0]);
  int iSize;
  if (argc == 1) {
    iSize = 256;
  } else {
    iSize = sqlite3_value_int(argv[1]);
    if (iSize != 224 && iSize != 256 && iSize != 384 && iSize != 512) {
      sqlite3_result_error(context,
                           "SHA3 size should be one of: 224 256 384 512", -1);
      return;
    }
  }
  if (eType == 5)
    return;
  SHA3Init(&cx, iSize);
  if (eType == 4) {
    SHA3Update(&cx, sqlite3_value_blob(argv[0]), nByte);
  } else {
    SHA3Update(&cx, sqlite3_value_text(argv[0]), nByte);
  }
  sqlite3_result_blob(context, SHA3Final(&cx), iSize / 8,
                      ((sqlite3_destructor_type)-1));
}
static void sha3_step_vformat(SHA3Context *p, const char *zFormat, ...) {
  va_list ap;
  int n;
  char zBuf[50];
  __builtin_va_start(ap, zFormat);
  sqlite3_vsnprintf(sizeof(zBuf), zBuf, zFormat, ap);
  __builtin_va_end(ap);
  n = (int)strlen(zBuf);
  SHA3Update(p, (unsigned char *)zBuf, n);
}
static void sha3QueryFunc(sqlite3_context *context, int argc,
                          sqlite3_value **argv) {
  sqlite3 *db = sqlite3_context_db_handle(context);
  const char *zSql = (const char *)sqlite3_value_text(argv[0]);
  sqlite3_stmt *pStmt = 0;
  int nCol;
  int i;
  int rc;
  int n;
  const char *z;
  SHA3Context cx;
  int iSize;
  if (argc == 1) {
    iSize = 256;
  } else {
    iSize = sqlite3_value_int(argv[1]);
    if (iSize != 224 && iSize != 256 && iSize != 384 && iSize != 512) {
      sqlite3_result_error(context,
                           "SHA3 size should be one of: 224 256 384 512", -1);
      return;
    }
  }
  if (zSql == 0)
    return;
  SHA3Init(&cx, iSize);
  while (zSql[0]) {
    rc = sqlite3_prepare_v2(db, zSql, -1, &pStmt, &zSql);
    if (rc) {
      char *zMsg = sqlite3_mprintf("error SQL statement [%s]: %s", zSql,
                                   sqlite3_errmsg(db));
      sqlite3_finalize(pStmt);
      sqlite3_result_error(context, zMsg, -1);
      sqlite3_free(zMsg);
      return;
    }
    if (!sqlite3_stmt_readonly(pStmt)) {
      char *zMsg = sqlite3_mprintf("non-query: [%s]", sqlite3_sql(pStmt));
      sqlite3_finalize(pStmt);
      sqlite3_result_error(context, zMsg, -1);
      sqlite3_free(zMsg);
      return;
    }
    nCol = sqlite3_column_count(pStmt);
    z = sqlite3_sql(pStmt);
    if (z) {
      n = (int)strlen(z);
      sha3_step_vformat(&cx, "S%d:", n);
      SHA3Update(&cx, (unsigned char *)z, n);
    }
    while (100 == sqlite3_step(pStmt)) {
      SHA3Update(&cx, (const unsigned char *)"R", 1);
      for (i = 0; i < nCol; i++) {
        switch (sqlite3_column_type(pStmt, i)) {
        case 5: {
          SHA3Update(&cx, (const unsigned char *)"N", 1);
          break;
        }
        case 1: {
          sqlite3_uint64 u;
          int j;
          unsigned char x[9];
          sqlite3_int64 v = sqlite3_column_int64(pStmt, i);
          memcpy(&u, &v, 8);
          for (j = 8; j >= 1; j--) {
            x[j] = u & 255;
            u >>= 8;
          }
          x[0] = 'I';
          SHA3Update(&cx, x, 9);
          break;
        }
        case 2: {
          sqlite3_uint64 u;
          int j;
          unsigned char x[9];
          double r = sqlite3_column_double(pStmt, i);
          memcpy(&u, &r, 8);
          for (j = 8; j >= 1; j--) {
            x[j] = u & 255;
            u >>= 8;
          }
          x[0] = 'F';
          SHA3Update(&cx, x, 9);
          break;
        }
        case 3: {
          int n2 = sqlite3_column_bytes(pStmt, i);
          const unsigned char *z2 = sqlite3_column_text(pStmt, i);
          sha3_step_vformat(&cx, "T%d:", n2);
          SHA3Update(&cx, z2, n2);
          break;
        }
        case 4: {
          int n2 = sqlite3_column_bytes(pStmt, i);
          const unsigned char *z2 = sqlite3_column_blob(pStmt, i);
          sha3_step_vformat(&cx, "B%d:", n2);
          SHA3Update(&cx, z2, n2);
          break;
        }
        }
      }
    }
    sqlite3_finalize(pStmt);
  }
  sqlite3_result_blob(context, SHA3Final(&cx), iSize / 8,
                      ((sqlite3_destructor_type)-1));
}
int sqlite3_shathree_init(sqlite3 *db, char **pzErrMsg,
                          const sqlite3_api_routines *pApi) {
  int rc = 0;
  (void)(pApi);
  (void)pzErrMsg;
  rc = sqlite3_create_function(db, "sha3", 1, 1 | 2097152 | 2048, 0, sha3Func,
                               0, 0);
  if (rc == 0) {
    rc = sqlite3_create_function(db, "sha3", 2, 1 | 2097152 | 2048, 0, sha3Func,
                                 0, 0);
  }
  if (rc == 0) {
    rc = sqlite3_create_function(db, "sha3_query", 1, 1 | 524288, 0,
                                 sha3QueryFunc, 0, 0);
  }
  if (rc == 0) {
    rc = sqlite3_create_function(db, "sha3_query", 2, 1 | 524288, 0,
                                 sha3QueryFunc, 0, 0);
  }
  return rc;
}
static int uintCollFunc(void *notUsed, int nKey1, const void *pKey1, int nKey2,
                        const void *pKey2) {
  const unsigned char *zA = (const unsigned char *)pKey1;
  const unsigned char *zB = (const unsigned char *)pKey2;
  int i = 0, j = 0, x;
  (void)notUsed;
  while (i < nKey1 && j < nKey2) {
    x = zA[i] - zB[j];
    if (((*__ctype_b_loc())[(int)((zA[i]))] & (unsigned short int)_ISdigit)) {
      int k;
      if (!((*__ctype_b_loc())[(int)((zB[j]))] & (unsigned short int)_ISdigit))
        return x;
      while (i < nKey1 && zA[i] == '0') {
        i++;
      }
      while (j < nKey2 && zB[j] == '0') {
        j++;
      }
      k = 0;
      while (i + k < nKey1 &&
             ((*__ctype_b_loc())[(int)((zA[i + k]))] &
              (unsigned short int)_ISdigit) &&
             j + k < nKey2 &&
             ((*__ctype_b_loc())[(int)((zB[j + k]))] &
              (unsigned short int)_ISdigit)) {
        k++;
      }
      if (i + k < nKey1 && ((*__ctype_b_loc())[(int)((zA[i + k]))] &
                            (unsigned short int)_ISdigit)) {
        return +1;
      } else if (j + k < nKey2 && ((*__ctype_b_loc())[(int)((zB[j + k]))] &
                                   (unsigned short int)_ISdigit)) {
        return -1;
      } else {
        x = memcmp(zA + i, zB + j, k);
        if (x)
          return x;
        i += k;
        j += k;
      }
    } else if (x) {
      return x;
    } else {
      i++;
      j++;
    }
  }
  return (nKey1 - i) - (nKey2 - j);
}
int sqlite3_uint_init(sqlite3 *db, char **pzErrMsg,
                      const sqlite3_api_routines *pApi) {
  (void)(pApi);
  (void)pzErrMsg;
  return sqlite3_create_collation(db, "uint", 1, 0, uintCollFunc);
}
typedef struct Decimal Decimal;
struct Decimal {
  char sign;
  char oom;
  char isNull;
  char isInit;
  int nDigit;
  int nFrac;
  signed char *a;
};
static void decimal_clear(Decimal *p) { sqlite3_free(p->a); }
static void decimal_free(Decimal *p) {
  if (p) {
    decimal_clear(p);
    sqlite3_free(p);
  }
}
static Decimal *decimal_new(sqlite3_context *pCtx, sqlite3_value *pIn, int nAlt,
                            const unsigned char *zAlt) {
  Decimal *p;
  int n, i;
  const unsigned char *zIn;
  int iExp = 0;
  p = sqlite3_malloc(sizeof(*p));
  if (p == 0)
    goto new_no_mem;
  p->sign = 0;
  p->oom = 0;
  p->isInit = 1;
  p->isNull = 0;
  p->nDigit = 0;
  p->nFrac = 0;
  if (zAlt) {
    n = nAlt, zIn = zAlt;
  } else {
    if (sqlite3_value_type(pIn) == 5) {
      p->a = 0;
      p->isNull = 1;
      return p;
    }
    n = sqlite3_value_bytes(pIn);
    zIn = sqlite3_value_text(pIn);
  }
  p->a = sqlite3_malloc64(n + 1);
  if (p->a == 0)
    goto new_no_mem;
  for (i = 0;
       ((*__ctype_b_loc())[(int)((zIn[i]))] & (unsigned short int)_ISspace);
       i++) {
  }
  if (zIn[i] == '-') {
    p->sign = 1;
    i++;
  } else if (zIn[i] == '+') {
    i++;
  }
  while (i < n && zIn[i] == '0')
    i++;
  while (i < n) {
    char c = zIn[i];
    if (c >= '0' && c <= '9') {
      p->a[p->nDigit++] = c - '0';
    } else if (c == '.') {
      p->nFrac = p->nDigit + 1;
    } else if (c == 'e' || c == 'E') {
      int j = i + 1;
      int neg = 0;
      if (j >= n)
        break;
      if (zIn[j] == '-') {
        neg = 1;
        j++;
      } else if (zIn[j] == '+') {
        j++;
      }
      while (j < n && iExp < 1000000) {
        if (zIn[j] >= '0' && zIn[j] <= '9') {
          iExp = iExp * 10 + zIn[j] - '0';
        }
        j++;
      }
      if (neg)
        iExp = -iExp;
      break;
    }
    i++;
  }
  if (p->nFrac) {
    p->nFrac = p->nDigit - (p->nFrac - 1);
  }
  if (iExp > 0) {
    if (p->nFrac > 0) {
      if (iExp <= p->nFrac) {
        p->nFrac -= iExp;
        iExp = 0;
      } else {
        iExp -= p->nFrac;
        p->nFrac = 0;
      }
    }
    if (iExp > 0) {
      p->a = sqlite3_realloc64(p->a, p->nDigit + iExp + 1);
      if (p->a == 0)
        goto new_no_mem;
      memset(p->a + p->nDigit, 0, iExp);
      p->nDigit += iExp;
    }
  } else if (iExp < 0) {
    int nExtra;
    iExp = -iExp;
    nExtra = p->nDigit - p->nFrac - 1;
    if (nExtra) {
      if (nExtra >= iExp) {
        p->nFrac += iExp;
        iExp = 0;
      } else {
        iExp -= nExtra;
        p->nFrac = p->nDigit - 1;
      }
    }
    if (iExp > 0) {
      p->a = sqlite3_realloc64(p->a, p->nDigit + iExp + 1);
      if (p->a == 0)
        goto new_no_mem;
      memmove(p->a + iExp, p->a, p->nDigit);
      memset(p->a, 0, iExp);
      p->nDigit += iExp;
      p->nFrac += iExp;
    }
  }
  return p;
new_no_mem:
  if (pCtx)
    sqlite3_result_error_nomem(pCtx);
  sqlite3_free(p);
  return 0;
}
static void decimal_result(sqlite3_context *pCtx, Decimal *p) {
  char *z;
  int i, j;
  int n;
  if (p == 0 || p->oom) {
    sqlite3_result_error_nomem(pCtx);
    return;
  }
  if (p->isNull) {
    sqlite3_result_null(pCtx);
    return;
  }
  z = sqlite3_malloc(p->nDigit + 4);
  if (z == 0) {
    sqlite3_result_error_nomem(pCtx);
    return;
  }
  i = 0;
  if (p->nDigit == 0 || (p->nDigit == 1 && p->a[0] == 0)) {
    p->sign = 0;
  }
  if (p->sign) {
    z[0] = '-';
    i = 1;
  }
  n = p->nDigit - p->nFrac;
  if (n <= 0) {
    z[i++] = '0';
  }
  j = 0;
  while (n > 1 && p->a[j] == 0) {
    j++;
    n--;
  }
  while (n > 0) {
    z[i++] = p->a[j] + '0';
    j++;
    n--;
  }
  if (p->nFrac) {
    z[i++] = '.';
    do {
      z[i++] = p->a[j] + '0';
      j++;
    } while (j < p->nDigit);
  }
  z[i] = 0;
  sqlite3_result_text(pCtx, z, i, sqlite3_free);
}
static void decimalFunc(sqlite3_context *context, int argc,
                        sqlite3_value **argv) {
  Decimal *p = decimal_new(context, argv[0], 0, 0);
  (void)(argc);
  decimal_result(context, p);
  decimal_free(p);
}
static int decimal_cmp(const Decimal *pA, const Decimal *pB) {
  int nASig, nBSig, rc, n;
  if (pA->sign != pB->sign) {
    return pA->sign ? -1 : +1;
  }
  if (pA->sign) {
    const Decimal *pTemp = pA;
    pA = pB;
    pB = pTemp;
  }
  nASig = pA->nDigit - pA->nFrac;
  nBSig = pB->nDigit - pB->nFrac;
  if (nASig != nBSig) {
    return nASig - nBSig;
  }
  n = pA->nDigit;
  if (n > pB->nDigit)
    n = pB->nDigit;
  rc = memcmp(pA->a, pB->a, n);
  if (rc == 0) {
    rc = pA->nDigit - pB->nDigit;
  }
  return rc;
}
static void decimalCmpFunc(sqlite3_context *context, int argc,
                           sqlite3_value **argv) {
  Decimal *pA = 0, *pB = 0;
  int rc;
  (void)(argc);
  pA = decimal_new(context, argv[0], 0, 0);
  if (pA == 0 || pA->isNull)
    goto cmp_done;
  pB = decimal_new(context, argv[1], 0, 0);
  if (pB == 0 || pB->isNull)
    goto cmp_done;
  rc = decimal_cmp(pA, pB);
  if (rc < 0)
    rc = -1;
  else if (rc > 0)
    rc = +1;
  sqlite3_result_int(context, rc);
cmp_done:
  decimal_free(pA);
  decimal_free(pB);
}
static void decimal_expand(Decimal *p, int nDigit, int nFrac) {
  int nAddSig;
  int nAddFrac;
  if (p == 0)
    return;
  nAddFrac = nFrac - p->nFrac;
  nAddSig = (nDigit - p->nDigit) - nAddFrac;
  if (nAddFrac == 0 && nAddSig == 0)
    return;
  p->a = sqlite3_realloc64(p->a, nDigit + 1);
  if (p->a == 0) {
    p->oom = 1;
    return;
  }
  if (nAddSig) {
    memmove(p->a + nAddSig, p->a, p->nDigit);
    memset(p->a, 0, nAddSig);
    p->nDigit += nAddSig;
  }
  if (nAddFrac) {
    memset(p->a + p->nDigit, 0, nAddFrac);
    p->nDigit += nAddFrac;
    p->nFrac += nAddFrac;
  }
}
static void decimal_add(Decimal *pA, Decimal *pB) {
  int nSig, nFrac, nDigit;
  int i, rc;
  if (pA == 0) {
    return;
  }
  if (pA->oom || pB == 0 || pB->oom) {
    pA->oom = 1;
    return;
  }
  if (pA->isNull || pB->isNull) {
    pA->isNull = 1;
    return;
  }
  nSig = pA->nDigit - pA->nFrac;
  if (nSig && pA->a[0] == 0)
    nSig--;
  if (nSig < pB->nDigit - pB->nFrac) {
    nSig = pB->nDigit - pB->nFrac;
  }
  nFrac = pA->nFrac;
  if (nFrac < pB->nFrac)
    nFrac = pB->nFrac;
  nDigit = nSig + nFrac + 1;
  decimal_expand(pA, nDigit, nFrac);
  decimal_expand(pB, nDigit, nFrac);
  if (pA->oom || pB->oom) {
    pA->oom = 1;
  } else {
    if (pA->sign == pB->sign) {
      int carry = 0;
      for (i = nDigit - 1; i >= 0; i--) {
        int x = pA->a[i] + pB->a[i] + carry;
        if (x >= 10) {
          carry = 1;
          pA->a[i] = x - 10;
        } else {
          carry = 0;
          pA->a[i] = x;
        }
      }
    } else {
      signed char *aA, *aB;
      int borrow = 0;
      rc = memcmp(pA->a, pB->a, nDigit);
      if (rc < 0) {
        aA = pB->a;
        aB = pA->a;
        pA->sign = !pA->sign;
      } else {
        aA = pA->a;
        aB = pB->a;
      }
      for (i = nDigit - 1; i >= 0; i--) {
        int x = aA[i] - aB[i] - borrow;
        if (x < 0) {
          pA->a[i] = x + 10;
          borrow = 1;
        } else {
          pA->a[i] = x;
          borrow = 0;
        }
      }
    }
  }
}
static int decimalCollFunc(void *notUsed, int nKey1, const void *pKey1,
                           int nKey2, const void *pKey2) {
  const unsigned char *zA = (const unsigned char *)pKey1;
  const unsigned char *zB = (const unsigned char *)pKey2;
  Decimal *pA = decimal_new(0, 0, nKey1, zA);
  Decimal *pB = decimal_new(0, 0, nKey2, zB);
  int rc;
  (void)(notUsed);
  if (pA == 0 || pB == 0) {
    rc = 0;
  } else {
    rc = decimal_cmp(pA, pB);
  }
  decimal_free(pA);
  decimal_free(pB);
  return rc;
}
static void decimalAddFunc(sqlite3_context *context, int argc,
                           sqlite3_value **argv) {
  Decimal *pA = decimal_new(context, argv[0], 0, 0);
  Decimal *pB = decimal_new(context, argv[1], 0, 0);
  (void)(argc);
  decimal_add(pA, pB);
  decimal_result(context, pA);
  decimal_free(pA);
  decimal_free(pB);
}
static void decimalSubFunc(sqlite3_context *context, int argc,
                           sqlite3_value **argv) {
  Decimal *pA = decimal_new(context, argv[0], 0, 0);
  Decimal *pB = decimal_new(context, argv[1], 0, 0);
  (void)(argc);
  if (pB) {
    pB->sign = !pB->sign;
    decimal_add(pA, pB);
    decimal_result(context, pA);
  }
  decimal_free(pA);
  decimal_free(pB);
}
static void decimalSumStep(sqlite3_context *context, int argc,
                           sqlite3_value **argv) {
  Decimal *p;
  Decimal *pArg;
  (void)(argc);
  p = sqlite3_aggregate_context(context, sizeof(*p));
  if (p == 0)
    return;
  if (!p->isInit) {
    p->isInit = 1;
    p->a = sqlite3_malloc(2);
    if (p->a == 0) {
      p->oom = 1;
    } else {
      p->a[0] = 0;
    }
    p->nDigit = 1;
    p->nFrac = 0;
  }
  if (sqlite3_value_type(argv[0]) == 5)
    return;
  pArg = decimal_new(context, argv[0], 0, 0);
  decimal_add(p, pArg);
  decimal_free(pArg);
}
static void decimalSumInverse(sqlite3_context *context, int argc,
                              sqlite3_value **argv) {
  Decimal *p;
  Decimal *pArg;
  (void)(argc);
  p = sqlite3_aggregate_context(context, sizeof(*p));
  if (p == 0)
    return;
  if (sqlite3_value_type(argv[0]) == 5)
    return;
  pArg = decimal_new(context, argv[0], 0, 0);
  if (pArg)
    pArg->sign = !pArg->sign;
  decimal_add(p, pArg);
  decimal_free(pArg);
}
static void decimalSumValue(sqlite3_context *context) {
  Decimal *p = sqlite3_aggregate_context(context, 0);
  if (p == 0)
    return;
  decimal_result(context, p);
}
static void decimalSumFinalize(sqlite3_context *context) {
  Decimal *p = sqlite3_aggregate_context(context, 0);
  if (p == 0)
    return;
  decimal_result(context, p);
  decimal_clear(p);
}
static void decimalMulFunc(sqlite3_context *context, int argc,
                           sqlite3_value **argv) {
  Decimal *pA = decimal_new(context, argv[0], 0, 0);
  Decimal *pB = decimal_new(context, argv[1], 0, 0);
  signed char *acc = 0;
  int i, j, k;
  int minFrac;
  (void)(argc);
  if (pA == 0 || pA->oom || pA->isNull || pB == 0 || pB->oom || pB->isNull) {
    goto mul_end;
  }
  acc = sqlite3_malloc64(pA->nDigit + pB->nDigit + 2);
  if (acc == 0) {
    sqlite3_result_error_nomem(context);
    goto mul_end;
  }
  memset(acc, 0, pA->nDigit + pB->nDigit + 2);
  minFrac = pA->nFrac;
  if (pB->nFrac < minFrac)
    minFrac = pB->nFrac;
  for (i = pA->nDigit - 1; i >= 0; i--) {
    signed char f = pA->a[i];
    int carry = 0, x;
    for (j = pB->nDigit - 1, k = i + j + 3; j >= 0; j--, k--) {
      x = acc[k] + f * pB->a[j] + carry;
      acc[k] = x % 10;
      carry = x / 10;
    }
    x = acc[k] + carry;
    acc[k] = x % 10;
    acc[k - 1] += x / 10;
  }
  sqlite3_free(pA->a);
  pA->a = acc;
  acc = 0;
  pA->nDigit += pB->nDigit + 2;
  pA->nFrac += pB->nFrac;
  pA->sign ^= pB->sign;
  while (pA->nFrac > minFrac && pA->a[pA->nDigit - 1] == 0) {
    pA->nFrac--;
    pA->nDigit--;
  }
  decimal_result(context, pA);
mul_end:
  sqlite3_free(acc);
  decimal_free(pA);
  decimal_free(pB);
}
int sqlite3_decimal_init(sqlite3 *db, char **pzErrMsg,
                         const sqlite3_api_routines *pApi) {
  int rc = 0;
  static const struct {
    const char *zFuncName;
    int nArg;
    void (*xFunc)(sqlite3_context *, int, sqlite3_value **);
  } aFunc[] = {{"decimal", 1, decimalFunc},
               {"decimal_cmp", 2, decimalCmpFunc},
               {"decimal_add", 2, decimalAddFunc},
               {"decimal_sub", 2, decimalSubFunc},
               {"decimal_mul", 2, decimalMulFunc}};
  unsigned int i;
  (void)pzErrMsg;
  (void)(pApi);
  for (i = 0; i < (int)(sizeof(aFunc) / sizeof(aFunc[0])) && rc == 0; i++) {
    rc = sqlite3_create_function(db, aFunc[i].zFuncName, aFunc[i].nArg,
                                 1 | 2097152 | 2048, 0, aFunc[i].xFunc, 0, 0);
  }
  if (rc == 0) {
    rc = sqlite3_create_window_function(
        db, "decimal_sum", 1, 1 | 2097152 | 2048, 0, decimalSumStep,
        decimalSumFinalize, decimalSumValue, decimalSumInverse, 0);
  }
  if (rc == 0) {
    rc = sqlite3_create_collation(db, "decimal", 1, 0, decimalCollFunc);
  }
  return rc;
};
static const u8 b64DigitValues[128] = {
    130, 130, 130, 130, 130, 130, 130, 130, 130, 129, 129, 129, 129, 129, 130,
    130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130,
    130, 130, 129, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 62,  130,
    130, 130, 63,  52,  53,  54,  55,  56,  57,  58,  59,  60,  61,  130, 130,
    130, 128, 130, 130, 130, 0,   1,   2,   3,   4,   5,   6,   7,   8,   9,
    10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20,  21,  22,  23,  24,
    25,  130, 130, 130, 130, 130, 130, 26,  27,  28,  29,  30,  31,  32,  33,
    34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47,  48,
    49,  50,  51,  130, 130, 130, 130, 130};
static const char b64Numerals[64 + 1] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static char *toBase64(u8 *pIn, int nbIn, char *pOut) {
  int nCol = 0;
  while (nbIn >= 3) {
    pOut[0] = (b64Numerals[(u8)(pIn[0] >> 2)]);
    pOut[1] = (b64Numerals[(u8)(((pIn[0] << 4) | (pIn[1] >> 4)) & 63)]);
    pOut[2] = (b64Numerals[(u8)(((pIn[1] & 15) << 2) | (pIn[2] >> 6))]);
    pOut[3] = (b64Numerals[(u8)(pIn[2] & 63)]);
    pOut += 4;
    nbIn -= 3;
    pIn += 3;
    if ((nCol += 4) >= 72 || nbIn <= 0) {
      *pOut++ = '\n';
      nCol = 0;
    }
  }
  if (nbIn > 0) {
    signed char nco = nbIn + 1;
    int nbe;
    unsigned long qv = *pIn++;
    for (nbe = 1; nbe < 3; ++nbe) {
      qv <<= 8;
      if (nbe < nbIn)
        qv |= *pIn++;
    }
    for (nbe = 3; nbe >= 0; --nbe) {
      char ce = (nbe < nco) ? (b64Numerals[(u8)((u8)(qv & 63))]) : '=';
      qv >>= 6;
      pOut[nbe] = ce;
    }
    pOut += 4;
    *pOut++ = '\n';
  }
  *pOut = 0;
  return pOut;
}
static char *skipNonB64(char *s, int nc) {
  char c;
  while (nc-- > 0 && (c = *s) &&
         !(((u8)(((((u8)(c)) < 128) ? (u8)(b64DigitValues[(u8)(c)]) : 128))) <
           128))
    ++s;
  return s;
}
static u8 *fromBase64(char *pIn, int ncIn, u8 *pOut) {
  if (ncIn > 0 && pIn[ncIn - 1] == '\n')
    --ncIn;
  while (ncIn > 0 && *pIn != '=') {
    static signed char nboi[] = {0, 0, 1, 2, 3};
    char *pUse = skipNonB64(pIn, ncIn);
    unsigned long qv = 0;
    int nti, nbo, nac;
    ncIn -= (pUse - pIn);
    pIn = pUse;
    nti = (ncIn > 4) ? 4 : ncIn;
    ncIn -= nti;
    nbo = nboi[nti];
    if (nbo == 0)
      break;
    for (nac = 0; nac < 4; ++nac) {
      char c = (nac < nti) ? *pIn++ : b64Numerals[0];
      u8 bdp = ((((u8)(c)) < 128) ? (u8)(b64DigitValues[(u8)(c)]) : 128);
      switch (bdp) {
      case 130:
        ncIn = 0;
        ;
      case 129:
        nti = nac;
        ;
      case 128:
        bdp = 0;
        --nbo;
        ;
      default:
        qv = qv << 6 | bdp;
        break;
      }
    }
    switch (nbo) {
    case 3:
      pOut[2] = (qv)&255;
    case 2:
      pOut[1] = (qv >> 8) & 255;
    case 1:
      pOut[0] = (qv >> 16) & 255;
    }
    pOut += nbo;
  }
  return pOut;
}
static void base64(sqlite3_context *context, int na, sqlite3_value *av[]) {
  int nb, nc, nv = sqlite3_value_bytes(av[0]);
  int nvMax = sqlite3_limit(sqlite3_context_db_handle(context), 0, -1);
  char *cBuf;
  u8 *bBuf;
  ((void)sizeof((na == 1) ? 1 : 0), ({
     if (na == 1)
       ;
     else
       __assert_fail("na==1", "shell.c", 3483, __PRETTY_FUNCTION__);
   }));
  switch (sqlite3_value_type(av[0])) {
  case 4:
    nb = nv;
    nc = 4 * (nv + 2 / 3);
    nc += (nc + (72 - 1)) / 72 + 1;
    if (nvMax < nc) {
      sqlite3_result_error(context, "blob expanded to base64 too big", -1);
      return;
    }
    bBuf = (u8 *)sqlite3_value_blob(av[0]);
    if (!bBuf) {
      if (7 == sqlite3_errcode(sqlite3_context_db_handle(context))) {
        goto memFail;
      }
      sqlite3_result_text(context, "", -1, ((sqlite3_destructor_type)0));
      break;
    }
    cBuf = sqlite3_malloc(nc);
    if (!cBuf)
      goto memFail;
    nc = (int)(toBase64(bBuf, nb, cBuf) - cBuf);
    sqlite3_result_text(context, cBuf, nc, sqlite3_free);
    break;
  case 3:
    nc = nv;
    nb = 3 * ((nv + 3) / 4);
    if (nvMax < nb) {
      sqlite3_result_error(context, "blob from base64 may be too big", -1);
      return;
    } else if (nb < 1) {
      nb = 1;
    }
    cBuf = (char *)sqlite3_value_text(av[0]);
    if (!cBuf) {
      if (7 == sqlite3_errcode(sqlite3_context_db_handle(context))) {
        goto memFail;
      }
      sqlite3_result_zeroblob(context, 0);
      break;
    }
    bBuf = sqlite3_malloc(nb);
    if (!bBuf)
      goto memFail;
    nb = (int)(fromBase64(cBuf, nc, bBuf) - bBuf);
    sqlite3_result_blob(context, bBuf, nb, sqlite3_free);
    break;
  default:
    sqlite3_result_error(context, "base64 accepts only blob or text", -1);
    return;
  }
  return;
memFail:
  sqlite3_result_error(context, "base64 OOM", -1);
}
int sqlite3_base64_init(sqlite3 *db, char **pzErr,
                        const sqlite3_api_routines *pApi) {
  (void)(pApi);
  (void)pzErr;
  return sqlite3_create_function(db, "base64", 1, 2048 | 2097152 | 524288 | 1,
                                 0, base64, 0, 0);
};
static char *skipNonB85(char *s, int nc) {
  char c;
  while (nc-- > 0 && (c = *s) &&
    ++s;
  return s;
}
static char *putcs(char *pc, char *s) {
  char c;
  while ((c = *s++) != 0)
    *pc++ = c;
  return pc;
}
static char *toBase85(u8 *pIn, int nbIn, char *pOut, char *pSep) {
  int nCol = 0;
  while (nbIn >= 4) {
    int nco = 5;
    unsigned long qbv = (((unsigned long)pIn[0]) << 24) | (pIn[1] << 16) |
                        (pIn[2] << 8) | pIn[3];
    while (nco > 0) {
      unsigned nqv = (unsigned)(qbv / 85);
      unsigned char dv = qbv - 85 * nqv;
      qbv = nqv;
      pOut[--nco] =
    }
    nbIn -= 4;
    pIn += 4;
    pOut += 5;
    if (pSep && (nCol += 5) >= 80) {
      pOut = putcs(pOut, pSep);
      nCol = 0;
    }
  }
  if (nbIn > 0) {
    int nco = nbIn + 1;
    unsigned long qv = *pIn++;
    int nbe = 1;
    while (nbe++ < nbIn) {
      qv = (qv << 8) | *pIn++;
    }
    nCol += nco;
    while (nco > 0) {
      u8 dv = (u8)(qv % 85);
      qv /= 85;
      pOut[--nco] =
    }
    pOut += (nbIn + 1);
  }
  if (pSep && nCol > 0)
    pOut = putcs(pOut, pSep);
  *pOut = 0;
  return pOut;
}
static u8 *fromBase85(char *pIn, int ncIn, u8 *pOut) {
  if (ncIn > 0 && pIn[ncIn - 1] == '\n')
    --ncIn;
  while (ncIn > 0) {
    static signed char nboi[] = {0, 0, 1, 2, 3, 4};
    char *pUse = skipNonB85(pIn, ncIn);
    unsigned long qv = 0;
    int nti, nbo;
    ncIn -= (pUse - pIn);
    pIn = pUse;
    nti = (ncIn > 5) ? 5 : ncIn;
    nbo = nboi[nti];
    if (nbo == 0)
      break;
    while (nti > 0) {
      char c = *pIn++;
                            ((c) > 'z'))];
      --ncIn;
      if (cdo == 0)
        break;
      qv = 85 * qv + (c - cdo);
      --nti;
    }
    nbo -= nti;
    switch (nbo) {
    case 4:
      *pOut++ = (qv >> 24) & 255;
    case 3:
      *pOut++ = (qv >> 16) & 255;
    case 2:
      *pOut++ = (qv >> 8) & 255;
    case 1:
      *pOut++ = qv & 255;
    case 0:
      break;
    }
  }
  return pOut;
}
static void base85(sqlite3_context *context, int na, sqlite3_value *av[]) {
  int nb, nc, nv = sqlite3_value_bytes(av[0]);
  int nvMax = sqlite3_limit(sqlite3_context_db_handle(context), 0, -1);
  char *cBuf;
  u8 *bBuf;
  ((void)sizeof((na == 1) ? 1 : 0), ({
     if (na == 1)
       ;
     else
       __assert_fail("na==1", "shell.c", 3859, __PRETTY_FUNCTION__);
   }));
  switch (sqlite3_value_type(av[0])) {
  case 4:
    nb = nv;
    nc = 5 * (nv / 4) + nv % 4 + nv / 64 + 1 + 2;
    if (nvMax < nc) {
      sqlite3_result_error(context, "blob expanded to base85 too big", -1);
      return;
    }
    bBuf = (u8 *)sqlite3_value_blob(av[0]);
    if (!bBuf) {
      if (7 == sqlite3_errcode(sqlite3_context_db_handle(context))) {
        goto memFail;
      }
      sqlite3_result_text(context, "", -1, ((sqlite3_destructor_type)0));
      break;
    }
    cBuf = sqlite3_malloc(nc);
    if (!cBuf)
      goto memFail;
    nc = (int)(toBase85(bBuf, nb, cBuf, "\n") - cBuf);
    sqlite3_result_text(context, cBuf, nc, sqlite3_free);
    break;
  case 3:
    nc = nv;
    nb = 4 * (nv / 5) + nv % 5;
    if (nvMax < nb) {
      sqlite3_result_error(context, "blob from base85 may be too big", -1);
      return;
    } else if (nb < 1) {
      nb = 1;
    }
    cBuf = (char *)sqlite3_value_text(av[0]);
    if (!cBuf) {
      if (7 == sqlite3_errcode(sqlite3_context_db_handle(context))) {
        goto memFail;
      }
      sqlite3_result_zeroblob(context, 0);
      break;
    }
    bBuf = sqlite3_malloc(nb);
    if (!bBuf)
      goto memFail;
    nb = (int)(fromBase85(cBuf, nc, bBuf) - bBuf);
    sqlite3_result_blob(context, bBuf, nb, sqlite3_free);
    break;
  default:
    sqlite3_result_error(context, "base85 accepts only blob or text.", -1);
    return;
  }
  return;
memFail:
  sqlite3_result_error(context, "base85 OOM", -1);
}
int sqlite3_base85_init(sqlite3 *db, char **pzErr,
                        const sqlite3_api_routines *pApi) {
  (void)(pApi);
  (void)pzErr;
  return sqlite3_create_function(db, "base85", 1, 2048 | 2097152 | 524288 | 1,
                                 0, base85, 0, 0);
}
static void ieee754func(sqlite3_context *context, int argc,
                        sqlite3_value **argv) {
  if (argc == 1) {
    sqlite3_int64 m, a;
    double r;
    int e;
    int isNeg;
    char zResult[100];
    ((void)sizeof((sizeof(m) == sizeof(r)) ? 1 : 0), ({
       if (sizeof(m) == sizeof(r))
         ;
       else
         __assert_fail("sizeof(m)==sizeof(r)", "shell.c", 4135,
                       __PRETTY_FUNCTION__);
     }));
    if (sqlite3_value_type(argv[0]) == 4 &&
        sqlite3_value_bytes(argv[0]) == sizeof(r)) {
      const unsigned char *x = sqlite3_value_blob(argv[0]);
      unsigned int i;
      sqlite3_uint64 v = 0;
      for (i = 0; i < sizeof(r); i++) {
        v = (v << 8) | x[i];
      }
      memcpy(&r, &v, sizeof(r));
    } else {
      r = sqlite3_value_double(argv[0]);
    }
    if (r < 0.000000) {
      isNeg = 1;
      r = -r;
    } else {
      isNeg = 0;
    }
    memcpy(&a, &r, sizeof(a));
    if (a == 0) {
      e = 0;
      m = 0;
    } else {
      e = a >> 52;
      m = a & ((((sqlite3_int64)1) << 52) - 1);
      if (e == 0) {
        m <<= 1;
      } else {
        m |= ((sqlite3_int64)1) << 52;
      }
      while (e < 1075 && m > 0 && (m & 1) == 0) {
        m >>= 1;
        e++;
      }
      if (isNeg)
        m = -m;
    }
    switch (*(int *)sqlite3_user_data(context)) {
    case 0:
      sqlite3_snprintf(sizeof(zResult), zResult, "ieee754(%lld,%d)", m,
                       e - 1075);
      sqlite3_result_text(context, zResult, -1, ((sqlite3_destructor_type)-1));
      break;
    case 1:
      sqlite3_result_int64(context, m);
      break;
    case 2:
      sqlite3_result_int(context, e - 1075);
      break;
    }
  } else {
    sqlite3_int64 m, e, a;
    double r;
    int isNeg = 0;
    m = sqlite3_value_int64(argv[0]);
    e = sqlite3_value_int64(argv[1]);
    if (e > 10000) {
      e = 10000;
    } else if (e < -10000) {
      e = -10000;
    }
    if (m < 0) {
      isNeg = 1;
      m = -m;
      if (m < 0)
        return;
    } else if (m == 0 && e > -1000 && e < 1000) {
      sqlite3_result_double(context, 0.000000);
      return;
    }
    while ((m >> 32) & 4292870144) {
      m >>= 1;
      e++;
    }
    while (m != 0 && ((m >> 32) & 4293918720) == 0) {
      m <<= 1;
      e--;
    }
    e += 1075;
    if (e <= 0) {
      if (1 - e >= 64) {
        m = 0;
      } else {
        m >>= 1 - e;
      }
      e = 0;
    } else if (e > 2047) {
      e = 2047;
    }
    a = m & ((((sqlite3_int64)1) << 52) - 1);
    a |= e << 52;
    if (isNeg)
      a |= ((sqlite3_uint64)1) << 63;
    memcpy(&r, &a, sizeof(r));
    sqlite3_result_double(context, r);
  }
}
static void ieee754func_from_blob(sqlite3_context *context, int argc,
                                  sqlite3_value **argv) {
  (void)(argc);
  if (sqlite3_value_type(argv[0]) == 4 &&
      sqlite3_value_bytes(argv[0]) == sizeof(double)) {
    double r;
    const unsigned char *x = sqlite3_value_blob(argv[0]);
    unsigned int i;
    sqlite3_uint64 v = 0;
    for (i = 0; i < sizeof(r); i++) {
      v = (v << 8) | x[i];
    }
    memcpy(&r, &v, sizeof(r));
    sqlite3_result_double(context, r);
  }
}
static void ieee754func_to_blob(sqlite3_context *context, int argc,
                                sqlite3_value **argv) {
  (void)(argc);
  if (sqlite3_value_type(argv[0]) == 2 || sqlite3_value_type(argv[0]) == 1) {
    double r = sqlite3_value_double(argv[0]);
    sqlite3_uint64 v;
    unsigned char a[sizeof(r)];
    unsigned int i;
    memcpy(&v, &r, sizeof(r));
    for (i = 1; i <= sizeof(r); i++) {
      a[sizeof(r) - i] = v & 255;
      v >>= 8;
    }
    sqlite3_result_blob(context, a, sizeof(r), ((sqlite3_destructor_type)-1));
  }
}
int sqlite3_ieee_init(sqlite3 *db, char **pzErrMsg,
                      const sqlite3_api_routines *pApi) {
  static const struct {
    char *zFName;
    int nArg;
    int iAux;
    void (*xFunc)(sqlite3_context *, int, sqlite3_value **);
  } aFunc[] = {{"ieee754", 1, 0, ieee754func},
               {"ieee754", 2, 0, ieee754func},
               {"ieee754_mantissa", 1, 1, ieee754func},
               {"ieee754_exponent", 1, 2, ieee754func},
               {"ieee754_to_blob", 1, 0, ieee754func_to_blob},
               {"ieee754_from_blob", 1, 0, ieee754func_from_blob}};
  unsigned int i;
  int rc = 0;
  (void)(pApi);
  (void)pzErrMsg;
  for (i = 0; i < sizeof(aFunc) / sizeof(aFunc[0]) && rc == 0; i++) {
    rc =
        sqlite3_create_function(db, aFunc[i].zFName, aFunc[i].nArg, 1 | 2097152,
                                (void *)&aFunc[i].iAux, aFunc[i].xFunc, 0, 0);
  }
  return rc;
}
static sqlite3_int64 genSeqMember(sqlite3_int64 smBase, sqlite3_int64 smStep,
                                  sqlite3_uint64 ix) {
  if (ix >= (sqlite3_uint64)9223372036854775807) {
    ix -= (sqlite3_uint64)9223372036854775807;
    smBase += (9223372036854775807 / 2) * smStep;
    smBase += (9223372036854775807 - 9223372036854775807 / 2) * smStep;
  }
  if (ix >= 2) {
    sqlite3_int64 ix2 = (sqlite3_int64)ix / 2;
    smBase += ix2 * smStep;
    ix -= ix2;
  }
  return smBase + ((sqlite3_int64)ix) * smStep;
}
typedef struct SequenceSpec {
  sqlite3_int64 iBase;
  sqlite3_int64 iTerm;
  sqlite3_int64 iStep;
  sqlite3_uint64 uSeqIndexMax;
  sqlite3_uint64 uSeqIndexNow;
  sqlite3_int64 iValueNow;
  u8 isNotEOF;
  u8 isReversing;
} SequenceSpec;
static void setupSequence(SequenceSpec *pss) {
  int bSameSigns;
  pss->uSeqIndexMax = 0;
  pss->isNotEOF = 0;
  bSameSigns = (pss->iBase < 0) == (pss->iTerm < 0);
  if (pss->iTerm < pss->iBase) {
    sqlite3_uint64 nuspan = 0;
    if (bSameSigns) {
      nuspan = (sqlite3_uint64)(pss->iBase - pss->iTerm);
    } else {
      nuspan = 1;
      nuspan += pss->iBase;
      nuspan += -(pss->iTerm + 1);
    }
    if (pss->iStep < 0) {
      pss->isNotEOF = 1;
      if (nuspan == (9223372036854775807 * 2 + 1)) {
        pss->uSeqIndexMax = (pss->iStep > (-9223372036854775807 - 1))
                                ? nuspan / -pss->iStep
                                : 1;
      } else if (pss->iStep > (-9223372036854775807 - 1)) {
        pss->uSeqIndexMax = nuspan / -pss->iStep;
      }
    }
  } else if (pss->iTerm > pss->iBase) {
    sqlite3_uint64 puspan = 0;
    if (bSameSigns) {
      puspan = (sqlite3_uint64)(pss->iTerm - pss->iBase);
    } else {
      puspan = 1;
      puspan += pss->iTerm;
      puspan += -(pss->iBase + 1);
    }
    if (pss->iStep > 0) {
      pss->isNotEOF = 1;
      pss->uSeqIndexMax = puspan / pss->iStep;
    }
  } else if (pss->iTerm == pss->iBase) {
    pss->isNotEOF = 1;
    pss->uSeqIndexMax = 0;
  }
  pss->uSeqIndexNow = (pss->isReversing) ? pss->uSeqIndexMax : 0;
  pss->iValueNow = (pss->isReversing)
                       ? genSeqMember(pss->iBase, pss->iStep, pss->uSeqIndexMax)
                       : pss->iBase;
}
static int progressSequence(SequenceSpec *pss) {
  if (!pss->isNotEOF)
    return 0;
  if (pss->isReversing) {
    if (pss->uSeqIndexNow > 0) {
      pss->uSeqIndexNow--;
      pss->iValueNow -= pss->iStep;
    } else {
      pss->isNotEOF = 0;
    }
  } else {
    if (pss->uSeqIndexNow < pss->uSeqIndexMax) {
      pss->uSeqIndexNow++;
      pss->iValueNow += pss->iStep;
    } else {
      pss->isNotEOF = 0;
    }
  }
  return pss->isNotEOF;
}
typedef struct series_cursor series_cursor;
struct series_cursor {
  sqlite3_vtab_cursor base;
  SequenceSpec ss;
};
static int seriesConnect(sqlite3 *db, void *pUnused, int argcUnused,
                         const char *const *argvUnused, sqlite3_vtab **ppVtab,
                         char **pzErrUnused) {
  sqlite3_vtab *pNew;
  int rc;
  (void)pUnused;
  (void)argcUnused;
  (void)argvUnused;
  (void)pzErrUnused;
  rc = sqlite3_declare_vtab(
      db, "CREATE TABLE x(value,start hidden,stop hidden,step hidden)");
  if (rc == 0) {
    pNew = *ppVtab = sqlite3_malloc(sizeof(*pNew));
    if (pNew == 0)
      return 7;
    memset(pNew, 0, sizeof(*pNew));
    sqlite3_vtab_config(db, 2);
  }
  return rc;
}
static int seriesDisconnect(sqlite3_vtab *pVtab) {
  sqlite3_free(pVtab);
  return 0;
}
static int seriesOpen(sqlite3_vtab *pUnused, sqlite3_vtab_cursor **ppCursor) {
  series_cursor *pCur;
  (void)pUnused;
  pCur = sqlite3_malloc(sizeof(*pCur));
  if (pCur == 0)
    return 7;
  memset(pCur, 0, sizeof(*pCur));
  *ppCursor = &pCur->base;
  return 0;
}
static int seriesClose(sqlite3_vtab_cursor *cur) {
  sqlite3_free(cur);
  return 0;
}
static int seriesNext(sqlite3_vtab_cursor *cur) {
  series_cursor *pCur = (series_cursor *)cur;
  progressSequence(&pCur->ss);
  return 0;
}
static int seriesColumn(sqlite3_vtab_cursor *cur, sqlite3_context *ctx, int i) {
  series_cursor *pCur = (series_cursor *)cur;
  sqlite3_int64 x = 0;
  switch (i) {
  case 1:
    x = pCur->ss.iBase;
    break;
  case 2:
    x = pCur->ss.iTerm;
    break;
  case 3:
    x = pCur->ss.iStep;
    break;
  default:
    x = pCur->ss.iValueNow;
    break;
  }
  sqlite3_result_int64(ctx, x);
  return 0;
}
static int seriesRowid(sqlite3_vtab_cursor *cur, sqlite_int64 *pRowid) {
  series_cursor *pCur = (series_cursor *)cur;
  sqlite3_uint64 n = pCur->ss.uSeqIndexNow;
  *pRowid = (sqlite3_int64)((n < 18446744073709551615) ? n + 1 : 0);
  return 0;
}
static int seriesEof(sqlite3_vtab_cursor *cur) {
  series_cursor *pCur = (series_cursor *)cur;
  return !pCur->ss.isNotEOF;
}
static int seriesFilter(sqlite3_vtab_cursor *pVtabCursor, int idxNum,
                        const char *idxStrUnused, int argc,
                        sqlite3_value **argv) {
  series_cursor *pCur = (series_cursor *)pVtabCursor;
  int i = 0;
  (void)idxStrUnused;
  if (idxNum & 1) {
    pCur->ss.iBase = sqlite3_value_int64(argv[i++]);
  } else {
    pCur->ss.iBase = 0;
  }
  if (idxNum & 2) {
    pCur->ss.iTerm = sqlite3_value_int64(argv[i++]);
  } else {
    pCur->ss.iTerm = 4294967295;
  }
  if (idxNum & 4) {
    pCur->ss.iStep = sqlite3_value_int64(argv[i++]);
    if (pCur->ss.iStep == 0) {
      pCur->ss.iStep = 1;
    } else if (pCur->ss.iStep < 0) {
      if ((idxNum & 16) == 0)
        idxNum |= 8;
    }
  } else {
    pCur->ss.iStep = 1;
  }
  for (i = 0; i < argc; i++) {
    if (sqlite3_value_type(argv[i]) == 5) {
      pCur->ss.iBase = 1;
      pCur->ss.iTerm = 0;
      pCur->ss.iStep = 1;
      break;
    }
  }
  if (idxNum & 8) {
    pCur->ss.isReversing = pCur->ss.iStep > 0;
  } else {
    pCur->ss.isReversing = pCur->ss.iStep < 0;
  }
  setupSequence(&pCur->ss);
  return 0;
}
static int seriesBestIndex(sqlite3_vtab *pVTab, sqlite3_index_info *pIdxInfo) {
  int i, j;
  int idxNum = 0;
  int bStartSeen = 0;
  int unusableMask = 0;
  int nArg = 0;
  int aIdx[3];
  const struct sqlite3_index_constraint *pConstraint;
  ((void)sizeof((2 == 1 + 1) ? 1 : 0), ({
     if (2 == 1 + 1)
       ;
     else
       __assert_fail("SERIES_COLUMN_STOP == SERIES_COLUMN_START+1", "shell.c",
                     4778, __PRETTY_FUNCTION__);
   }));
  ((void)sizeof((3 == 1 + 2) ? 1 : 0), ({
     if (3 == 1 + 2)
       ;
     else
       __assert_fail("SERIES_COLUMN_STEP == SERIES_COLUMN_START+2", "shell.c",
                     4779, __PRETTY_FUNCTION__);
   }));
  aIdx[0] = aIdx[1] = aIdx[2] = -1;
  pConstraint = pIdxInfo->aConstraint;
  for (i = 0; i < pIdxInfo->nConstraint; i++, pConstraint++) {
    int iCol;
    int iMask;
    if (pConstraint->iColumn < 1)
      continue;
    iCol = pConstraint->iColumn - 1;
    ((void)sizeof((iCol >= 0 && iCol <= 2) ? 1 : 0), ({
       if (iCol >= 0 && iCol <= 2)
         ;
       else
         __assert_fail("iCol>=0 && iCol<=2", "shell.c", 4788,
                       __PRETTY_FUNCTION__);
     }));
    iMask = 1 << iCol;
    if (iCol == 0)
      bStartSeen = 1;
    if (pConstraint->usable == 0) {
      unusableMask |= iMask;
      continue;
    } else if (pConstraint->op == 2) {
      idxNum |= iMask;
      aIdx[iCol] = i;
    }
  }
  for (i = 0; i < 3; i++) {
    if ((j = aIdx[i]) >= 0) {
      pIdxInfo->aConstraintUsage[j].argvIndex = ++nArg;
      pIdxInfo->aConstraintUsage[j].omit = !0;
    }
  }
  if (!bStartSeen) {
    sqlite3_free(pVTab->zErrMsg);
    pVTab->zErrMsg = sqlite3_mprintf(
        "first argument to \"generate_series()\" missing or unusable");
    return 1;
  }
  if ((unusableMask & ~idxNum) != 0) {
    return 19;
  }
  if ((idxNum & 3) == 3) {
    pIdxInfo->estimatedCost = (double)(2 - ((idxNum & 4) != 0));
    pIdxInfo->estimatedRows = 1000;
    if (pIdxInfo->nOrderBy >= 1 && pIdxInfo->aOrderBy[0].iColumn == 0) {
      if (pIdxInfo->aOrderBy[0].desc) {
        idxNum |= 8;
      } else {
        idxNum |= 16;
      }
      pIdxInfo->orderByConsumed = 1;
    }
  } else {
    pIdxInfo->estimatedRows = 2147483647;
  }
  pIdxInfo->idxNum = idxNum;
  return 0;
}
static sqlite3_module seriesModule = {0,
                                      0,
                                      seriesConnect,
                                      seriesBestIndex,
                                      seriesDisconnect,
                                      0,
                                      seriesOpen,
                                      seriesClose,
                                      seriesFilter,
                                      seriesNext,
                                      seriesEof,
                                      seriesColumn,
                                      seriesRowid,
                                      0,
                                      0,
                                      0,
                                      0,
                                      0,
                                      0,
                                      0,
                                      0,
                                      0,
                                      0,
                                      0};
int sqlite3_series_init(sqlite3 *db, char **pzErrMsg,
                        const sqlite3_api_routines *pApi) {
  int rc = 0;
  (void)(pApi);
  if (sqlite3_libversion_number() < 3008012 && pzErrMsg != 0) {
    *pzErrMsg =
        sqlite3_mprintf("generate_series() requires SQLite 3.8.12 or later");
    return 1;
  }
  rc = sqlite3_create_module(db, "generate_series", &seriesModule, 0);
  return rc;
}
typedef unsigned short ReStateNumber;
typedef struct ReStateSet {
  unsigned nState;
  ReStateNumber *aState;
} ReStateSet;
typedef struct ReInput ReInput;
struct ReInput {
  const unsigned char *z;
  int i;
  int mx;
};
typedef struct ReCompiled ReCompiled;
struct ReCompiled {
  ReInput sIn;
  const char *zErr;
  char *aOp;
  int *aArg;
  unsigned (*xNextChar)(ReInput *);
  unsigned char zInit[12];
  int nInit;
  unsigned nState;
  unsigned nAlloc;
};
static void re_add_state(ReStateSet *pSet, int newState) {
  unsigned i;
  for (i = 0; i < pSet->nState; i++)
    if (pSet->aState[i] == newState)
      return;
  pSet->aState[pSet->nState++] = (ReStateNumber)newState;
}
static unsigned re_next_char(ReInput *p) {
  unsigned c;
  if (p->i >= p->mx)
    return 0;
  c = p->z[p->i++];
  if (c >= 128) {
    if ((c & 224) == 192 && p->i < p->mx && (p->z[p->i] & 192) == 128) {
      c = (c & 31) << 6 | (p->z[p->i++] & 63);
      if (c < 128)
        c = 65533;
    } else if ((c & 240) == 224 && p->i + 1 < p->mx &&
               (p->z[p->i] & 192) == 128 && (p->z[p->i + 1] & 192) == 128) {
      c = (c & 15) << 12 | ((p->z[p->i] & 63) << 6) | (p->z[p->i + 1] & 63);
      p->i += 2;
      if (c <= 2047 || (c >= 55296 && c <= 57343))
        c = 65533;
    } else if ((c & 248) == 240 && p->i + 2 < p->mx &&
               (p->z[p->i] & 192) == 128 && (p->z[p->i + 1] & 192) == 128 &&
               (p->z[p->i + 2] & 192) == 128) {
      c = (c & 7) << 18 | ((p->z[p->i] & 63) << 12) |
          ((p->z[p->i + 1] & 63) << 6) | (p->z[p->i + 2] & 63);
      p->i += 3;
      if (c <= 65535 || c > 1114111)
        c = 65533;
    } else {
      c = 65533;
    }
  }
  return c;
}
static unsigned re_next_char_nocase(ReInput *p) {
  unsigned c = re_next_char(p);
  if (c >= 'A' && c <= 'Z')
    c += 'a' - 'A';
  return c;
}
static int re_word_char(int c) {
  return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') ||
         (c >= 'A' && c <= 'Z') || c == '_';
}
static int re_digit_char(int c) { return (c >= '0' && c <= '9'); }
static int re_space_char(int c) {
  return c == ' ' || c == '\t' || c == '\n' || c == '\x0d' || c == 'A' ||
         c == 'A';
}
static int sqlite3re_match(ReCompiled *pRe, const unsigned char *zIn, int nIn) {
  ReStateSet aStateSet[2], *pThis, *pNext;
  ReStateNumber aSpace[100];
  ReStateNumber *pToFree;
  unsigned int i = 0;
  unsigned int iSwap = 0;
  int c = 268435455;
  int cPrev = 0;
  int rc = 0;
  ReInput in;
  in.z = zIn;
  in.i = 0;
  in.mx = nIn >= 0 ? nIn : (int)strlen((char const *)zIn);
  if (pRe->nInit) {
    unsigned char x = pRe->zInit[0];
    while (in.i + pRe->nInit <= in.mx &&
           (zIn[in.i] != x ||
            strncmp((const char *)zIn + in.i, (const char *)pRe->zInit,
                    pRe->nInit) != 0)) {
      in.i++;
    }
    if (in.i + pRe->nInit > in.mx)
      return 0;
    c = 268435455 - 1;
  }
  if (pRe->nState <= (sizeof(aSpace) / (sizeof(aSpace[0]) * 2))) {
    pToFree = 0;
    aStateSet[0].aState = aSpace;
  } else {
    pToFree = sqlite3_malloc64(sizeof(ReStateNumber) * 2 * pRe->nState);
    if (pToFree == 0)
      return -1;
    aStateSet[0].aState = pToFree;
  }
  aStateSet[1].aState = &aStateSet[0].aState[pRe->nState];
  pNext = &aStateSet[1];
  pNext->nState = 0;
  re_add_state(pNext, 0);
  while (c != 0 && pNext->nState > 0) {
    cPrev = c;
    c = pRe->xNextChar(&in);
    pThis = pNext;
    pNext = &aStateSet[iSwap];
    iSwap = 1 - iSwap;
    pNext->nState = 0;
    for (i = 0; i < pThis->nState; i++) {
      int x = pThis->aState[i];
      switch (pRe->aOp[x]) {
      case 1: {
        if (pRe->aArg[x] == c)
          re_add_state(pNext, x + 1);
        break;
      }
      case 18: {
        if (cPrev == 268435455)
          re_add_state(pThis, x + 1);
        break;
      }
      case 2: {
        if (c != 0)
          re_add_state(pNext, x + 1);
        break;
      }
      case 11: {
        if (re_word_char(c))
          re_add_state(pNext, x + 1);
        break;
      }
      case 12: {
        if (!re_word_char(c) && c != 0)
          re_add_state(pNext, x + 1);
        break;
      }
      case 13: {
        if (re_digit_char(c))
          re_add_state(pNext, x + 1);
        break;
      }
      case 14: {
        if (!re_digit_char(c) && c != 0)
          re_add_state(pNext, x + 1);
        break;
      }
      case 15: {
        if (re_space_char(c))
          re_add_state(pNext, x + 1);
        break;
      }
      case 16: {
        if (!re_space_char(c) && c != 0)
          re_add_state(pNext, x + 1);
        break;
      }
      case 17: {
        if (re_word_char(c) != re_word_char(cPrev))
          re_add_state(pThis, x + 1);
        break;
      }
      case 3: {
        re_add_state(pNext, x);
        re_add_state(pThis, x + 1);
        break;
      }
      case 4: {
        re_add_state(pThis, x + pRe->aArg[x]);
        re_add_state(pThis, x + 1);
        break;
      }
      case 5: {
        re_add_state(pThis, x + pRe->aArg[x]);
        break;
      }
      case 6: {
        rc = 1;
        goto re_match_end;
      }
      case 8: {
        if (c == 0)
          break;
        goto re_op_cc_inc;
      }
      case 7:
      re_op_cc_inc : {
        int j = 1;
        int n = pRe->aArg[x];
        int hit = 0;
        for (j = 1; j > 0 && j < n; j++) {
          if (pRe->aOp[x + j] == 9) {
            if (pRe->aArg[x + j] == c) {
              hit = 1;
              j = -1;
            }
          } else {
            if (pRe->aArg[x + j] <= c && pRe->aArg[x + j + 1] >= c) {
              hit = 1;
              j = -1;
            } else {
              j++;
            }
          }
        }
        if (pRe->aOp[x] == 8)
          hit = !hit;
        if (hit)
          re_add_state(pNext, x + n);
        break;
      }
      }
    }
  }
  for (i = 0; i < pNext->nState; i++) {
    int x = pNext->aState[i];
    while (pRe->aOp[x] == 5)
      x += pRe->aArg[x];
    if (pRe->aOp[x] == 6) {
      rc = 1;
      break;
    }
  }
re_match_end:
  sqlite3_free(pToFree);
  return rc;
}
static int re_resize(ReCompiled *p, int N) {
  char *aOp;
  int *aArg;
  aOp = sqlite3_realloc64(p->aOp, N * sizeof(p->aOp[0]));
  if (aOp == 0)
    return 1;
  p->aOp = aOp;
  aArg = sqlite3_realloc64(p->aArg, N * sizeof(p->aArg[0]));
  if (aArg == 0)
    return 1;
  p->aArg = aArg;
  p->nAlloc = N;
  return 0;
}
static int re_insert(ReCompiled *p, int iBefore, int op, int arg) {
  int i;
  if (p->nAlloc <= p->nState && re_resize(p, p->nAlloc * 2))
    return 0;
  for (i = p->nState; i > iBefore; i--) {
    p->aOp[i] = p->aOp[i - 1];
    p->aArg[i] = p->aArg[i - 1];
  }
  p->nState++;
  p->aOp[iBefore] = (char)op;
  p->aArg[iBefore] = arg;
  return iBefore;
}
static int re_append(ReCompiled *p, int op, int arg) {
  return re_insert(p, p->nState, op, arg);
}
static void re_copy(ReCompiled *p, int iStart, int N) {
  if (p->nState + N >= p->nAlloc && re_resize(p, p->nAlloc * 2 + N))
    return;
  memcpy(&p->aOp[p->nState], &p->aOp[iStart], N * sizeof(p->aOp[0]));
  memcpy(&p->aArg[p->nState], &p->aArg[iStart], N * sizeof(p->aArg[0]));
  p->nState += N;
}
static int re_hex(int c, int *pV) {
  if (c >= '0' && c <= '9') {
    c -= '0';
  } else if (c >= 'a' && c <= 'f') {
    c -= 'a' - 10;
  } else if (c >= 'A' && c <= 'F') {
    c -= 'A' - 10;
  } else {
    return 0;
  }
  *pV = (*pV) * 16 + (c & 255);
  return 1;
}
static unsigned re_esc_char(ReCompiled *p) {
  static const char zEsc[] = "afnrtv\\()*.+?[$^{|}]";
  static const char zTrans[] = "";
  int i, v = 0;
  char c;
  if (p->sIn.i >= p->sIn.mx)
    return 0;
  c = p->sIn.z[p->sIn.i];
  if (c == 'u' && p->sIn.i + 4 < p->sIn.mx) {
    const unsigned char *zIn = p->sIn.z + p->sIn.i;
    if (re_hex(zIn[1], &v) && re_hex(zIn[2], &v) && re_hex(zIn[3], &v) &&
        re_hex(zIn[4], &v)) {
      p->sIn.i += 5;
      return v;
    }
  }
  if (c == 'x' && p->sIn.i + 2 < p->sIn.mx) {
    const unsigned char *zIn = p->sIn.z + p->sIn.i;
    if (re_hex(zIn[1], &v) && re_hex(zIn[2], &v)) {
      p->sIn.i += 3;
      return v;
    }
  }
  for (i = 0; zEsc[i] && zEsc[i] != c; i++) {
  }
  if (zEsc[i]) {
    if (i < 6)
      c = zTrans[i];
    p->sIn.i++;
  } else {
    p->zErr = "unknown \\ escape";
  }
  return c;
}
static const char *re_subcompile_string(ReCompiled *);
static unsigned char rePeek(ReCompiled *p) {
  return p->sIn.i < p->sIn.mx ? p->sIn.z[p->sIn.i] : 0;
}
static const char *re_subcompile_re(ReCompiled *p) {
  const char *zErr;
  int iStart, iEnd, iGoto;
  iStart = p->nState;
  zErr = re_subcompile_string(p);
  if (zErr)
    return zErr;
  while (rePeek(p) == '|') {
    iEnd = p->nState;
    re_insert(p, iStart, 4, iEnd + 2 - iStart);
    iGoto = re_append(p, 5, 0);
    p->sIn.i++;
    zErr = re_subcompile_string(p);
    if (zErr)
      return zErr;
    p->aArg[iGoto] = p->nState - iGoto;
  }
  return 0;
}
static const char *re_subcompile_string(ReCompiled *p) {
  int iPrev = -1;
  int iStart;
  unsigned c;
  const char *zErr;
  while ((c = p->xNextChar(&p->sIn)) != 0) {
    iStart = p->nState;
    switch (c) {
    case '|':
    case ')': {
      p->sIn.i--;
      return 0;
    }
    case '(': {
      zErr = re_subcompile_re(p);
      if (zErr)
        return zErr;
      if (rePeek(p) != ')')
        return "unmatched '('";
      p->sIn.i++;
      break;
    }
    case '.': {
      if (rePeek(p) == '*') {
        re_append(p, 3, 0);
        p->sIn.i++;
      } else {
        re_append(p, 2, 0);
      }
      break;
    }
    case '*': {
      if (iPrev < 0)
        return "'*' without operand";
      re_insert(p, iPrev, 5, p->nState - iPrev + 1);
      re_append(p, 4, iPrev - p->nState + 1);
      break;
    }
    case '+': {
      if (iPrev < 0)
        return "'+' without operand";
      re_append(p, 4, iPrev - p->nState);
      break;
    }
    case '?': {
      if (iPrev < 0)
        return "'?' without operand";
      re_insert(p, iPrev, 4, p->nState - iPrev + 1);
      break;
    }
    case '$': {
      re_append(p, 1, 0);
      break;
    }
    case '^': {
      re_append(p, 18, 0);
      break;
    }
    case '{': {
      int m = 0, n = 0;
      int sz, j;
      if (iPrev < 0)
        return "'{m,n}' without operand";
      while ((c = rePeek(p)) >= '0' && c <= '9') {
        m = m * 10 + c - '0';
        p->sIn.i++;
      }
      n = m;
      if (c == ',') {
        p->sIn.i++;
        n = 0;
        while ((c = rePeek(p)) >= '0' && c <= '9') {
          n = n * 10 + c - '0';
          p->sIn.i++;
        }
      }
      if (c != '}')
        return "unmatched '{'";
      if (n > 0 && n < m)
        return "n less than m in '{m,n}'";
      p->sIn.i++;
      sz = p->nState - iPrev;
      if (m == 0) {
        if (n == 0)
          return "both m and n are zero in '{m,n}'";
        re_insert(p, iPrev, 4, sz + 1);
        iPrev++;
        n--;
      } else {
        for (j = 1; j < m; j++)
          re_copy(p, iPrev, sz);
      }
      for (j = m; j < n; j++) {
        re_append(p, 4, sz + 1);
        re_copy(p, iPrev, sz);
      }
      if (n == 0 && m > 0) {
        re_append(p, 4, -sz);
      }
      break;
    }
    case '[': {
      unsigned int iFirst = p->nState;
      if (rePeek(p) == '^') {
        re_append(p, 8, 0);
        p->sIn.i++;
      } else {
        re_append(p, 7, 0);
      }
      while ((c = p->xNextChar(&p->sIn)) != 0) {
        if (c == '[' && rePeek(p) == ':') {
          return "POSIX character classes not supported";
        }
        if (c == '\\')
          c = re_esc_char(p);
        if (rePeek(p) == '-') {
          re_append(p, 10, c);
          p->sIn.i++;
          c = p->xNextChar(&p->sIn);
          if (c == '\\')
            c = re_esc_char(p);
          re_append(p, 10, c);
        } else {
          re_append(p, 9, c);
        }
        if (rePeek(p) == ']') {
          p->sIn.i++;
          break;
        }
      }
      if (c == 0)
        return "unclosed '['";
      if (p->nState > iFirst)
        p->aArg[iFirst] = p->nState - iFirst;
      break;
    }
    case '\\': {
      int specialOp = 0;
      switch (rePeek(p)) {
      case 'b':
        specialOp = 17;
        break;
      case 'd':
        specialOp = 13;
        break;
      case 'D':
        specialOp = 14;
        break;
      case 's':
        specialOp = 15;
        break;
      case 'S':
        specialOp = 16;
        break;
      case 'w':
        specialOp = 11;
        break;
      case 'W':
        specialOp = 12;
        break;
      }
      if (specialOp) {
        p->sIn.i++;
        re_append(p, specialOp, 0);
      } else {
        c = re_esc_char(p);
        re_append(p, 1, c);
      }
      break;
    }
    default: {
      re_append(p, 1, c);
      break;
    }
    }
    iPrev = iStart;
  }
  return 0;
}
static void sqlite3re_free(ReCompiled *pRe) {
  if (pRe) {
    sqlite3_free(pRe->aOp);
    sqlite3_free(pRe->aArg);
    sqlite3_free(pRe);
  }
}
static const char *sqlite3re_compile(ReCompiled **ppRe, const char *zIn,
                                     int noCase) {
  ReCompiled *pRe;
  const char *zErr;
  int i, j;
  *ppRe = 0;
  pRe = sqlite3_malloc(sizeof(*pRe));
  if (pRe == 0) {
    return "out of memory";
  }
  memset(pRe, 0, sizeof(*pRe));
  pRe->xNextChar = noCase ? re_next_char_nocase : re_next_char;
  if (re_resize(pRe, 30)) {
    sqlite3re_free(pRe);
    return "out of memory";
  }
  if (zIn[0] == '^') {
    zIn++;
  } else {
    re_append(pRe, 3, 0);
  }
  pRe->sIn.z = (unsigned char *)zIn;
  pRe->sIn.i = 0;
  pRe->sIn.mx = (int)strlen(zIn);
  zErr = re_subcompile_re(pRe);
  if (zErr) {
    sqlite3re_free(pRe);
    return zErr;
  }
  if (pRe->sIn.i >= pRe->sIn.mx) {
    re_append(pRe, 6, 0);
    *ppRe = pRe;
  } else {
    sqlite3re_free(pRe);
    return "unrecognized character";
  }
  if (pRe->aOp[0] == 3 && !noCase) {
    for (j = 0, i = 1; j < (int)sizeof(pRe->zInit) - 2 && pRe->aOp[i] == 1;
         i++) {
      unsigned x = pRe->aArg[i];
      if (x <= 127) {
        pRe->zInit[j++] = (unsigned char)x;
      } else if (x <= 2047) {
        pRe->zInit[j++] = (unsigned char)(192 | (x >> 6));
        pRe->zInit[j++] = 128 | (x & 63);
      } else if (x <= 65535) {
        pRe->zInit[j++] = (unsigned char)(224 | (x >> 12));
        pRe->zInit[j++] = 128 | ((x >> 6) & 63);
        pRe->zInit[j++] = 128 | (x & 63);
      } else {
        break;
      }
    }
    if (j > 0 && pRe->zInit[j - 1] == 0)
      j--;
    pRe->nInit = j;
  }
  return pRe->zErr;
}
static void re_sql_func(sqlite3_context *context, int argc,
                        sqlite3_value **argv) {
  ReCompiled *pRe;
  const char *zPattern;
  const unsigned char *zStr;
  const char *zErr;
  int setAux = 0;
  (void)argc;
  pRe = sqlite3_get_auxdata(context, 0);
  if (pRe == 0) {
    zPattern = (const char *)sqlite3_value_text(argv[0]);
    if (zPattern == 0)
      return;
    zErr = sqlite3re_compile(&pRe, zPattern, sqlite3_user_data(context) != 0);
    if (zErr) {
      sqlite3re_free(pRe);
      sqlite3_result_error(context, zErr, -1);
      return;
    }
    if (pRe == 0) {
      sqlite3_result_error_nomem(context);
      return;
    }
    setAux = 1;
  }
  zStr = (const unsigned char *)sqlite3_value_text(argv[1]);
  if (zStr != 0) {
    sqlite3_result_int(context, sqlite3re_match(pRe, zStr, -1));
  }
  if (setAux) {
    sqlite3_set_auxdata(context, 0, pRe, (void (*)(void *))sqlite3re_free);
  }
}
int sqlite3_regexp_init(sqlite3 *db, char **pzErrMsg,
                        const sqlite3_api_routines *pApi) {
  int rc = 0;
  (void)(pApi);
  (void)pzErrMsg;
  rc = sqlite3_create_function(db, "regexp", 2, 1 | 2097152 | 2048, 0,
                               re_sql_func, 0, 0);
  if (rc == 0) {
    rc = sqlite3_create_function(db, "regexpi", 2, 1 | 2097152 | 2048,
                                 (void *)db, re_sql_func, 0, 0);
  }
  return rc;
}
struct flock {
  short int l_type;
  short int l_whence;
  __off_t l_start;
  __off_t l_len;
  __pid_t l_pid;
};
extern int fcntl(int __fd, int __cmd, ...);
extern int open(const char *__file, int __oflag, ...);
extern int openat(int __fd, const char *__file, int __oflag, ...);
extern int creat(const char *__file, mode_t __mode);
extern int posix_fadvise(int __fd, off_t __offset, off_t __len, int __advise);
extern int posix_fallocate(int __fd, off_t __offset, off_t __len);
struct utimbuf {
  __time_t actime;
  __time_t modtime;
};
extern int utime(const char *__file, const struct utimbuf *__file_times);
struct tm {
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
  long int tm_gmtoff;
  const char *tm_zone;
};
struct itimerspec {
  struct timespec it_interval;
  struct timespec it_value;
};
struct sigevent;
extern clock_t clock(void);
extern time_t time(time_t *__timer);
extern double difftime(time_t __time1, time_t __time0);
extern time_t mktime(struct tm *__tp);
extern size_t strftime(char *__s, size_t __maxsize, const char *__format,
                       const struct tm *__tp);
extern size_t strftime_l(char *__s, size_t __maxsize, const char *__format,
                         const struct tm *__tp, locale_t __loc);
extern struct tm *gmtime(const time_t *__timer);
extern struct tm *localtime(const time_t *__timer);
extern struct tm *gmtime_r(const time_t *__timer, struct tm *__tp);
extern struct tm *localtime_r(const time_t *__timer, struct tm *__tp);
extern char *asctime(const struct tm *__tp);
extern char *ctime(const time_t *__timer);
extern char *asctime_r(const struct tm *__tp, char *__buf);
extern char *ctime_r(const time_t *__timer, char *__buf);
extern char *__tzname[2];
extern int __daylight;
extern long int __timezone;
extern char *tzname[2];
extern void tzset(void);
extern int daylight;
extern long int timezone;
extern time_t timegm(struct tm *__tp);
extern time_t timelocal(struct tm *__tp);
extern int dysize(int __year);
extern int nanosleep(const struct timespec *__requested_time,
                     struct timespec *__remaining);
extern int clock_getres(clockid_t __clock_id, struct timespec *__res);
extern int clock_gettime(clockid_t __clock_id, struct timespec *__tp);
extern int clock_settime(clockid_t __clock_id, const struct timespec *__tp);
extern int clock_nanosleep(clockid_t __clock_id, int __flags,
                           const struct timespec *__req,
                           struct timespec *__rem);
extern int clock_getcpuclockid(pid_t __pid, clockid_t *__clock_id);
extern int timer_create(clockid_t __clock_id, struct sigevent *__evp,
                        timer_t *__timerid);
extern int timer_delete(timer_t __timerid);
extern int timer_settime(timer_t __timerid, int __flags,
                         const struct itimerspec *__value,
                         struct itimerspec *__ovalue);
extern int timer_gettime(timer_t __timerid, struct itimerspec *__value);
extern int timer_getoverrun(timer_t __timerid);
extern int timespec_get(struct timespec *__ts, int __base);
extern int *__errno_location(void);
static void readFileContents(sqlite3_context *ctx, const char *zName) {
  FILE *in;
  sqlite3_int64 nIn;
  void *pBuf;
  sqlite3 *db;
  int mxBlob;
  in = fopen(zName, "rb");
  if (in == 0) {
    return;
  }
  fseek(in, 0, 2);
  nIn = ftell(in);
  rewind(in);
  db = sqlite3_context_db_handle(ctx);
  mxBlob = sqlite3_limit(db, 0, -1);
  if (nIn > mxBlob) {
    sqlite3_result_error_code(ctx, 18);
    fclose(in);
    return;
  }
  pBuf = sqlite3_malloc64(nIn ? nIn : 1);
  if (pBuf == 0) {
    sqlite3_result_error_nomem(ctx);
    fclose(in);
    return;
  }
  if (nIn == (sqlite3_int64)fread(pBuf, 1, (size_t)nIn, in)) {
    sqlite3_result_blob64(ctx, pBuf, nIn, sqlite3_free);
  } else {
    sqlite3_result_error_code(ctx, 10);
    sqlite3_free(pBuf);
  }
  fclose(in);
}
static void readfileFunc(sqlite3_context *context, int argc,
                         sqlite3_value **argv) {
  const char *zName;
  (void)(argc);
  zName = (const char *)sqlite3_value_text(argv[0]);
  if (zName == 0)
    return;
  readFileContents(context, zName);
}
static void ctxErrorMsg(sqlite3_context *ctx, const char *zFmt, ...) {
  char *zMsg = 0;
  va_list ap;
  __builtin_va_start(ap, zFmt);
  zMsg = sqlite3_vmprintf(zFmt, ap);
  sqlite3_result_error(ctx, zMsg, -1);
  sqlite3_free(zMsg);
  __builtin_va_end(ap);
}
static int fileStat(const char *zPath, struct stat *pStatBuf) {
  return stat(zPath, pStatBuf);
}
static int fileLinkStat(const char *zPath, struct stat *pStatBuf) {
  return lstat(zPath, pStatBuf);
}
static int makeDirectory(const char *zFile) {
  char *zCopy = sqlite3_mprintf("%s", zFile);
  int rc = 0;
  if (zCopy == 0) {
    rc = 7;
  } else {
    int nCopy = (int)strlen(zCopy);
    int i = 1;
    while (rc == 0) {
      struct stat sStat;
      int rc2;
      for (; zCopy[i] != '/' && i < nCopy; i++)
        ;
      if (i == nCopy)
        break;
      zCopy[i] = 'A';
      rc2 = fileStat(zCopy, &sStat);
      if (rc2 != 0) {
        if (mkdir(zCopy, 777))
          rc = 1;
      } else {
        if (!((((sStat.st_mode)) & 170000) == (40000)))
          rc = 1;
      }
      zCopy[i] = '/';
      i++;
    }
    sqlite3_free(zCopy);
  }
  return rc;
}
static int writeFile(sqlite3_context *pCtx, const char *zFile,
                     sqlite3_value *pData, mode_t mode, sqlite3_int64 mtime) {
  if (zFile == 0)
    return 1;
  if (((((mode)) & 170000) == (120000))) {
    const char *zTo = (const char *)sqlite3_value_text(pData);
    if (zTo == 0 || symlink(zTo, zFile) < 0)
      return 1;
  } else {
    if (((((mode)) & 170000) == (40000))) {
      if (mkdir(zFile, mode)) {
        struct stat sStat;
        if ((*__errno_location()) != 17 || 0 != fileStat(zFile, &sStat) ||
            !((((sStat.st_mode)) & 170000) == (40000)) ||
            ((sStat.st_mode & 777) != (mode & 777) &&
             0 != chmod(zFile, mode & 777))) {
          return 1;
        }
      }
    } else {
      sqlite3_int64 nWrite = 0;
      const char *z;
      int rc = 0;
      FILE *out = fopen(zFile, "wb");
      if (out == 0)
        return 1;
      z = (const char *)sqlite3_value_blob(pData);
      if (z) {
        sqlite3_int64 n = fwrite(z, 1, sqlite3_value_bytes(pData), out);
        nWrite = sqlite3_value_bytes(pData);
        if (nWrite != n) {
          rc = 1;
        }
      }
      fclose(out);
      if (rc == 0 && mode && chmod(zFile, mode & 777)) {
        rc = 1;
      }
      if (rc)
        return 2;
      sqlite3_result_int64(pCtx, nWrite);
    }
  }
  if (mtime >= 0) {
    struct timeval times[2];
    times[0].tv_usec = times[1].tv_usec = 0;
    times[0].tv_sec = time(0);
    times[1].tv_sec = mtime;
    if (utimes(zFile, times)) {
      return 1;
    }
  }
  return 0;
}
static void writefileFunc(sqlite3_context *context, int argc,
                          sqlite3_value **argv) {
  const char *zFile;
  mode_t mode = 0;
  int res;
  sqlite3_int64 mtime = -1;
  if (argc < 2 || argc > 4) {
    sqlite3_result_error(
        context, "wrong number of arguments to function writefile()", -1);
    return;
  }
  zFile = (const char *)sqlite3_value_text(argv[0]);
  if (zFile == 0)
    return;
  if (argc >= 3) {
    mode = (mode_t)sqlite3_value_int(argv[2]);
  }
  if (argc == 4) {
    mtime = sqlite3_value_int64(argv[3]);
  }
  res = writeFile(context, zFile, argv[1], mode, mtime);
  if (res == 1 && (*__errno_location()) == 2) {
    if (makeDirectory(zFile) == 0) {
      res = writeFile(context, zFile, argv[1], mode, mtime);
    }
  }
  if (argc > 2 && res != 0) {
    if (((((mode)) & 170000) == (120000))) {
      ctxErrorMsg(context, "failed to create symlink: %s", zFile);
    } else if (((((mode)) & 170000) == (40000))) {
      ctxErrorMsg(context, "failed to create directory: %s", zFile);
    } else {
      ctxErrorMsg(context, "failed to write file: %s", zFile);
    }
  }
}
static void lsModeFunc(sqlite3_context *context, int argc,
                       sqlite3_value **argv) {
  int i;
  int iMode = sqlite3_value_int(argv[0]);
  char z[16];
  (void)argc;
  if (((((iMode)) & 170000) == (120000))) {
    z[0] = 'l';
  } else if (((((iMode)) & 170000) == (100000))) {
    z[0] = '-';
  } else if (((((iMode)) & 170000) == (40000))) {
    z[0] = 'd';
  } else {
    z[0] = '?';
  }
  for (i = 0; i < 3; i++) {
    int m = (iMode >> ((2 - i) * 3));
    char *a = &z[1 + i * 3];
    a[0] = (m & 4) ? 'r' : '-';
    a[1] = (m & 2) ? 'w' : '-';
    a[2] = (m & 1) ? 'x' : '-';
  }
  z[10] = 'A';
  sqlite3_result_text(context, z, -1, ((sqlite3_destructor_type)-1));
}
typedef struct fsdir_cursor fsdir_cursor;
typedef struct FsdirLevel FsdirLevel;
struct FsdirLevel {
  DIR *pDir;
  char *zDir;
};
struct fsdir_cursor {
  sqlite3_vtab_cursor base;
  int nLvl;
  int iLvl;
  FsdirLevel *aLvl;
  const char *zBase;
  int nBase;
  struct stat sStat;
  char *zPath;
  sqlite3_int64 iRowid;
};
typedef struct fsdir_tab fsdir_tab;
struct fsdir_tab {
  sqlite3_vtab base;
};
static int fsdirConnect(sqlite3 *db, void *pAux, int argc,
                        const char *const *argv, sqlite3_vtab **ppVtab,
                        char **pzErr) {
  fsdir_tab *pNew = 0;
  int rc;
  (void)pAux;
  (void)argc;
  (void)argv;
  (void)pzErr;
  rc = sqlite3_declare_vtab(
      db, "CREATE TABLE x(name,mode,mtime,data,path HIDDEN,dir HIDDEN)");
  if (rc == 0) {
    pNew = (fsdir_tab *)sqlite3_malloc(sizeof(*pNew));
    if (pNew == 0)
      return 7;
    memset(pNew, 0, sizeof(*pNew));
    sqlite3_vtab_config(db, 3);
  }
  *ppVtab = (sqlite3_vtab *)pNew;
  return rc;
}
static int fsdirDisconnect(sqlite3_vtab *pVtab) {
  sqlite3_free(pVtab);
  return 0;
}
static int fsdirOpen(sqlite3_vtab *p, sqlite3_vtab_cursor **ppCursor) {
  fsdir_cursor *pCur;
  (void)p;
  pCur = sqlite3_malloc(sizeof(*pCur));
  if (pCur == 0)
    return 7;
  memset(pCur, 0, sizeof(*pCur));
  pCur->iLvl = -1;
  *ppCursor = &pCur->base;
  return 0;
}
static void fsdirResetCursor(fsdir_cursor *pCur) {
  int i;
  for (i = 0; i <= pCur->iLvl; i++) {
    FsdirLevel *pLvl = &pCur->aLvl[i];
    if (pLvl->pDir)
      closedir(pLvl->pDir);
    sqlite3_free(pLvl->zDir);
  }
  sqlite3_free(pCur->zPath);
  sqlite3_free(pCur->aLvl);
  pCur->aLvl = 0;
  pCur->zPath = 0;
  pCur->zBase = 0;
  pCur->nBase = 0;
  pCur->nLvl = 0;
  pCur->iLvl = -1;
  pCur->iRowid = 1;
}
static int fsdirClose(sqlite3_vtab_cursor *cur) {
  fsdir_cursor *pCur = (fsdir_cursor *)cur;
  fsdirResetCursor(pCur);
  sqlite3_free(pCur);
  return 0;
}
static void fsdirSetErrmsg(fsdir_cursor *pCur, const char *zFmt, ...) {
  va_list ap;
  __builtin_va_start(ap, zFmt);
  pCur->base.pVtab->zErrMsg = sqlite3_vmprintf(zFmt, ap);
  __builtin_va_end(ap);
}
static int fsdirNext(sqlite3_vtab_cursor *cur) {
  fsdir_cursor *pCur = (fsdir_cursor *)cur;
  mode_t m = pCur->sStat.st_mode;
  pCur->iRowid++;
  if (((((m)) & 170000) == (40000))) {
    int iNew = pCur->iLvl + 1;
    FsdirLevel *pLvl;
    if (iNew >= pCur->nLvl) {
      int nNew = iNew + 1;
      sqlite3_int64 nByte = nNew * sizeof(FsdirLevel);
      FsdirLevel *aNew = (FsdirLevel *)sqlite3_realloc64(pCur->aLvl, nByte);
      if (aNew == 0)
        return 7;
      memset(&aNew[pCur->nLvl], 0, sizeof(FsdirLevel) * (nNew - pCur->nLvl));
      pCur->aLvl = aNew;
      pCur->nLvl = nNew;
    }
    pCur->iLvl = iNew;
    pLvl = &pCur->aLvl[iNew];
    pLvl->zDir = pCur->zPath;
    pCur->zPath = 0;
    pLvl->pDir = opendir(pLvl->zDir);
    if (pLvl->pDir == 0) {
      fsdirSetErrmsg(pCur, "cannot read directory: %s", pCur->zPath);
      return 1;
    }
  }
  while (pCur->iLvl >= 0) {
    FsdirLevel *pLvl = &pCur->aLvl[pCur->iLvl];
    struct dirent *pEntry = readdir(pLvl->pDir);
    if (pEntry) {
      if (pEntry->d_name[0] == '.') {
        if (pEntry->d_name[1] == '.' && pEntry->d_name[2] == 'A')
          continue;
        if (pEntry->d_name[1] == 'A')
          continue;
      }
      sqlite3_free(pCur->zPath);
      pCur->zPath = sqlite3_mprintf("%s/%s", pLvl->zDir, pEntry->d_name);
      if (pCur->zPath == 0)
        return 7;
      if (fileLinkStat(pCur->zPath, &pCur->sStat)) {
        fsdirSetErrmsg(pCur, "cannot stat file: %s", pCur->zPath);
        return 1;
      }
      return 0;
    }
    closedir(pLvl->pDir);
    sqlite3_free(pLvl->zDir);
    pLvl->pDir = 0;
    pLvl->zDir = 0;
    pCur->iLvl--;
  }
  sqlite3_free(pCur->zPath);
  pCur->zPath = 0;
  return 0;
}
static int fsdirColumn(sqlite3_vtab_cursor *cur, sqlite3_context *ctx, int i) {
  fsdir_cursor *pCur = (fsdir_cursor *)cur;
  switch (i) {
  case 0: {
    sqlite3_result_text(ctx, &pCur->zPath[pCur->nBase], -1,
                        ((sqlite3_destructor_type)-1));
    break;
  }
  case 1:
    sqlite3_result_int64(ctx, pCur->sStat.st_mode);
    break;
  case 2:
    sqlite3_result_int64(ctx, pCur->sStat.st_mtim.tv_sec);
    break;
  case 3: {
    mode_t m = pCur->sStat.st_mode;
    if (((((m)) & 170000) == (40000))) {
      sqlite3_result_null(ctx);
    } else if (((((m)) & 170000) == (120000))) {
      char aStatic[64];
      char *aBuf = aStatic;
      sqlite3_int64 nBuf = 64;
      int n;
      while (1) {
        n = readlink(pCur->zPath, aBuf, nBuf);
        if (n < nBuf)
          break;
        if (aBuf != aStatic)
          sqlite3_free(aBuf);
        nBuf = nBuf * 2;
        aBuf = sqlite3_malloc64(nBuf);
        if (aBuf == 0) {
          sqlite3_result_error_nomem(ctx);
          return 7;
        }
      }
      sqlite3_result_text(ctx, aBuf, n, ((sqlite3_destructor_type)-1));
      if (aBuf != aStatic)
        sqlite3_free(aBuf);
    } else {
      readFileContents(ctx, pCur->zPath);
    }
  }
  case 4:
  default: {
    break;
  }
  }
  return 0;
}
static int fsdirRowid(sqlite3_vtab_cursor *cur, sqlite_int64 *pRowid) {
  fsdir_cursor *pCur = (fsdir_cursor *)cur;
  *pRowid = pCur->iRowid;
  return 0;
}
static int fsdirEof(sqlite3_vtab_cursor *cur) {
  fsdir_cursor *pCur = (fsdir_cursor *)cur;
  return (pCur->zPath == 0);
}
static int fsdirFilter(sqlite3_vtab_cursor *cur, int idxNum, const char *idxStr,
                       int argc, sqlite3_value **argv) {
  const char *zDir = 0;
  fsdir_cursor *pCur = (fsdir_cursor *)cur;
  (void)idxStr;
  fsdirResetCursor(pCur);
  if (idxNum == 0) {
    fsdirSetErrmsg(pCur, "table function fsdir requires an argument");
    return 1;
  }
  ((void)sizeof((argc == idxNum && (argc == 1 || argc == 2)) ? 1 : 0), ({
     if (argc == idxNum && (argc == 1 || argc == 2))
       ;
     else
       __assert_fail("argc==idxNum && (argc==1 || argc==2)", "shell.c", 6639,
                     __PRETTY_FUNCTION__);
   }));
  zDir = (const char *)sqlite3_value_text(argv[0]);
  if (zDir == 0) {
    fsdirSetErrmsg(pCur, "table function fsdir requires a non-NULL argument");
    return 1;
  }
  if (argc == 2) {
    pCur->zBase = (const char *)sqlite3_value_text(argv[1]);
  }
  if (pCur->zBase) {
    pCur->nBase = (int)strlen(pCur->zBase) + 1;
    pCur->zPath = sqlite3_mprintf("%s/%s", pCur->zBase, zDir);
  } else {
    pCur->zPath = sqlite3_mprintf("%s", zDir);
  }
  if (pCur->zPath == 0) {
    return 7;
  }
  if (fileLinkStat(pCur->zPath, &pCur->sStat)) {
    fsdirSetErrmsg(pCur, "cannot stat file: %s", pCur->zPath);
    return 1;
  }
  return 0;
}
static int fsdirBestIndex(sqlite3_vtab *tab, sqlite3_index_info *pIdxInfo) {
  int i;
  int idxPath = -1;
  int idxDir = -1;
  int seenPath = 0;
  int seenDir = 0;
  const struct sqlite3_index_constraint *pConstraint;
  (void)tab;
  pConstraint = pIdxInfo->aConstraint;
  for (i = 0; i < pIdxInfo->nConstraint; i++, pConstraint++) {
    if (pConstraint->op != 2)
      continue;
    switch (pConstraint->iColumn) {
    case 4: {
      if (pConstraint->usable) {
        idxPath = i;
        seenPath = 0;
      } else if (idxPath < 0) {
        seenPath = 1;
      }
      break;
    }
    case 5: {
      if (pConstraint->usable) {
        idxDir = i;
        seenDir = 0;
      } else if (idxDir < 0) {
        seenDir = 1;
      }
      break;
    }
    }
  }
  if (seenPath || seenDir) {
    return 19;
  }
  if (idxPath < 0) {
    pIdxInfo->idxNum = 0;
    pIdxInfo->estimatedRows = 2147483647;
  } else {
    pIdxInfo->aConstraintUsage[idxPath].omit = 1;
    pIdxInfo->aConstraintUsage[idxPath].argvIndex = 1;
    if (idxDir >= 0) {
      pIdxInfo->aConstraintUsage[idxDir].omit = 1;
      pIdxInfo->aConstraintUsage[idxDir].argvIndex = 2;
      pIdxInfo->idxNum = 2;
      pIdxInfo->estimatedCost = 10.000000;
    } else {
      pIdxInfo->idxNum = 1;
      pIdxInfo->estimatedCost = 100.000000;
    }
  }
  return 0;
}
static int fsdirRegister(sqlite3 *db) {
  static sqlite3_module fsdirModule = {0,
                                       0,
                                       fsdirConnect,
                                       fsdirBestIndex,
                                       fsdirDisconnect,
                                       0,
                                       fsdirOpen,
                                       fsdirClose,
                                       fsdirFilter,
                                       fsdirNext,
                                       fsdirEof,
                                       fsdirColumn,
                                       fsdirRowid,
                                       0,
                                       0,
                                       0,
                                       0,
                                       0,
                                       0,
                                       0,
                                       0,
                                       0,
                                       0,
                                       0};
  int rc = sqlite3_create_module(db, "fsdir", &fsdirModule, 0);
  return rc;
}
int sqlite3_fileio_init(sqlite3 *db, char **pzErrMsg,
                        const sqlite3_api_routines *pApi) {
  int rc = 0;
  (void)(pApi);
  (void)pzErrMsg;
  rc = sqlite3_create_function(db, "readfile", 1, 1 | 524288, 0, readfileFunc,
                               0, 0);
  if (rc == 0) {
    rc = sqlite3_create_function(db, "writefile", -1, 1 | 524288, 0,
                                 writefileFunc, 0, 0);
  }
  if (rc == 0) {
    rc = sqlite3_create_function(db, "lsmode", 1, 1, 0, lsModeFunc, 0, 0);
  }
  if (rc == 0) {
    rc = fsdirRegister(db);
  }
  return rc;
}
typedef struct completion_vtab completion_vtab;
struct completion_vtab {
  sqlite3_vtab base;
  sqlite3 *db;
};
typedef struct completion_cursor completion_cursor;
struct completion_cursor {
  sqlite3_vtab_cursor base;
  sqlite3 *db;
  int nPrefix, nLine;
  char *zPrefix;
  char *zLine;
  const char *zCurrentRow;
  int szRow;
  sqlite3_stmt *pStmt;
  sqlite3_int64 iRowid;
  int ePhase;
  int j;
};
static int completionConnect(sqlite3 *db, void *pAux, int argc,
                             const char *const *argv, sqlite3_vtab **ppVtab,
                             char **pzErr) {
  completion_vtab *pNew;
  int rc;
  (void)(pAux);
  (void)(argc);
  (void)(argv);
  (void)(pzErr);
  sqlite3_vtab_config(db, 2);
  rc = sqlite3_declare_vtab(
      db, "CREATE TABLE x(  candidate TEXT,  prefix TEXT HIDDEN,  wholeline "
          "TEXT HIDDEN,  phase INT HIDDEN)");
  if (rc == 0) {
    pNew = sqlite3_malloc(sizeof(*pNew));
    *ppVtab = (sqlite3_vtab *)pNew;
    if (pNew == 0)
      return 7;
    memset(pNew, 0, sizeof(*pNew));
    pNew->db = db;
  }
  return rc;
}
static int completionDisconnect(sqlite3_vtab *pVtab) {
  sqlite3_free(pVtab);
  return 0;
}
static int completionOpen(sqlite3_vtab *p, sqlite3_vtab_cursor **ppCursor) {
  completion_cursor *pCur;
  pCur = sqlite3_malloc(sizeof(*pCur));
  if (pCur == 0)
    return 7;
  memset(pCur, 0, sizeof(*pCur));
  pCur->db = ((completion_vtab *)p)->db;
  *ppCursor = &pCur->base;
  return 0;
}
static void completionCursorReset(completion_cursor *pCur) {
  sqlite3_free(pCur->zPrefix);
  pCur->zPrefix = 0;
  pCur->nPrefix = 0;
  sqlite3_free(pCur->zLine);
  pCur->zLine = 0;
  pCur->nLine = 0;
  sqlite3_finalize(pCur->pStmt);
  pCur->pStmt = 0;
  pCur->j = 0;
}
static int completionClose(sqlite3_vtab_cursor *cur) {
  completionCursorReset((completion_cursor *)cur);
  sqlite3_free(cur);
  return 0;
}
static int completionNext(sqlite3_vtab_cursor *cur) {
  completion_cursor *pCur = (completion_cursor *)cur;
  int eNextPhase = 0;
  int iCol = -1;
  pCur->iRowid++;
  while (pCur->ePhase != 11) {
    switch (pCur->ePhase) {
    case 1: {
      if (pCur->j >= sqlite3_keyword_count()) {
        pCur->zCurrentRow = 0;
        pCur->ePhase = 7;
      } else {
        sqlite3_keyword_name(pCur->j++, &pCur->zCurrentRow, &pCur->szRow);
      }
      iCol = -1;
      break;
    }
    case 7: {
      if (pCur->pStmt == 0) {
        sqlite3_prepare_v2(pCur->db, "PRAGMA database_list", -1, &pCur->pStmt,
                           0);
      }
      iCol = 1;
      eNextPhase = 8;
      break;
    }
    case 8: {
      if (pCur->pStmt == 0) {
        sqlite3_stmt *pS2;
        char *zSql = 0;
        const char *zSep = "";
        sqlite3_prepare_v2(pCur->db, "PRAGMA database_list", -1, &pS2, 0);
        while (sqlite3_step(pS2) == 100) {
          const char *zDb = (const char *)sqlite3_column_text(pS2, 1);
          zSql = sqlite3_mprintf("%z%sSELECT name FROM \"%w\".sqlite_schema",
                                 zSql, zSep, zDb);
          if (zSql == 0)
            return 7;
          zSep = " UNION ";
        }
        sqlite3_finalize(pS2);
        sqlite3_prepare_v2(pCur->db, zSql, -1, &pCur->pStmt, 0);
        sqlite3_free(zSql);
      }
      iCol = 0;
      eNextPhase = 9;
      break;
    }
    case 9: {
      if (pCur->pStmt == 0) {
        sqlite3_stmt *pS2;
        char *zSql = 0;
        const char *zSep = "";
        sqlite3_prepare_v2(pCur->db, "PRAGMA database_list", -1, &pS2, 0);
        while (sqlite3_step(pS2) == 100) {
          const char *zDb = (const char *)sqlite3_column_text(pS2, 1);
          zSql = sqlite3_mprintf(
              "%z%sSELECT pti.name FROM \"%w\".sqlite_schema AS sm JOIN "
              "pragma_table_info(sm.name,%Q) AS pti WHERE sm.type='table'",
              zSql, zSep, zDb, zDb);
          if (zSql == 0)
            return 7;
          zSep = " UNION ";
        }
        sqlite3_finalize(pS2);
        sqlite3_prepare_v2(pCur->db, zSql, -1, &pCur->pStmt, 0);
        sqlite3_free(zSql);
      }
      iCol = 0;
      eNextPhase = 11;
      break;
    }
    }
    if (iCol < 0) {
      if (pCur->zCurrentRow == 0)
        continue;
    } else {
      if (sqlite3_step(pCur->pStmt) == 100) {
        pCur->zCurrentRow =
            (const char *)sqlite3_column_text(pCur->pStmt, iCol);
        pCur->szRow = sqlite3_column_bytes(pCur->pStmt, iCol);
      } else {
        sqlite3_finalize(pCur->pStmt);
        pCur->pStmt = 0;
        pCur->ePhase = eNextPhase;
        continue;
      }
    }
    if (pCur->nPrefix == 0)
      break;
    if (pCur->nPrefix <= pCur->szRow &&
        sqlite3_strnicmp(pCur->zPrefix, pCur->zCurrentRow, pCur->nPrefix) ==
            0) {
      break;
    }
  }
  return 0;
}
static int completionColumn(sqlite3_vtab_cursor *cur, sqlite3_context *ctx,
                            int i) {
  completion_cursor *pCur = (completion_cursor *)cur;
  switch (i) {
  case 0: {
    sqlite3_result_text(ctx, pCur->zCurrentRow, pCur->szRow,
                        ((sqlite3_destructor_type)-1));
    break;
  }
  case 1: {
    sqlite3_result_text(ctx, pCur->zPrefix, -1, ((sqlite3_destructor_type)-1));
    break;
  }
  case 2: {
    sqlite3_result_text(ctx, pCur->zLine, -1, ((sqlite3_destructor_type)-1));
    break;
  }
  case 3: {
    sqlite3_result_int(ctx, pCur->ePhase);
    break;
  }
  }
  return 0;
}
static int completionRowid(sqlite3_vtab_cursor *cur, sqlite_int64 *pRowid) {
  completion_cursor *pCur = (completion_cursor *)cur;
  *pRowid = pCur->iRowid;
  return 0;
}
static int completionEof(sqlite3_vtab_cursor *cur) {
  completion_cursor *pCur = (completion_cursor *)cur;
  return pCur->ePhase >= 11;
}
static int completionFilter(sqlite3_vtab_cursor *pVtabCursor, int idxNum,
                            const char *idxStr, int argc,
                            sqlite3_value **argv) {
  completion_cursor *pCur = (completion_cursor *)pVtabCursor;
  int iArg = 0;
  (void)(idxStr);
  (void)(argc);
  completionCursorReset(pCur);
  if (idxNum & 1) {
    pCur->nPrefix = sqlite3_value_bytes(argv[iArg]);
    if (pCur->nPrefix > 0) {
      pCur->zPrefix = sqlite3_mprintf("%s", sqlite3_value_text(argv[iArg]));
      if (pCur->zPrefix == 0)
        return 7;
    }
    iArg = 1;
  }
  if (idxNum & 2) {
    pCur->nLine = sqlite3_value_bytes(argv[iArg]);
    if (pCur->nLine > 0) {
      pCur->zLine = sqlite3_mprintf("%s", sqlite3_value_text(argv[iArg]));
      if (pCur->zLine == 0)
        return 7;
    }
  }
  if (pCur->zLine != 0 && pCur->zPrefix == 0) {
    int i = pCur->nLine;
    while (i > 0 && (((*__ctype_b_loc())[(int)((pCur->zLine[i - 1]))] &
                      (unsigned short int)_ISalnum) ||
                     pCur->zLine[i - 1] == '_')) {
      i--;
    }
    pCur->nPrefix = pCur->nLine - i;
    if (pCur->nPrefix > 0) {
      pCur->zPrefix = sqlite3_mprintf("%.*s", pCur->nPrefix, pCur->zLine + i);
      if (pCur->zPrefix == 0)
        return 7;
    }
  }
  pCur->iRowid = 0;
  pCur->ePhase = 1;
  return completionNext(pVtabCursor);
}
static int completionBestIndex(sqlite3_vtab *tab,
                               sqlite3_index_info *pIdxInfo) {
  int i;
  int idxNum = 0;
  int prefixIdx = -1;
  int wholelineIdx = -1;
  int nArg = 0;
  const struct sqlite3_index_constraint *pConstraint;
  (void)(tab);
  pConstraint = pIdxInfo->aConstraint;
  for (i = 0; i < pIdxInfo->nConstraint; i++, pConstraint++) {
    if (pConstraint->usable == 0)
      continue;
    if (pConstraint->op != 2)
      continue;
    switch (pConstraint->iColumn) {
    case 1:
      prefixIdx = i;
      idxNum |= 1;
      break;
    case 2:
      wholelineIdx = i;
      idxNum |= 2;
      break;
    }
  }
  if (prefixIdx >= 0) {
    pIdxInfo->aConstraintUsage[prefixIdx].argvIndex = ++nArg;
    pIdxInfo->aConstraintUsage[prefixIdx].omit = 1;
  }
  if (wholelineIdx >= 0) {
    pIdxInfo->aConstraintUsage[wholelineIdx].argvIndex = ++nArg;
    pIdxInfo->aConstraintUsage[wholelineIdx].omit = 1;
  }
  pIdxInfo->idxNum = idxNum;
  pIdxInfo->estimatedCost = (double)5000 - 1000 * nArg;
  pIdxInfo->estimatedRows = 500 - 100 * nArg;
  return 0;
}
static sqlite3_module completionModule = {0,
                                          0,
                                          completionConnect,
                                          completionBestIndex,
                                          completionDisconnect,
                                          0,
                                          completionOpen,
                                          completionClose,
                                          completionFilter,
                                          completionNext,
                                          completionEof,
                                          completionColumn,
                                          completionRowid,
                                          0,
                                          0,
                                          0,
                                          0,
                                          0,
                                          0,
                                          0,
                                          0,
                                          0,
                                          0,
                                          0};
int sqlite3CompletionVtabInit(sqlite3 *db) {
  int rc = 0;
  rc = sqlite3_create_module(db, "completion", &completionModule, 0);
  return rc;
}
int sqlite3_completion_init(sqlite3 *db, char **pzErrMsg,
                            const sqlite3_api_routines *pApi) {
  int rc = 0;
  (void)(pApi);
  (void)(pzErrMsg);
  rc = sqlite3CompletionVtabInit(db);
  return rc;
}
typedef struct sqlite3_vfs ApndVfs;
typedef struct ApndFile ApndFile;
struct ApndFile {
  sqlite3_file base;
  sqlite3_int64 iPgOne;
  sqlite3_int64 iMark;
};
static int apndClose(sqlite3_file *);
static int apndRead(sqlite3_file *, void *, int iAmt, sqlite3_int64 iOfst);
static int apndWrite(sqlite3_file *, const void *, int iAmt,
                     sqlite3_int64 iOfst);
static int apndTruncate(sqlite3_file *, sqlite3_int64 size);
static int apndSync(sqlite3_file *, int flags);
static int apndFileSize(sqlite3_file *, sqlite3_int64 *pSize);
static int apndLock(sqlite3_file *, int);
static int apndUnlock(sqlite3_file *, int);
static int apndCheckReservedLock(sqlite3_file *, int *pResOut);
static int apndFileControl(sqlite3_file *, int op, void *pArg);
static int apndSectorSize(sqlite3_file *);
static int apndDeviceCharacteristics(sqlite3_file *);
static int apndShmMap(sqlite3_file *, int iPg, int pgsz, int, void volatile **);
static int apndShmLock(sqlite3_file *, int offset, int n, int flags);
static void apndShmBarrier(sqlite3_file *);
static int apndShmUnmap(sqlite3_file *, int deleteFlag);
static int apndFetch(sqlite3_file *, sqlite3_int64 iOfst, int iAmt, void **pp);
static int apndUnfetch(sqlite3_file *, sqlite3_int64 iOfst, void *p);
static int apndOpen(sqlite3_vfs *, const char *, sqlite3_file *, int, int *);
static int apndDelete(sqlite3_vfs *, const char *zName, int syncDir);
static int apndAccess(sqlite3_vfs *, const char *zName, int flags, int *);
static int apndFullPathname(sqlite3_vfs *, const char *zName, int, char *zOut);
static void *apndDlOpen(sqlite3_vfs *, const char *zFilename);
static void apndDlError(sqlite3_vfs *, int nByte, char *zErrMsg);
static void (*apndDlSym(sqlite3_vfs *pVfs, void *p, const char *zSym))(void);
static void apndDlClose(sqlite3_vfs *, void *);
static int apndRandomness(sqlite3_vfs *, int nByte, char *zOut);
static int apndSleep(sqlite3_vfs *, int microseconds);
static int apndCurrentTime(sqlite3_vfs *, double *);
static int apndGetLastError(sqlite3_vfs *, int, char *);
static int apndCurrentTimeInt64(sqlite3_vfs *, sqlite3_int64 *);
static int apndSetSystemCall(sqlite3_vfs *, const char *, sqlite3_syscall_ptr);
static sqlite3_syscall_ptr apndGetSystemCall(sqlite3_vfs *, const char *z);
static const char *apndNextSystemCall(sqlite3_vfs *, const char *zName);
static sqlite3_vfs apnd_vfs = {3,
                               0,
                               1024,
                               0,
                               "apndvfs",
                               0,
                               apndOpen,
                               apndDelete,
                               apndAccess,
                               apndFullPathname,
                               apndDlOpen,
                               apndDlError,
                               apndDlSym,
                               apndDlClose,
                               apndRandomness,
                               apndSleep,
                               apndCurrentTime,
                               apndGetLastError,
                               apndCurrentTimeInt64,
                               apndSetSystemCall,
                               apndGetSystemCall,
                               apndNextSystemCall};
static const sqlite3_io_methods apnd_io_methods = {3,
                                                   apndClose,
                                                   apndRead,
                                                   apndWrite,
                                                   apndTruncate,
                                                   apndSync,
                                                   apndFileSize,
                                                   apndLock,
                                                   apndUnlock,
                                                   apndCheckReservedLock,
                                                   apndFileControl,
                                                   apndSectorSize,
                                                   apndDeviceCharacteristics,
                                                   apndShmMap,
                                                   apndShmLock,
                                                   apndShmBarrier,
                                                   apndShmUnmap,
                                                   apndFetch,
                                                   apndUnfetch};
static int apndClose(sqlite3_file *pFile) {
  pFile = ((sqlite3_file *)(((ApndFile *)(pFile)) + 1));
  return pFile->pMethods->xClose(pFile);
}
static int apndRead(sqlite3_file *pFile, void *zBuf, int iAmt,
                    sqlite_int64 iOfst) {
  ApndFile *paf = (ApndFile *)pFile;
  pFile = ((sqlite3_file *)(((ApndFile *)(pFile)) + 1));
  return pFile->pMethods->xRead(pFile, zBuf, iAmt, paf->iPgOne + iOfst);
}
static int apndWriteMark(ApndFile *paf, sqlite3_file *pFile,
                         sqlite_int64 iWriteEnd) {
  sqlite_int64 iPgOne = paf->iPgOne;
  unsigned char a[(17 + 8)];
  int i = 8;
  int rc;
  ((void)sizeof((pFile == ((sqlite3_file *)(((ApndFile *)(paf)) + 1))) ? 1 : 0),
   ({
     if (pFile == ((sqlite3_file *)(((ApndFile *)(paf)) + 1)))
       ;
     else
       __assert_fail("pFile == ORIGFILE(paf)", "shell.c", 7583,
                     __PRETTY_FUNCTION__);
   }));
  memcpy(a, "Start-Of-SQLite3-", 17);
  while (--i >= 0) {
    a[17 + i] = (unsigned char)(iPgOne & 255);
    iPgOne >>= 8;
  }
  iWriteEnd += paf->iPgOne;
  if (0 == (rc = pFile->pMethods->xWrite(pFile, a, (17 + 8), iWriteEnd))) {
    paf->iMark = iWriteEnd;
  }
  return rc;
}
static int apndWrite(sqlite3_file *pFile, const void *zBuf, int iAmt,
                     sqlite_int64 iOfst) {
  ApndFile *paf = (ApndFile *)pFile;
  sqlite_int64 iWriteEnd = iOfst + iAmt;
  if (iWriteEnd >= (1073741824))
    return 13;
  pFile = ((sqlite3_file *)(((ApndFile *)(pFile)) + 1));
  if (paf->iMark < 0 || paf->iPgOne + iWriteEnd > paf->iMark) {
    int rc = apndWriteMark(paf, pFile, iWriteEnd);
    if (0 != rc)
      return rc;
  }
  return pFile->pMethods->xWrite(pFile, zBuf, iAmt, paf->iPgOne + iOfst);
}
static int apndTruncate(sqlite3_file *pFile, sqlite_int64 size) {
  ApndFile *paf = (ApndFile *)pFile;
  pFile = ((sqlite3_file *)(((ApndFile *)(pFile)) + 1));
  if (0 != apndWriteMark(paf, pFile, size))
    return 10;
  return pFile->pMethods->xTruncate(pFile, paf->iMark + (17 + 8));
}
static int apndSync(sqlite3_file *pFile, int flags) {
  pFile = ((sqlite3_file *)(((ApndFile *)(pFile)) + 1));
  return pFile->pMethods->xSync(pFile, flags);
}
static int apndFileSize(sqlite3_file *pFile, sqlite_int64 *pSize) {
  ApndFile *paf = (ApndFile *)pFile;
  *pSize = (paf->iMark >= 0) ? (paf->iMark - paf->iPgOne) : 0;
  return 0;
}
static int apndLock(sqlite3_file *pFile, int eLock) {
  pFile = ((sqlite3_file *)(((ApndFile *)(pFile)) + 1));
  return pFile->pMethods->xLock(pFile, eLock);
}
static int apndUnlock(sqlite3_file *pFile, int eLock) {
  pFile = ((sqlite3_file *)(((ApndFile *)(pFile)) + 1));
  return pFile->pMethods->xUnlock(pFile, eLock);
}
static int apndCheckReservedLock(sqlite3_file *pFile, int *pResOut) {
  pFile = ((sqlite3_file *)(((ApndFile *)(pFile)) + 1));
  return pFile->pMethods->xCheckReservedLock(pFile, pResOut);
}
static int apndFileControl(sqlite3_file *pFile, int op, void *pArg) {
  ApndFile *paf = (ApndFile *)pFile;
  int rc;
  pFile = ((sqlite3_file *)(((ApndFile *)(pFile)) + 1));
  if (op == 5)
    *(sqlite3_int64 *)pArg += paf->iPgOne;
  rc = pFile->pMethods->xFileControl(pFile, op, pArg);
  if (rc == 0 && op == 12) {
    *(char **)pArg =
        sqlite3_mprintf("apnd(%lld)/%z", paf->iPgOne, *(char **)pArg);
  }
  return rc;
}
static int apndSectorSize(sqlite3_file *pFile) {
  pFile = ((sqlite3_file *)(((ApndFile *)(pFile)) + 1));
  return pFile->pMethods->xSectorSize(pFile);
}
static int apndDeviceCharacteristics(sqlite3_file *pFile) {
  pFile = ((sqlite3_file *)(((ApndFile *)(pFile)) + 1));
  return pFile->pMethods->xDeviceCharacteristics(pFile);
}
static int apndShmMap(sqlite3_file *pFile, int iPg, int pgsz, int bExtend,
                      void volatile **pp) {
  pFile = ((sqlite3_file *)(((ApndFile *)(pFile)) + 1));
  return pFile->pMethods->xShmMap(pFile, iPg, pgsz, bExtend, pp);
}
static int apndShmLock(sqlite3_file *pFile, int offset, int n, int flags) {
  pFile = ((sqlite3_file *)(((ApndFile *)(pFile)) + 1));
  return pFile->pMethods->xShmLock(pFile, offset, n, flags);
}
static void apndShmBarrier(sqlite3_file *pFile) {
  pFile = ((sqlite3_file *)(((ApndFile *)(pFile)) + 1));
  pFile->pMethods->xShmBarrier(pFile);
}
static int apndShmUnmap(sqlite3_file *pFile, int deleteFlag) {
  pFile = ((sqlite3_file *)(((ApndFile *)(pFile)) + 1));
  return pFile->pMethods->xShmUnmap(pFile, deleteFlag);
}
static int apndFetch(sqlite3_file *pFile, sqlite3_int64 iOfst, int iAmt,
                     void **pp) {
  ApndFile *p = (ApndFile *)pFile;
  if (p->iMark < 0 || iOfst + iAmt > p->iMark) {
    return 10;
  }
  pFile = ((sqlite3_file *)(((ApndFile *)(pFile)) + 1));
  return pFile->pMethods->xFetch(pFile, iOfst + p->iPgOne, iAmt, pp);
}
static int apndUnfetch(sqlite3_file *pFile, sqlite3_int64 iOfst, void *pPage) {
  ApndFile *p = (ApndFile *)pFile;
  pFile = ((sqlite3_file *)(((ApndFile *)(pFile)) + 1));
  return pFile->pMethods->xUnfetch(pFile, iOfst + p->iPgOne, pPage);
}
static sqlite3_int64 apndReadMark(sqlite3_int64 sz, sqlite3_file *pFile) {
  int rc, i;
  sqlite3_int64 iMark;
  int msbs = 8 * (8 - 1);
  unsigned char a[(17 + 8)];
  if ((17 + 8) != (sz & 511))
    return -1;
  rc = pFile->pMethods->xRead(pFile, a, (17 + 8), sz - (17 + 8));
  if (rc)
    return -1;
  if (memcmp(a, "Start-Of-SQLite3-", 17) != 0)
    return -1;
  iMark = ((sqlite3_int64)(a[17] & 127)) << msbs;
  for (i = 1; i < 8; i++) {
    msbs -= 8;
    iMark |= (sqlite3_int64)a[17 + i] << msbs;
  }
  if (iMark > (sz - (17 + 8) - 512))
    return -1;
  if (iMark & 511)
    return -1;
  return iMark;
}
static const char apvfsSqliteHdr[] = "SQLite format 3";
static int apndIsAppendvfsDatabase(sqlite3_int64 sz, sqlite3_file *pFile) {
  int rc;
  char zHdr[16];
  sqlite3_int64 iMark = apndReadMark(sz, pFile);
  if (iMark >= 0) {
    rc = pFile->pMethods->xRead(pFile, zHdr, sizeof(zHdr), iMark);
    if (0 == rc && memcmp(zHdr, apvfsSqliteHdr, sizeof(zHdr)) == 0 &&
        (sz & 511) == (17 + 8) && sz >= 512 + (17 + 8)) {
      return 1;
    }
  }
  return 0;
}
static int apndIsOrdinaryDatabaseFile(sqlite3_int64 sz, sqlite3_file *pFile) {
  char zHdr[16];
  if (apndIsAppendvfsDatabase(sz, pFile) || (sz & 511) != 0 ||
      0 != pFile->pMethods->xRead(pFile, zHdr, sizeof(zHdr), 0) ||
      memcmp(zHdr, apvfsSqliteHdr, sizeof(zHdr)) != 0) {
    return 0;
  } else {
    return 1;
  }
}
static int apndOpen(sqlite3_vfs *pApndVfs, const char *zName,
                    sqlite3_file *pFile, int flags, int *pOutFlags) {
  ApndFile *pApndFile = (ApndFile *)pFile;
  sqlite3_file *pBaseFile = ((sqlite3_file *)(((ApndFile *)(pFile)) + 1));
  sqlite3_vfs *pBaseVfs = ((sqlite3_vfs *)((pApndVfs)->pAppData));
  int rc;
  sqlite3_int64 sz = 0;
  if ((flags & 256) == 0) {
    return pBaseVfs->xOpen(pBaseVfs, zName, pFile, flags, pOutFlags);
  }
  memset(pApndFile, 0, sizeof(ApndFile));
  pFile->pMethods = &apnd_io_methods;
  pApndFile->iMark = -1;
  rc = pBaseVfs->xOpen(pBaseVfs, zName, pBaseFile, flags, pOutFlags);
  if (rc == 0) {
    rc = pBaseFile->pMethods->xFileSize(pBaseFile, &sz);
    if (rc) {
      pBaseFile->pMethods->xClose(pBaseFile);
    }
  }
  if (rc) {
    pFile->pMethods = 0;
    return rc;
  }
  if (apndIsOrdinaryDatabaseFile(sz, pBaseFile)) {
    memmove(pApndFile, pBaseFile, pBaseVfs->szOsFile);
    return 0;
  }
  pApndFile->iPgOne = apndReadMark(sz, pFile);
  if (pApndFile->iPgOne >= 0) {
    pApndFile->iMark = sz - (17 + 8);
    return 0;
  }
  if ((flags & 4) == 0) {
    pBaseFile->pMethods->xClose(pBaseFile);
    rc = 14;
    pFile->pMethods = 0;
  } else {
    pApndFile->iPgOne =
        (((sz) + ((sqlite3_int64)(4096 - 1))) & ~((sqlite3_int64)(4096 - 1)));
  }
  return rc;
}
static int apndDelete(sqlite3_vfs *pVfs, const char *zPath, int dirSync) {
  return ((sqlite3_vfs *)((pVfs)->pAppData))
      ->xDelete(((sqlite3_vfs *)((pVfs)->pAppData)), zPath, dirSync);
}
static int apndAccess(sqlite3_vfs *pVfs, const char *zPath, int flags,
                      int *pResOut) {
  return ((sqlite3_vfs *)((pVfs)->pAppData))
      ->xAccess(((sqlite3_vfs *)((pVfs)->pAppData)), zPath, flags, pResOut);
}
static int apndFullPathname(sqlite3_vfs *pVfs, const char *zPath, int nOut,
                            char *zOut) {
  return ((sqlite3_vfs *)((pVfs)->pAppData))
      ->xFullPathname(((sqlite3_vfs *)((pVfs)->pAppData)), zPath, nOut, zOut);
}
static void *apndDlOpen(sqlite3_vfs *pVfs, const char *zPath) {
  return ((sqlite3_vfs *)((pVfs)->pAppData))
      ->xDlOpen(((sqlite3_vfs *)((pVfs)->pAppData)), zPath);
}
static void apndDlError(sqlite3_vfs *pVfs, int nByte, char *zErrMsg) {
  ((sqlite3_vfs *)((pVfs)->pAppData))
      ->xDlError(((sqlite3_vfs *)((pVfs)->pAppData)), nByte, zErrMsg);
}
static void (*apndDlSym(sqlite3_vfs *pVfs, void *p, const char *zSym))(void) {
  return ((sqlite3_vfs *)((pVfs)->pAppData))
      ->xDlSym(((sqlite3_vfs *)((pVfs)->pAppData)), p, zSym);
}
static void apndDlClose(sqlite3_vfs *pVfs, void *pHandle) {
  ((sqlite3_vfs *)((pVfs)->pAppData))
      ->xDlClose(((sqlite3_vfs *)((pVfs)->pAppData)), pHandle);
}
static int apndRandomness(sqlite3_vfs *pVfs, int nByte, char *zBufOut) {
  return ((sqlite3_vfs *)((pVfs)->pAppData))
      ->xRandomness(((sqlite3_vfs *)((pVfs)->pAppData)), nByte, zBufOut);
}
static int apndSleep(sqlite3_vfs *pVfs, int nMicro) {
  return ((sqlite3_vfs *)((pVfs)->pAppData))
      ->xSleep(((sqlite3_vfs *)((pVfs)->pAppData)), nMicro);
}
static int apndCurrentTime(sqlite3_vfs *pVfs, double *pTimeOut) {
  return ((sqlite3_vfs *)((pVfs)->pAppData))
      ->xCurrentTime(((sqlite3_vfs *)((pVfs)->pAppData)), pTimeOut);
}
static int apndGetLastError(sqlite3_vfs *pVfs, int a, char *b) {
  return ((sqlite3_vfs *)((pVfs)->pAppData))
      ->xGetLastError(((sqlite3_vfs *)((pVfs)->pAppData)), a, b);
}
static int apndCurrentTimeInt64(sqlite3_vfs *pVfs, sqlite3_int64 *p) {
  return ((sqlite3_vfs *)((pVfs)->pAppData))
      ->xCurrentTimeInt64(((sqlite3_vfs *)((pVfs)->pAppData)), p);
}
static int apndSetSystemCall(sqlite3_vfs *pVfs, const char *zName,
                             sqlite3_syscall_ptr pCall) {
  return ((sqlite3_vfs *)((pVfs)->pAppData))
      ->xSetSystemCall(((sqlite3_vfs *)((pVfs)->pAppData)), zName, pCall);
}
static sqlite3_syscall_ptr apndGetSystemCall(sqlite3_vfs *pVfs,
                                             const char *zName) {
  return ((sqlite3_vfs *)((pVfs)->pAppData))
      ->xGetSystemCall(((sqlite3_vfs *)((pVfs)->pAppData)), zName);
}
static const char *apndNextSystemCall(sqlite3_vfs *pVfs, const char *zName) {
  return ((sqlite3_vfs *)((pVfs)->pAppData))
      ->xNextSystemCall(((sqlite3_vfs *)((pVfs)->pAppData)), zName);
}
int sqlite3_appendvfs_init(sqlite3 *db, char **pzErrMsg,
                           const sqlite3_api_routines *pApi) {
  int rc = 0;
  sqlite3_vfs *pOrig;
  (void)(pApi);
  (void)pzErrMsg;
  (void)db;
  pOrig = sqlite3_vfs_find(0);
  if (pOrig == 0)
    return 1;
  apnd_vfs.iVersion = pOrig->iVersion;
  apnd_vfs.pAppData = pOrig;
  apnd_vfs.szOsFile = pOrig->szOsFile + sizeof(ApndFile);
  rc = sqlite3_vfs_register(&apnd_vfs, 0);
  if (rc == 0)
    rc = (0 | (1 << 8));
  return rc;
}
typedef struct sqlite3expert sqlite3expert;
sqlite3expert *sqlite3_expert_new(sqlite3 *db, char **pzErr);
int sqlite3_expert_config(sqlite3expert *p, int op, ...);
int sqlite3_expert_sql(sqlite3expert *p, const char *zSql, char **pzErr);
int sqlite3_expert_analyze(sqlite3expert *p, char **pzErr);
int sqlite3_expert_count(sqlite3expert *);
const char *sqlite3_expert_report(sqlite3expert *, int iStmt, int eReport);
void sqlite3_expert_destroy(sqlite3expert *);
typedef struct IdxColumn IdxColumn;
typedef struct IdxConstraint IdxConstraint;
typedef struct IdxScan IdxScan;
typedef struct IdxStatement IdxStatement;
typedef struct IdxTable IdxTable;
typedef struct IdxWrite IdxWrite;
struct IdxConstraint {
  char *zColl;
  int bRange;
  int iCol;
  int bFlag;
  int bDesc;
  IdxConstraint *pNext;
  IdxConstraint *pLink;
};
struct IdxScan {
  IdxTable *pTab;
  int iDb;
  i64 covering;
  IdxConstraint *pOrder;
  IdxConstraint *pEq;
  IdxConstraint *pRange;
  IdxScan *pNextScan;
};
struct IdxColumn {
  char *zName;
  char *zColl;
  int iPk;
};
struct IdxTable {
  int nCol;
  char *zName;
  IdxColumn *aCol;
  IdxTable *pNext;
};
struct IdxWrite {
  IdxTable *pTab;
  int eOp;
  IdxWrite *pNext;
};
struct IdxStatement {
  int iId;
  char *zSql;
  char *zIdx;
  char *zEQP;
  IdxStatement *pNext;
};
typedef struct IdxHashEntry IdxHashEntry;
typedef struct IdxHash IdxHash;
struct IdxHashEntry {
  char *zKey;
  char *zVal;
  char *zVal2;
  IdxHashEntry *pHashNext;
  IdxHashEntry *pNext;
};
struct IdxHash {
  IdxHashEntry *pFirst;
  IdxHashEntry *aHash[1023];
};
struct sqlite3expert {
  int iSample;
  sqlite3 *db;
  sqlite3 *dbm;
  sqlite3 *dbv;
  IdxTable *pTable;
  IdxScan *pScan;
  IdxWrite *pWrite;
  IdxStatement *pStatement;
  int bRun;
  char **pzErrmsg;
  int rc;
  IdxHash hIdx;
  char *zCandidates;
};
static void *idxMalloc(int *pRc, int nByte) {
  void *pRet;
  ((void)sizeof((*pRc == 0) ? 1 : 0), ({
     if (*pRc == 0)
       ;
     else
       __assert_fail("*pRc==SQLITE_OK", "shell.c", 10714, __PRETTY_FUNCTION__);
   }));
  ((void)sizeof((nByte > 0) ? 1 : 0), ({
     if (nByte > 0)
       ;
     else
       __assert_fail("nByte>0", "shell.c", 10715, __PRETTY_FUNCTION__);
   }));
  pRet = sqlite3_malloc(nByte);
  if (pRet) {
    memset(pRet, 0, nByte);
  } else {
    *pRc = 7;
  }
  return pRet;
}
static void idxHashInit(IdxHash *pHash) { memset(pHash, 0, sizeof(IdxHash)); }
static void idxHashClear(IdxHash *pHash) {
  int i;
  for (i = 0; i < 1023; i++) {
    IdxHashEntry *pEntry;
    IdxHashEntry *pNext;
    for (pEntry = pHash->aHash[i]; pEntry; pEntry = pNext) {
      pNext = pEntry->pHashNext;
      sqlite3_free(pEntry->zVal2);
      sqlite3_free(pEntry);
    }
  }
  memset(pHash, 0, sizeof(IdxHash));
}
static int idxHashString(const char *z, int n) {
  unsigned int ret = 0;
  int i;
  for (i = 0; i < n; i++) {
    ret += (ret << 3) + (unsigned char)(z[i]);
  }
  return (int)(ret % 1023);
}
static int idxHashAdd(int *pRc, IdxHash *pHash, const char *zKey,
                      const char *zVal) {
  int nKey = (int)strlen(zKey);
  int iHash = idxHashString(zKey, nKey);
  int nVal = (zVal ? (int)strlen(zVal) : 0);
  IdxHashEntry *pEntry;
  ((void)sizeof((iHash >= 0) ? 1 : 0), ({
     if (iHash >= 0)
       ;
     else
       __assert_fail("iHash>=0", "shell.c", 10777, __PRETTY_FUNCTION__);
   }));
  for (pEntry = pHash->aHash[iHash]; pEntry; pEntry = pEntry->pHashNext) {
    if ((int)strlen(pEntry->zKey) == nKey &&
        0 == memcmp(pEntry->zKey, zKey, nKey)) {
      return 1;
    }
  }
  pEntry = idxMalloc(pRc, sizeof(IdxHashEntry) + nKey + 1 + nVal + 1);
  if (pEntry) {
    pEntry->zKey = (char *)&pEntry[1];
    memcpy(pEntry->zKey, zKey, nKey);
    if (zVal) {
      pEntry->zVal = &pEntry->zKey[nKey + 1];
      memcpy(pEntry->zVal, zVal, nVal);
    }
    pEntry->pHashNext = pHash->aHash[iHash];
    pHash->aHash[iHash] = pEntry;
    pEntry->pNext = pHash->pFirst;
    pHash->pFirst = pEntry;
  }
  return 0;
}
static IdxHashEntry *idxHashFind(IdxHash *pHash, const char *zKey, int nKey) {
  int iHash;
  IdxHashEntry *pEntry;
  if (nKey < 0)
    nKey = (int)strlen(zKey);
  iHash = idxHashString(zKey, nKey);
  ((void)sizeof((iHash >= 0) ? 1 : 0), ({
     if (iHash >= 0)
       ;
     else
       __assert_fail("iHash>=0", "shell.c", 10809, __PRETTY_FUNCTION__);
   }));
  for (pEntry = pHash->aHash[iHash]; pEntry; pEntry = pEntry->pHashNext) {
    if ((int)strlen(pEntry->zKey) == nKey &&
        0 == memcmp(pEntry->zKey, zKey, nKey)) {
      return pEntry;
    }
  }
  return 0;
}
static const char *idxHashSearch(IdxHash *pHash, const char *zKey, int nKey) {
  IdxHashEntry *pEntry = idxHashFind(pHash, zKey, nKey);
  if (pEntry)
    return pEntry->zVal;
  return 0;
}
static IdxConstraint *idxNewConstraint(int *pRc, const char *zColl) {
  IdxConstraint *pNew;
  int nColl = (int)strlen(zColl);
  ((void)sizeof((*pRc == 0) ? 1 : 0), ({
     if (*pRc == 0)
       ;
     else
       __assert_fail("*pRc==SQLITE_OK", "shell.c", 10838, __PRETTY_FUNCTION__);
   }));
  pNew = (IdxConstraint *)idxMalloc(pRc, sizeof(IdxConstraint) * nColl + 1);
  if (pNew) {
    pNew->zColl = (char *)&pNew[1];
    memcpy(pNew->zColl, zColl, nColl + 1);
  }
  return pNew;
}
static void idxDatabaseError(sqlite3 *db, char **pzErrmsg) {
  *pzErrmsg = sqlite3_mprintf("%s", sqlite3_errmsg(db));
}
static int idxPrepareStmt(sqlite3 *db, sqlite3_stmt **ppStmt, char **pzErrmsg,
                          const char *zSql) {
  int rc = sqlite3_prepare_v2(db, zSql, -1, ppStmt, 0);
  if (rc != 0) {
    *ppStmt = 0;
    idxDatabaseError(db, pzErrmsg);
  }
  return rc;
}
static int idxPrintfPrepareStmt(sqlite3 *db, sqlite3_stmt **ppStmt,
                                char **pzErrmsg, const char *zFmt, ...) {
  va_list ap;
  int rc;
  char *zSql;
  __builtin_va_start(ap, zFmt);
  zSql = sqlite3_vmprintf(zFmt, ap);
  if (zSql == 0) {
    rc = 7;
  } else {
    rc = idxPrepareStmt(db, ppStmt, pzErrmsg, zSql);
    sqlite3_free(zSql);
  }
  __builtin_va_end(ap);
  return rc;
}
typedef struct ExpertVtab ExpertVtab;
struct ExpertVtab {
  sqlite3_vtab base;
  IdxTable *pTab;
  sqlite3expert *pExpert;
};
typedef struct ExpertCsr ExpertCsr;
struct ExpertCsr {
  sqlite3_vtab_cursor base;
  sqlite3_stmt *pData;
};
static char *expertDequote(const char *zIn) {
  int n = (int)strlen(zIn);
  char *zRet = sqlite3_malloc(n);
  ((void)sizeof((zIn[0] == '\'') ? 1 : 0), ({
     if (zIn[0] == '\'')
       ;
     else
       __assert_fail("zIn[0]=='\\''", "shell.c", 10921, __PRETTY_FUNCTION__);
   }));
  ((void)sizeof((zIn[n - 1] == '\'') ? 1 : 0), ({
     if (zIn[n - 1] == '\'')
       ;
     else
       __assert_fail("zIn[n-1]=='\\''", "shell.c", 10922, __PRETTY_FUNCTION__);
   }));
  if (zRet) {
    int iOut = 0;
    int iIn = 0;
    for (iIn = 1; iIn < (n - 1); iIn++) {
      if (zIn[iIn] == '\'') {
        ((void)sizeof((zIn[iIn + 1] == '\'') ? 1 : 0), ({
           if (zIn[iIn + 1] == '\'')
             ;
           else
             __assert_fail("zIn[iIn+1]=='\\''", "shell.c", 10929,
                           __PRETTY_FUNCTION__);
         }));
        iIn++;
      }
      zRet[iOut++] = zIn[iIn];
    }
    zRet[iOut] = 'A';
  }
  return zRet;
}
static int expertConnect(sqlite3 *db, void *pAux, int argc,
                         const char *const *argv, sqlite3_vtab **ppVtab,
                         char **pzErr) {
  sqlite3expert *pExpert = (sqlite3expert *)pAux;
  ExpertVtab *p = 0;
  int rc;
  if (argc != 4) {
    *pzErr = sqlite3_mprintf("internal error!");
    rc = 1;
  } else {
    char *zCreateTable = expertDequote(argv[3]);
    if (zCreateTable) {
      rc = sqlite3_declare_vtab(db, zCreateTable);
      if (rc == 0) {
        p = idxMalloc(&rc, sizeof(ExpertVtab));
      }
      if (rc == 0) {
        p->pExpert = pExpert;
        p->pTab = pExpert->pTable;
        ((void)sizeof((sqlite3_stricmp(p->pTab->zName, argv[2]) == 0) ? 1 : 0),
         ({
           if (sqlite3_stricmp(p->pTab->zName, argv[2]) == 0)
             ;
           else
             __assert_fail("sqlite3_stricmp(p->pTab->zName, argv[2])==0",
                           "shell.c", 10973, __PRETTY_FUNCTION__);
         }));
      }
      sqlite3_free(zCreateTable);
    } else {
      rc = 7;
    }
  }
  *ppVtab = (sqlite3_vtab *)p;
  return rc;
}
static int expertDisconnect(sqlite3_vtab *pVtab) {
  ExpertVtab *p = (ExpertVtab *)pVtab;
  sqlite3_free(p);
  return 0;
}
static int expertBestIndex(sqlite3_vtab *pVtab, sqlite3_index_info *pIdxInfo) {
  ExpertVtab *p = (ExpertVtab *)pVtab;
  int rc = 0;
  int n = 0;
  IdxScan *pScan;
  const int opmask = 2 | 4 | 16 | 32 | 8;
  pScan = idxMalloc(&rc, sizeof(IdxScan));
  if (pScan) {
    int i;
    pScan->pTab = p->pTab;
    pScan->pNextScan = p->pExpert->pScan;
    p->pExpert->pScan = pScan;
    for (i = 0; i < pIdxInfo->nConstraint; i++) {
      struct sqlite3_index_constraint *pCons = &pIdxInfo->aConstraint[i];
      if (pCons->usable && pCons->iColumn >= 0 &&
          p->pTab->aCol[pCons->iColumn].iPk == 0 && (pCons->op & opmask)) {
        IdxConstraint *pNew;
        const char *zColl = sqlite3_vtab_collation(pIdxInfo, i);
        pNew = idxNewConstraint(&rc, zColl);
        if (pNew) {
          pNew->iCol = pCons->iColumn;
          if (pCons->op == 2) {
            pNew->pNext = pScan->pEq;
            pScan->pEq = pNew;
          } else {
            pNew->bRange = 1;
            pNew->pNext = pScan->pRange;
            pScan->pRange = pNew;
          }
        }
        n++;
        pIdxInfo->aConstraintUsage[i].argvIndex = n;
      }
    }
    for (i = pIdxInfo->nOrderBy - 1; i >= 0; i--) {
      int iCol = pIdxInfo->aOrderBy[i].iColumn;
      if (iCol >= 0) {
        IdxConstraint *pNew = idxNewConstraint(&rc, p->pTab->aCol[iCol].zColl);
        if (pNew) {
          pNew->iCol = iCol;
          pNew->bDesc = pIdxInfo->aOrderBy[i].desc;
          pNew->pNext = pScan->pOrder;
          pNew->pLink = pScan->pOrder;
          pScan->pOrder = pNew;
          n++;
        }
      }
    }
  }
  pIdxInfo->estimatedCost = 1000000.000000 / (n + 1);
  return rc;
}
static int expertUpdate(sqlite3_vtab *pVtab, int nData, sqlite3_value **azData,
                        sqlite_int64 *pRowid) {
  (void)pVtab;
  (void)nData;
  (void)azData;
  (void)pRowid;
  return 0;
}
static int expertOpen(sqlite3_vtab *pVTab, sqlite3_vtab_cursor **ppCursor) {
  int rc = 0;
  ExpertCsr *pCsr;
  (void)pVTab;
  pCsr = idxMalloc(&rc, sizeof(ExpertCsr));
  *ppCursor = (sqlite3_vtab_cursor *)pCsr;
  return rc;
}
static int expertClose(sqlite3_vtab_cursor *cur) {
  ExpertCsr *pCsr = (ExpertCsr *)cur;
  sqlite3_finalize(pCsr->pData);
  sqlite3_free(pCsr);
  return 0;
}
static int expertEof(sqlite3_vtab_cursor *cur) {
  ExpertCsr *pCsr = (ExpertCsr *)cur;
  return pCsr->pData == 0;
}
static int expertNext(sqlite3_vtab_cursor *cur) {
  ExpertCsr *pCsr = (ExpertCsr *)cur;
  int rc = 0;
  ((void)sizeof((pCsr->pData) ? 1 : 0), ({
     if (pCsr->pData)
       ;
     else
       __assert_fail("pCsr->pData", "shell.c", 11111, __PRETTY_FUNCTION__);
   }));
  rc = sqlite3_step(pCsr->pData);
  if (rc != 100) {
    rc = sqlite3_finalize(pCsr->pData);
    pCsr->pData = 0;
  } else {
    rc = 0;
  }
  return rc;
}
static int expertRowid(sqlite3_vtab_cursor *cur, sqlite_int64 *pRowid) {
  (void)cur;
  *pRowid = 0;
  return 0;
}
static int expertColumn(sqlite3_vtab_cursor *cur, sqlite3_context *ctx, int i) {
  ExpertCsr *pCsr = (ExpertCsr *)cur;
  sqlite3_value *pVal;
  pVal = sqlite3_column_value(pCsr->pData, i);
  if (pVal) {
    sqlite3_result_value(ctx, pVal);
  }
  return 0;
}
static int expertFilter(sqlite3_vtab_cursor *cur, int idxNum,
                        const char *idxStr, int argc, sqlite3_value **argv) {
  ExpertCsr *pCsr = (ExpertCsr *)cur;
  ExpertVtab *pVtab = (ExpertVtab *)(cur->pVtab);
  sqlite3expert *pExpert = pVtab->pExpert;
  int rc;
  (void)idxNum;
  (void)idxStr;
  (void)argc;
  (void)argv;
  rc = sqlite3_finalize(pCsr->pData);
  pCsr->pData = 0;
  if (rc == 0) {
    rc = idxPrintfPrepareStmt(pExpert->db, &pCsr->pData, &pVtab->base.zErrMsg,
                              "SELECT * FROM main.%Q WHERE sample()",
                              pVtab->pTab->zName);
  }
  if (rc == 0) {
    rc = expertNext(cur);
  }
  return rc;
}
static int idxRegisterVtab(sqlite3expert *p) {
  static sqlite3_module expertModule = {2,
                                        expertConnect,
                                        expertConnect,
                                        expertBestIndex,
                                        expertDisconnect,
                                        expertDisconnect,
                                        expertOpen,
                                        expertClose,
                                        expertFilter,
                                        expertNext,
                                        expertEof,
                                        expertColumn,
                                        expertRowid,
                                        expertUpdate,
                                        0,
                                        0,
                                        0,
                                        0,
                                        0,
                                        0,
                                        0,
                                        0,
                                        0,
                                        0};
  return sqlite3_create_module(p->dbv, "expert", &expertModule, (void *)p);
}
static void idxFinalize(int *pRc, sqlite3_stmt *pStmt) {
  int rc = sqlite3_finalize(pStmt);
  if (*pRc == 0)
    *pRc = rc;
}
static int idxGetTableInfo(sqlite3 *db, const char *zTab, IdxTable **ppOut,
                           char **pzErrmsg) {
  sqlite3_stmt *p1 = 0;
  int nCol = 0;
  int nTab;
  int nByte;
  IdxTable *pNew = 0;
  int rc, rc2;
  char *pCsr = 0;
  int nPk = 0;
  *ppOut = 0;
  if (zTab == 0)
    return 1;
  nTab = (int)strlen(zTab);
  nByte = sizeof(IdxTable) + nTab + 1;
  rc = idxPrintfPrepareStmt(db, &p1, pzErrmsg, "PRAGMA table_xinfo=%Q", zTab);
  while (rc == 0 && 100 == sqlite3_step(p1)) {
    const char *zCol = (const char *)sqlite3_column_text(p1, 1);
    const char *zColSeq = 0;
    if (zCol == 0) {
      rc = 1;
      break;
    }
    nByte += 1 + (int)strlen(zCol);
    rc = sqlite3_table_column_metadata(db, "main", zTab, zCol, 0, &zColSeq, 0,
                                       0, 0);
    if (zColSeq == 0)
      zColSeq = "binary";
    nByte += 1 + (int)strlen(zColSeq);
    nCol++;
    nPk += (sqlite3_column_int(p1, 5) > 0);
  }
  rc2 = sqlite3_reset(p1);
  if (rc == 0)
    rc = rc2;
  nByte += sizeof(IdxColumn) * nCol;
  if (rc == 0) {
    pNew = idxMalloc(&rc, nByte);
  }
  if (rc == 0) {
    pNew->aCol = (IdxColumn *)&pNew[1];
    pNew->nCol = nCol;
    pCsr = (char *)&pNew->aCol[nCol];
  }
  nCol = 0;
  while (rc == 0 && 100 == sqlite3_step(p1)) {
    const char *zCol = (const char *)sqlite3_column_text(p1, 1);
    const char *zColSeq = 0;
    int nCopy;
    if (zCol == 0)
      continue;
    nCopy = (int)strlen(zCol) + 1;
    pNew->aCol[nCol].zName = pCsr;
    pNew->aCol[nCol].iPk = (sqlite3_column_int(p1, 5) == 1 && nPk == 1);
    memcpy(pCsr, zCol, nCopy);
    pCsr += nCopy;
    rc = sqlite3_table_column_metadata(db, "main", zTab, zCol, 0, &zColSeq, 0,
                                       0, 0);
    if (rc == 0) {
      if (zColSeq == 0)
        zColSeq = "binary";
      nCopy = (int)strlen(zColSeq) + 1;
      pNew->aCol[nCol].zColl = pCsr;
      memcpy(pCsr, zColSeq, nCopy);
      pCsr += nCopy;
    }
    nCol++;
  }
  idxFinalize(&rc, p1);
  if (rc != 0) {
    sqlite3_free(pNew);
    pNew = 0;
  } else if (((pNew != 0) ? 1
                          : (((void)sizeof((0) ? 1 : 0), ({
                                if (0)
                                  ;
                                else
                                  __assert_fail("0", "shell.c", 11308,
                                                __PRETTY_FUNCTION__);
                              })),
                             0))) {
    pNew->zName = pCsr;
    if (((pNew->zName != 0) ? 1
                            : (((void)sizeof((0) ? 1 : 0), ({
                                  if (0)
                                    ;
                                  else
                                    __assert_fail("0", "shell.c", 11310,
                                                  __PRETTY_FUNCTION__);
                                })),
                               0)))
      memcpy(pNew->zName, zTab, nTab + 1);
  }
  *ppOut = pNew;
  return rc;
}
static char *idxAppendText(int *pRc, char *zIn, const char *zFmt, ...) {
  va_list ap;
  char *zAppend = 0;
  char *zRet = 0;
  int nIn = zIn ? (int)strlen(zIn) : 0;
  int nAppend = 0;
  __builtin_va_start(ap, zFmt);
  if (*pRc == 0) {
    zAppend = sqlite3_vmprintf(zFmt, ap);
    if (zAppend) {
      nAppend = (int)strlen(zAppend);
      zRet = (char *)sqlite3_malloc(nIn + nAppend + 1);
    }
    if (zAppend && zRet) {
      if (nIn)
        memcpy(zRet, zIn, nIn);
      memcpy(&zRet[nIn], zAppend, nAppend + 1);
    } else {
      sqlite3_free(zRet);
      zRet = 0;
      *pRc = 7;
    }
    sqlite3_free(zAppend);
    sqlite3_free(zIn);
  }
  __builtin_va_end(ap);
  return zRet;
}
static int idxIdentifierRequiresQuotes(const char *zId) {
  int i;
  int nId = (int)strlen(zId);
  if (sqlite3_keyword_check(zId, nId))
    return 1;
  for (i = 0; zId[i]; i++) {
    if (!(zId[i] == '_') && !(zId[i] >= '0' && zId[i] <= '9') &&
        !(zId[i] >= 'a' && zId[i] <= 'z') &&
        !(zId[i] >= 'A' && zId[i] <= 'Z')) {
      return 1;
    }
  }
  return 0;
}
static char *idxAppendColDefn(int *pRc, char *zIn, IdxTable *pTab,
                              IdxConstraint *pCons) {
  char *zRet = zIn;
  IdxColumn *p = &pTab->aCol[pCons->iCol];
  if (zRet)
    zRet = idxAppendText(pRc, zRet, ", ");
  if (idxIdentifierRequiresQuotes(p->zName)) {
    zRet = idxAppendText(pRc, zRet, "%Q", p->zName);
  } else {
    zRet = idxAppendText(pRc, zRet, "%s", p->zName);
  }
  if (sqlite3_stricmp(p->zColl, pCons->zColl)) {
    if (idxIdentifierRequiresQuotes(pCons->zColl)) {
      zRet = idxAppendText(pRc, zRet, " COLLATE %Q", pCons->zColl);
    } else {
      zRet = idxAppendText(pRc, zRet, " COLLATE %s", pCons->zColl);
    }
  }
  if (pCons->bDesc) {
    zRet = idxAppendText(pRc, zRet, " DESC");
  }
  return zRet;
}
static int idxFindCompatible(int *pRc, sqlite3 *dbm, IdxScan *pScan,
                             IdxConstraint *pEq, IdxConstraint *pTail) {
  const char *zTbl = pScan->pTab->zName;
  sqlite3_stmt *pIdxList = 0;
  IdxConstraint *pIter;
  int nEq = 0;
  int rc;
  for (pIter = pEq; pIter; pIter = pIter->pLink)
    nEq++;
  rc = idxPrintfPrepareStmt(dbm, &pIdxList, 0, "PRAGMA index_list=%Q", zTbl);
  while (rc == 0 && sqlite3_step(pIdxList) == 100) {
    int bMatch = 1;
    IdxConstraint *pT = pTail;
    sqlite3_stmt *pInfo = 0;
    const char *zIdx = (const char *)sqlite3_column_text(pIdxList, 1);
    if (zIdx == 0)
      continue;
    for (pIter = pEq; pIter; pIter = pIter->pLink)
      pIter->bFlag = 0;
    rc = idxPrintfPrepareStmt(dbm, &pInfo, 0, "PRAGMA index_xInfo=%Q", zIdx);
    while (rc == 0 && sqlite3_step(pInfo) == 100) {
      int iIdx = sqlite3_column_int(pInfo, 0);
      int iCol = sqlite3_column_int(pInfo, 1);
      const char *zColl = (const char *)sqlite3_column_text(pInfo, 4);
      if (iIdx < nEq) {
        for (pIter = pEq; pIter; pIter = pIter->pLink) {
          if (pIter->bFlag)
            continue;
          if (pIter->iCol != iCol)
            continue;
          if (sqlite3_stricmp(pIter->zColl, zColl))
            continue;
          pIter->bFlag = 1;
          break;
        }
        if (pIter == 0) {
          bMatch = 0;
          break;
        }
      } else {
        if (pT) {
          if (pT->iCol != iCol || sqlite3_stricmp(pT->zColl, zColl)) {
            bMatch = 0;
            break;
          }
          pT = pT->pLink;
        }
      }
    }
    idxFinalize(&rc, pInfo);
    if (rc == 0 && bMatch) {
      sqlite3_finalize(pIdxList);
      return 1;
    }
  }
  idxFinalize(&rc, pIdxList);
  *pRc = rc;
  return 0;
}
static int countNonzeros(void *pCount, int nc, char *azResults[],
                         char *azColumns[]) {
  (void)azColumns;
  if (nc > 0 && (azResults[0][0] != '0' || azResults[0][1] != 0)) {
    *((int *)pCount) += 1;
  }
  return 0;
}
static int idxCreateFromCons(sqlite3expert *p, IdxScan *pScan,
                             IdxConstraint *pEq, IdxConstraint *pTail) {
  sqlite3 *dbm = p->dbm;
  int rc = 0;
  if ((pEq || pTail) && 0 == idxFindCompatible(&rc, dbm, pScan, pEq, pTail)) {
    IdxTable *pTab = pScan->pTab;
    char *zCols = 0;
    char *zIdx = 0;
    IdxConstraint *pCons;
    unsigned int h = 0;
    const char *zFmt;
    for (pCons = pEq; pCons; pCons = pCons->pLink) {
      zCols = idxAppendColDefn(&rc, zCols, pTab, pCons);
    }
    for (pCons = pTail; pCons; pCons = pCons->pLink) {
      zCols = idxAppendColDefn(&rc, zCols, pTab, pCons);
    }
    if (rc == 0) {
      const char *zTable = pScan->pTab->zName;
      int quoteTable = idxIdentifierRequiresQuotes(zTable);
      char *zName = 0;
      int collisions = 0;
      do {
        int i;
        char *zFind;
        for (i = 0; zCols[i]; i++) {
          h += ((h << 3) + zCols[i]);
        }
        sqlite3_free(zName);
        zName = sqlite3_mprintf("%s_idx_%08x", zTable, h);
        if (zName == 0)
          break;
        zFmt = "SELECT count(*) FROM sqlite_schema WHERE name=%Q AND type in "
               "('index','table','view')";
        zFind = sqlite3_mprintf(zFmt, zName);
        i = 0;
        rc = sqlite3_exec(dbm, zFind, countNonzeros, &i, 0);
        ((void)sizeof((rc == 0) ? 1 : 0), ({
           if (rc == 0)
             ;
           else
             __assert_fail("rc==SQLITE_OK", "shell.c", 11543,
                           __PRETTY_FUNCTION__);
         }));
        sqlite3_free(zFind);
        if (i == 0) {
          collisions = 0;
          break;
        }
        ++collisions;
      } while (collisions < 50 && zName != 0);
      if (collisions) {
        rc = (5 | (3 << 8));
      } else if (zName == 0) {
        rc = 7;
      } else {
        if (quoteTable) {
          zFmt = "CREATE INDEX \"%w\" ON \"%w\"(%s)";
        } else {
          zFmt = "CREATE INDEX %s ON %s(%s)";
        }
        zIdx = sqlite3_mprintf(zFmt, zName, zTable, zCols);
        if (!zIdx) {
          rc = 7;
        } else {
          rc = sqlite3_exec(dbm, zIdx, 0, 0, p->pzErrmsg);
          if (rc != 0) {
            rc = (5 | (3 << 8));
          } else {
            idxHashAdd(&rc, &p->hIdx, zName, zIdx);
          }
        }
        sqlite3_free(zName);
        sqlite3_free(zIdx);
      }
    }
    sqlite3_free(zCols);
  }
  return rc;
}
static int idxFindConstraint(IdxConstraint *pList, IdxConstraint *p) {
  IdxConstraint *pCmp;
  for (pCmp = pList; pCmp; pCmp = pCmp->pLink) {
    if (p->iCol == pCmp->iCol)
      return 1;
  }
  return 0;
}
static int idxCreateFromWhere(sqlite3expert *p, IdxScan *pScan,
                              IdxConstraint *pTail) {
  IdxConstraint *p1 = 0;
  IdxConstraint *pCon;
  int rc;
  for (pCon = pScan->pEq; pCon; pCon = pCon->pNext) {
    if (!idxFindConstraint(p1, pCon) && !idxFindConstraint(pTail, pCon)) {
      pCon->pLink = p1;
      p1 = pCon;
    }
  }
  rc = idxCreateFromCons(p, pScan, p1, pTail);
  if (pTail == 0) {
    for (pCon = pScan->pRange; rc == 0 && pCon; pCon = pCon->pNext) {
      ((void)sizeof((pCon->pLink == 0) ? 1 : 0), ({
         if (pCon->pLink == 0)
           ;
         else
           __assert_fail("pCon->pLink==0", "shell.c", 11620,
                         __PRETTY_FUNCTION__);
       }));
      if (!idxFindConstraint(p1, pCon) && !idxFindConstraint(pTail, pCon)) {
        rc = idxCreateFromCons(p, pScan, p1, pCon);
      }
    }
  }
  return rc;
}
static int idxCreateCandidates(sqlite3expert *p) {
  int rc = 0;
  IdxScan *pIter;
  for (pIter = p->pScan; pIter && rc == 0; pIter = pIter->pNextScan) {
    rc = idxCreateFromWhere(p, pIter, 0);
    if (rc == 0 && pIter->pOrder) {
      rc = idxCreateFromWhere(p, pIter, pIter->pOrder);
    }
  }
  return rc;
}
static void idxConstraintFree(IdxConstraint *pConstraint) {
  IdxConstraint *pNext;
  IdxConstraint *p;
  for (p = pConstraint; p; p = pNext) {
    pNext = p->pNext;
    sqlite3_free(p);
  }
}
static void idxScanFree(IdxScan *pScan, IdxScan *pLast) {
  IdxScan *p;
  IdxScan *pNext;
  for (p = pScan; p != pLast; p = pNext) {
    pNext = p->pNextScan;
    idxConstraintFree(p->pOrder);
    idxConstraintFree(p->pEq);
    idxConstraintFree(p->pRange);
    sqlite3_free(p);
  }
}
static void idxStatementFree(IdxStatement *pStatement, IdxStatement *pLast) {
  IdxStatement *p;
  IdxStatement *pNext;
  for (p = pStatement; p != pLast; p = pNext) {
    pNext = p->pNext;
    sqlite3_free(p->zEQP);
    sqlite3_free(p->zIdx);
    sqlite3_free(p);
  }
}
static void idxTableFree(IdxTable *pTab) {
  IdxTable *pIter;
  IdxTable *pNext;
  for (pIter = pTab; pIter; pIter = pNext) {
    pNext = pIter->pNext;
    sqlite3_free(pIter);
  }
}
static void idxWriteFree(IdxWrite *pTab) {
  IdxWrite *pIter;
  IdxWrite *pNext;
  for (pIter = pTab; pIter; pIter = pNext) {
    pNext = pIter->pNext;
    sqlite3_free(pIter);
  }
}
static int idxFindIndexes(sqlite3expert *p, char **pzErr) {
  IdxStatement *pStmt;
  sqlite3 *dbm = p->dbm;
  int rc = 0;
  IdxHash hIdx;
  idxHashInit(&hIdx);
  for (pStmt = p->pStatement; rc == 0 && pStmt; pStmt = pStmt->pNext) {
    IdxHashEntry *pEntry;
    sqlite3_stmt *pExplain = 0;
    idxHashClear(&hIdx);
    rc = idxPrintfPrepareStmt(dbm, &pExplain, pzErr, "EXPLAIN QUERY PLAN %s",
                              pStmt->zSql);
    while (rc == 0 && sqlite3_step(pExplain) == 100) {
      const char *zDetail = (const char *)sqlite3_column_text(pExplain, 3);
      int nDetail;
      int i;
      if (!zDetail)
        continue;
      nDetail = (int)strlen(zDetail);
      for (i = 0; i < nDetail; i++) {
        const char *zIdx = 0;
        if (i + 13 < nDetail && memcmp(&zDetail[i], " USING INDEX ", 13) == 0) {
          zIdx = &zDetail[i + 13];
        } else if (i + 22 < nDetail &&
                   memcmp(&zDetail[i], " USING COVERING INDEX ", 22) == 0) {
          zIdx = &zDetail[i + 22];
        }
        if (zIdx) {
          const char *zSql;
          int nIdx = 0;
          while (zIdx[nIdx] != 'A' &&
                 (zIdx[nIdx] != ' ' || zIdx[nIdx + 1] != '(')) {
            nIdx++;
          }
          zSql = idxHashSearch(&p->hIdx, zIdx, nIdx);
          if (zSql) {
            idxHashAdd(&rc, &hIdx, zSql, 0);
            if (rc)
              goto find_indexes_out;
          }
          break;
        }
      }
      if (zDetail[0] != '-') {
        pStmt->zEQP = idxAppendText(&rc, pStmt->zEQP, "%s\n", zDetail);
      }
    }
    for (pEntry = hIdx.pFirst; pEntry; pEntry = pEntry->pNext) {
      pStmt->zIdx = idxAppendText(&rc, pStmt->zIdx, "%s;\n", pEntry->zKey);
    }
    idxFinalize(&rc, pExplain);
  }
find_indexes_out:
  idxHashClear(&hIdx);
  return rc;
}
static int idxAuthCallback(void *pCtx, int eOp, const char *z3, const char *z4,
                           const char *zDb, const char *zTrigger) {
  int rc = 0;
  (void)z4;
  (void)zTrigger;
  if (eOp == 18 || eOp == 23 || eOp == 9) {
    if (sqlite3_stricmp(zDb, "main") == 0) {
      sqlite3expert *p = (sqlite3expert *)pCtx;
      IdxTable *pTab;
      for (pTab = p->pTable; pTab; pTab = pTab->pNext) {
        if (0 == sqlite3_stricmp(z3, pTab->zName))
          break;
      }
      if (pTab) {
        IdxWrite *pWrite;
        for (pWrite = p->pWrite; pWrite; pWrite = pWrite->pNext) {
          if (pWrite->pTab == pTab && pWrite->eOp == eOp)
            break;
        }
        if (pWrite == 0) {
          pWrite = idxMalloc(&rc, sizeof(IdxWrite));
          if (rc == 0) {
            pWrite->pTab = pTab;
            pWrite->eOp = eOp;
            pWrite->pNext = p->pWrite;
            p->pWrite = pWrite;
          }
        }
      }
    }
  }
  return rc;
}
static int idxProcessOneTrigger(sqlite3expert *p, IdxWrite *pWrite,
                                char **pzErr) {
  static const char *zInt = "t592690916721053953805701627921227776";
  static const char *zDrop = "DROP TABLE t592690916721053953805701627921227776";
  IdxTable *pTab = pWrite->pTab;
  const char *zTab = pTab->zName;
  const char *zSql =
      "SELECT 'CREATE TEMP' || substr(sql, 7) FROM sqlite_schema WHERE "
      "tbl_name = %Q AND type IN ('table', 'trigger') ORDER BY type;";
  sqlite3_stmt *pSelect = 0;
  int rc = 0;
  char *zWrite = 0;
  rc = idxPrintfPrepareStmt(p->db, &pSelect, pzErr, zSql, zTab, zTab);
  while (rc == 0 && 100 == sqlite3_step(pSelect)) {
    const char *zCreate = (const char *)sqlite3_column_text(pSelect, 0);
    if (zCreate == 0)
      continue;
    rc = sqlite3_exec(p->dbv, zCreate, 0, 0, pzErr);
  }
  idxFinalize(&rc, pSelect);
  if (rc == 0) {
    char *z = sqlite3_mprintf("ALTER TABLE temp.%Q RENAME TO %Q", zTab, zInt);
    if (z == 0) {
      rc = 7;
    } else {
      rc = sqlite3_exec(p->dbv, z, 0, 0, pzErr);
      sqlite3_free(z);
    }
  }
  switch (pWrite->eOp) {
  case 18: {
    int i;
    zWrite = idxAppendText(&rc, zWrite, "INSERT INTO %Q VALUES(", zInt);
    for (i = 0; i < pTab->nCol; i++) {
      zWrite = idxAppendText(&rc, zWrite, "%s?", i == 0 ? "" : ", ");
    }
    zWrite = idxAppendText(&rc, zWrite, ")");
    break;
  }
  case 23: {
    int i;
    zWrite = idxAppendText(&rc, zWrite, "UPDATE %Q SET ", zInt);
    for (i = 0; i < pTab->nCol; i++) {
      zWrite = idxAppendText(&rc, zWrite, "%s%Q=?", i == 0 ? "" : ", ",
                             pTab->aCol[i].zName);
    }
    break;
  }
  default: {
    ((void)sizeof((pWrite->eOp == 9) ? 1 : 0), ({
       if (pWrite->eOp == 9)
         ;
       else
         __assert_fail("pWrite->eOp==SQLITE_DELETE", "shell.c", 11889,
                       __PRETTY_FUNCTION__);
     }));
    if (rc == 0) {
      zWrite = sqlite3_mprintf("DELETE FROM %Q", zInt);
      if (zWrite == 0)
        rc = 7;
    }
  }
  }
  if (rc == 0) {
    sqlite3_stmt *pX = 0;
    rc = sqlite3_prepare_v2(p->dbv, zWrite, -1, &pX, 0);
    idxFinalize(&rc, pX);
    if (rc != 0) {
      idxDatabaseError(p->dbv, pzErr);
    }
  }
  sqlite3_free(zWrite);
  if (rc == 0) {
    rc = sqlite3_exec(p->dbv, zDrop, 0, 0, pzErr);
  }
  return rc;
}
static int idxProcessTriggers(sqlite3expert *p, char **pzErr) {
  int rc = 0;
  IdxWrite *pEnd = 0;
  IdxWrite *pFirst = p->pWrite;
  while (rc == 0 && pFirst != pEnd) {
    IdxWrite *pIter;
    for (pIter = pFirst; rc == 0 && pIter != pEnd; pIter = pIter->pNext) {
      rc = idxProcessOneTrigger(p, pIter, pzErr);
    }
    pEnd = pFirst;
    pFirst = p->pWrite;
  }
  return rc;
}
static int idxCreateVtabSchema(sqlite3expert *p, char **pzErrmsg) {
  int rc = idxRegisterVtab(p);
  sqlite3_stmt *pSchema = 0;
  rc = idxPrepareStmt(
      p->db, &pSchema, pzErrmsg,
      "SELECT type, name, sql, 1 FROM sqlite_schema WHERE type IN "
      "('table','view') AND name NOT LIKE 'sqlite_%%'  UNION ALL SELECT type, "
      "name, sql, 2 FROM sqlite_schema WHERE type = 'trigger'  AND tbl_name "
      "IN(SELECT name FROM sqlite_schema WHERE type = 'view') ORDER BY 4, 1");
  while (rc == 0 && 100 == sqlite3_step(pSchema)) {
    const char *zType = (const char *)sqlite3_column_text(pSchema, 0);
    const char *zName = (const char *)sqlite3_column_text(pSchema, 1);
    const char *zSql = (const char *)sqlite3_column_text(pSchema, 2);
    if (zType == 0 || zName == 0)
      continue;
    if (zType[0] == 'v' || zType[1] == 'r') {
      if (zSql)
        rc = sqlite3_exec(p->dbv, zSql, 0, 0, pzErrmsg);
    } else {
      IdxTable *pTab;
      rc = idxGetTableInfo(p->db, zName, &pTab, pzErrmsg);
      if (rc == 0) {
        int i;
        char *zInner = 0;
        char *zOuter = 0;
        pTab->pNext = p->pTable;
        p->pTable = pTab;
        zInner = idxAppendText(&rc, 0, "CREATE TABLE x(");
        for (i = 0; i < pTab->nCol; i++) {
          zInner = idxAppendText(&rc, zInner, "%s%Q COLLATE %s",
                                 (i == 0 ? "" : ", "), pTab->aCol[i].zName,
                                 pTab->aCol[i].zColl);
        }
        zInner = idxAppendText(&rc, zInner, ")");
        zOuter = idxAppendText(
            &rc, 0, "CREATE VIRTUAL TABLE %Q USING expert(%Q)", zName, zInner);
        if (rc == 0) {
          rc = sqlite3_exec(p->dbv, zOuter, 0, 0, pzErrmsg);
        }
        sqlite3_free(zInner);
        sqlite3_free(zOuter);
      }
    }
  }
  idxFinalize(&rc, pSchema);
  return rc;
}
struct IdxSampleCtx {
  int iTarget;
  double target;
  double nRow;
  double nRet;
};
static void idxSampleFunc(sqlite3_context *pCtx, int argc,
                          sqlite3_value **argv) {
  struct IdxSampleCtx *p = (struct IdxSampleCtx *)sqlite3_user_data(pCtx);
  int bRet;
  (void)argv;
  ((void)sizeof((argc == 0) ? 1 : 0), ({
     if (argc == 0)
       ;
     else
       __assert_fail("argc==0", "shell.c", 12009, __PRETTY_FUNCTION__);
   }));
  if (p->nRow == 0.000000) {
    bRet = 1;
  } else {
    bRet = (p->nRet / p->nRow) <= p->target;
    if (bRet == 0) {
      unsigned short rnd;
      sqlite3_randomness(2, (void *)&rnd);
      bRet = ((int)rnd % 100) <= p->iTarget;
    }
  }
  sqlite3_result_int(pCtx, bRet);
  p->nRow += 1.000000;
  p->nRet += (double)bRet;
}
struct IdxRemCtx {
  int nSlot;
  struct IdxRemSlot {
    int eType;
    i64 iVal;
    double rVal;
    int nByte;
    int n;
    char *z;
  } aSlot[1];
};
static void idxRemFunc(sqlite3_context *pCtx, int argc, sqlite3_value **argv) {
  struct IdxRemCtx *p = (struct IdxRemCtx *)sqlite3_user_data(pCtx);
  struct IdxRemSlot *pSlot;
  int iSlot;
  ((void)sizeof((argc == 2) ? 1 : 0), ({
     if (argc == 2)
       ;
     else
       __assert_fail("argc==2", "shell.c", 12049, __PRETTY_FUNCTION__);
   }));
  iSlot = sqlite3_value_int(argv[0]);
  ((void)sizeof((iSlot <= p->nSlot) ? 1 : 0), ({
     if (iSlot <= p->nSlot)
       ;
     else
       __assert_fail("iSlot<=p->nSlot", "shell.c", 12052, __PRETTY_FUNCTION__);
   }));
  pSlot = &p->aSlot[iSlot];
  switch (pSlot->eType) {
  case 5:
    break;
  case 1:
    sqlite3_result_int64(pCtx, pSlot->iVal);
    break;
  case 2:
    sqlite3_result_double(pCtx, pSlot->rVal);
    break;
  case 4:
    sqlite3_result_blob(pCtx, pSlot->z, pSlot->n,
                        ((sqlite3_destructor_type)-1));
    break;
  case 3:
    sqlite3_result_text(pCtx, pSlot->z, pSlot->n,
                        ((sqlite3_destructor_type)-1));
    break;
  }
  pSlot->eType = sqlite3_value_type(argv[1]);
  switch (pSlot->eType) {
  case 5:
    break;
  case 1:
    pSlot->iVal = sqlite3_value_int64(argv[1]);
    break;
  case 2:
    pSlot->rVal = sqlite3_value_double(argv[1]);
    break;
  case 4:
  case 3: {
    int nByte = sqlite3_value_bytes(argv[1]);
    const void *pData = 0;
    if (nByte > pSlot->nByte) {
      char *zNew = (char *)sqlite3_realloc(pSlot->z, nByte * 2);
      if (zNew == 0) {
        sqlite3_result_error_nomem(pCtx);
        return;
      }
      pSlot->nByte = nByte * 2;
      pSlot->z = zNew;
    }
    pSlot->n = nByte;
    if (pSlot->eType == 4) {
      pData = sqlite3_value_blob(argv[1]);
      if (pData)
        memcpy(pSlot->z, pData, nByte);
    } else {
      pData = sqlite3_value_text(argv[1]);
      memcpy(pSlot->z, pData, nByte);
    }
    break;
  }
  }
}
static int idxLargestIndex(sqlite3 *db, int *pnMax, char **pzErr) {
  int rc = 0;
  const char *zMax = "SELECT max(i.seqno) FROM   sqlite_schema AS s,   "
                     "pragma_index_list(s.name) AS l,   "
                     "pragma_index_info(l.name) AS i WHERE s.type = 'table'";
  sqlite3_stmt *pMax = 0;
  *pnMax = 0;
  rc = idxPrepareStmt(db, &pMax, pzErr, zMax);
  if (rc == 0 && 100 == sqlite3_step(pMax)) {
    *pnMax = sqlite3_column_int(pMax, 0) + 1;
  }
  idxFinalize(&rc, pMax);
  return rc;
}
static int idxPopulateOneStat1(sqlite3expert *p, sqlite3_stmt *pIndexXInfo,
                               sqlite3_stmt *pWriteStat, const char *zTab,
                               const char *zIdx, char **pzErr) {
  char *zCols = 0;
  char *zOrder = 0;
  char *zQuery = 0;
  int nCol = 0;
  int i;
  sqlite3_stmt *pQuery = 0;
  int *aStat = 0;
  int rc = 0;
  ((void)sizeof((p->iSample > 0) ? 1 : 0), ({
     if (p->iSample > 0)
       ;
     else
       __assert_fail("p->iSample>0", "shell.c", 12154, __PRETTY_FUNCTION__);
   }));
  sqlite3_bind_text(pIndexXInfo, 1, zIdx, -1, ((sqlite3_destructor_type)0));
  while (0 == rc && 100 == sqlite3_step(pIndexXInfo)) {
    const char *zComma = zCols == 0 ? "" : ", ";
    const char *zName = (const char *)sqlite3_column_text(pIndexXInfo, 0);
    const char *zColl = (const char *)sqlite3_column_text(pIndexXInfo, 1);
    zCols = idxAppendText(&rc, zCols, "%sx.%Q IS rem(%d, x.%Q) COLLATE %s",
                          zComma, zName, nCol, zName, zColl);
    zOrder = idxAppendText(&rc, zOrder, "%s%d", zComma, ++nCol);
  }
  sqlite3_reset(pIndexXInfo);
  if (rc == 0) {
    if (p->iSample == 100) {
      zQuery = sqlite3_mprintf("SELECT %s FROM %Q x ORDER BY %s", zCols, zTab,
                               zOrder);
    } else {
      zQuery = sqlite3_mprintf(
          "SELECT %s FROM temp.t592690916721053953805701627921227776 x ORDER "
          "BY %s",
          zCols, zOrder);
    }
  }
  sqlite3_free(zCols);
  sqlite3_free(zOrder);
  if (rc == 0) {
    sqlite3 *dbrem = (p->iSample == 100 ? p->db : p->dbv);
    rc = idxPrepareStmt(dbrem, &pQuery, pzErr, zQuery);
  }
  sqlite3_free(zQuery);
  if (rc == 0) {
    aStat = (int *)idxMalloc(&rc, sizeof(int) * (nCol + 1));
  }
  if (rc == 0 && 100 == sqlite3_step(pQuery)) {
    IdxHashEntry *pEntry;
    char *zStat = 0;
    for (i = 0; i <= nCol; i++)
      aStat[i] = 1;
    while (rc == 0 && 100 == sqlite3_step(pQuery)) {
      aStat[0]++;
      for (i = 0; i < nCol; i++) {
        if (sqlite3_column_int(pQuery, i) == 0)
          break;
      }
      for (; i < nCol; i++) {
        aStat[i + 1]++;
      }
    }
    if (rc == 0) {
      int s0 = aStat[0];
      zStat = sqlite3_mprintf("%d", s0);
      if (zStat == 0)
        rc = 7;
      for (i = 1; rc == 0 && i <= nCol; i++) {
        zStat =
            idxAppendText(&rc, zStat, " %d", (s0 + aStat[i] / 2) / aStat[i]);
      }
    }
    if (rc == 0) {
      sqlite3_bind_text(pWriteStat, 1, zTab, -1, ((sqlite3_destructor_type)0));
      sqlite3_bind_text(pWriteStat, 2, zIdx, -1, ((sqlite3_destructor_type)0));
      sqlite3_bind_text(pWriteStat, 3, zStat, -1, ((sqlite3_destructor_type)0));
      sqlite3_step(pWriteStat);
      rc = sqlite3_reset(pWriteStat);
    }
    pEntry = idxHashFind(&p->hIdx, zIdx, (int)strlen(zIdx));
    if (pEntry) {
      ((void)sizeof((pEntry->zVal2 == 0) ? 1 : 0), ({
         if (pEntry->zVal2 == 0)
           ;
         else
           __assert_fail("pEntry->zVal2==0", "shell.c", 12225,
                         __PRETTY_FUNCTION__);
       }));
      pEntry->zVal2 = zStat;
    } else {
      sqlite3_free(zStat);
    }
  }
  sqlite3_free(aStat);
  idxFinalize(&rc, pQuery);
  return rc;
}
static int idxBuildSampleTable(sqlite3expert *p, const char *zTab) {
  int rc;
  char *zSql;
  rc = sqlite3_exec(
      p->dbv, "DROP TABLE IF EXISTS temp.t592690916721053953805701627921227776",
      0, 0, 0);
  if (rc != 0)
    return rc;
  zSql =
      sqlite3_mprintf("CREATE TABLE temp.t592690916721053953805701627921227776 "
                      "AS SELECT * FROM %Q",
                      zTab);
  if (zSql == 0)
    return 7;
  rc = sqlite3_exec(p->dbv, zSql, 0, 0, 0);
  sqlite3_free(zSql);
  return rc;
}
static int idxPopulateStat1(sqlite3expert *p, char **pzErr) {
  int rc = 0;
  int nMax = 0;
  struct IdxRemCtx *pCtx = 0;
  struct IdxSampleCtx samplectx;
  int i;
  i64 iPrev = -100000;
  sqlite3_stmt *pAllIndex = 0;
  sqlite3_stmt *pIndexXInfo = 0;
  sqlite3_stmt *pWrite = 0;
  const char *zAllIndex =
      "SELECT s.rowid, s.name, l.name FROM   sqlite_schema AS s,   "
      "pragma_index_list(s.name) AS l WHERE s.type = 'table'";
  const char *zIndexXInfo =
      "SELECT name, coll FROM pragma_index_xinfo(?) WHERE key";
  const char *zWrite = "INSERT INTO sqlite_stat1 VALUES(?, ?, ?)";
  if (p->iSample == 0)
    return 0;
  rc = idxLargestIndex(p->dbm, &nMax, pzErr);
  if (nMax <= 0 || rc != 0)
    return rc;
  rc = sqlite3_exec(p->dbm, "ANALYZE; PRAGMA writable_schema=1", 0, 0, 0);
  if (rc == 0) {
    int nByte = sizeof(struct IdxRemCtx) + (sizeof(struct IdxRemSlot) * nMax);
    pCtx = (struct IdxRemCtx *)idxMalloc(&rc, nByte);
  }
  if (rc == 0) {
    sqlite3 *dbrem = (p->iSample == 100 ? p->db : p->dbv);
    rc = sqlite3_create_function(dbrem, "rem", 2, 1, (void *)pCtx, idxRemFunc,
                                 0, 0);
  }
  if (rc == 0) {
    rc = sqlite3_create_function(p->db, "sample", 0, 1, (void *)&samplectx,
                                 idxSampleFunc, 0, 0);
  }
  if (rc == 0) {
    pCtx->nSlot = nMax + 1;
    rc = idxPrepareStmt(p->dbm, &pAllIndex, pzErr, zAllIndex);
  }
  if (rc == 0) {
    rc = idxPrepareStmt(p->dbm, &pIndexXInfo, pzErr, zIndexXInfo);
  }
  if (rc == 0) {
    rc = idxPrepareStmt(p->dbm, &pWrite, pzErr, zWrite);
  }
  while (rc == 0 && 100 == sqlite3_step(pAllIndex)) {
    i64 iRowid = sqlite3_column_int64(pAllIndex, 0);
    const char *zTab = (const char *)sqlite3_column_text(pAllIndex, 1);
    const char *zIdx = (const char *)sqlite3_column_text(pAllIndex, 2);
    if (zTab == 0 || zIdx == 0)
      continue;
    if (p->iSample < 100 && iPrev != iRowid) {
      samplectx.target = (double)p->iSample / 100.000000;
      samplectx.iTarget = p->iSample;
      samplectx.nRow = 0.000000;
      samplectx.nRet = 0.000000;
      rc = idxBuildSampleTable(p, zTab);
      if (rc != 0)
        break;
    }
    rc = idxPopulateOneStat1(p, pIndexXInfo, pWrite, zTab, zIdx, pzErr);
    iPrev = iRowid;
  }
  if (rc == 0 && p->iSample < 100) {
    rc = sqlite3_exec(
        p->dbv,
        "DROP TABLE IF EXISTS temp.t592690916721053953805701627921227776", 0, 0,
        0);
  }
  idxFinalize(&rc, pAllIndex);
  idxFinalize(&rc, pIndexXInfo);
  idxFinalize(&rc, pWrite);
  if (pCtx) {
    for (i = 0; i < pCtx->nSlot; i++) {
      sqlite3_free(pCtx->aSlot[i].z);
    }
    sqlite3_free(pCtx);
  }
  if (rc == 0) {
    rc = sqlite3_exec(p->dbm, "ANALYZE sqlite_schema", 0, 0, 0);
  }
  sqlite3_exec(
      p->db, "DROP TABLE IF EXISTS temp.t592690916721053953805701627921227776",
      0, 0, 0);
  return rc;
}
sqlite3expert *sqlite3_expert_new(sqlite3 *db, char **pzErrmsg) {
  int rc = 0;
  sqlite3expert *pNew;
  pNew = (sqlite3expert *)idxMalloc(&rc, sizeof(sqlite3expert));
  if (rc == 0) {
    pNew->db = db;
    pNew->iSample = 100;
    rc = sqlite3_open(":memory:", &pNew->dbv);
  }
  if (rc == 0) {
    rc = sqlite3_open(":memory:", &pNew->dbm);
    if (rc == 0) {
      sqlite3_db_config(pNew->dbm, 1008, 1, (int *)0);
    }
  }
  if (rc == 0) {
    sqlite3_stmt *pSql = 0;
    rc = idxPrintfPrepareStmt(
        pNew->db, &pSql, pzErrmsg,
        "SELECT sql FROM sqlite_schema WHERE name NOT LIKE 'sqlite_%%' AND sql "
        "NOT LIKE 'CREATE VIRTUAL %%'");
    while (rc == 0 && 100 == sqlite3_step(pSql)) {
      const char *zSql = (const char *)sqlite3_column_text(pSql, 0);
      if (zSql)
        rc = sqlite3_exec(pNew->dbm, zSql, 0, 0, pzErrmsg);
    }
    idxFinalize(&rc, pSql);
  }
  if (rc == 0) {
    rc = idxCreateVtabSchema(pNew, pzErrmsg);
  }
  if (rc == 0) {
    sqlite3_set_authorizer(pNew->dbv, idxAuthCallback, (void *)pNew);
  }
  if (rc != 0) {
    sqlite3_expert_destroy(pNew);
    pNew = 0;
  }
  return pNew;
}
int sqlite3_expert_config(sqlite3expert *p, int op, ...) {
  int rc = 0;
  va_list ap;
  __builtin_va_start(ap, op);
  switch (op) {
  case 1: {
    int iVal = va_arg(ap, int);
    if (iVal < 0)
      iVal = 0;
    if (iVal > 100)
      iVal = 100;
    p->iSample = iVal;
    break;
  }
  default:
    rc = 12;
    break;
  }
  __builtin_va_end(ap);
  return rc;
}
int sqlite3_expert_sql(sqlite3expert *p, const char *zSql, char **pzErr) {
  IdxScan *pScanOrig = p->pScan;
  IdxStatement *pStmtOrig = p->pStatement;
  int rc = 0;
  const char *zStmt = zSql;
  if (p->bRun)
    return 21;
  while (rc == 0 && zStmt && zStmt[0]) {
    sqlite3_stmt *pStmt = 0;
    rc = sqlite3_prepare_v2(p->dbv, zStmt, -1, &pStmt, &zStmt);
    if (rc == 0) {
      if (pStmt) {
        IdxStatement *pNew;
        const char *z = sqlite3_sql(pStmt);
        int n = (int)strlen(z);
        pNew = (IdxStatement *)idxMalloc(&rc, sizeof(IdxStatement) + n + 1);
        if (rc == 0) {
          pNew->zSql = (char *)&pNew[1];
          memcpy(pNew->zSql, z, n + 1);
          pNew->pNext = p->pStatement;
          if (p->pStatement)
            pNew->iId = p->pStatement->iId + 1;
          p->pStatement = pNew;
        }
        sqlite3_finalize(pStmt);
      }
    } else {
      idxDatabaseError(p->dbv, pzErr);
    }
  }
  if (rc != 0) {
    idxScanFree(p->pScan, pScanOrig);
    idxStatementFree(p->pStatement, pStmtOrig);
    p->pScan = pScanOrig;
    p->pStatement = pStmtOrig;
  }
  return rc;
}
int sqlite3_expert_analyze(sqlite3expert *p, char **pzErr) {
  int rc;
  IdxHashEntry *pEntry;
  rc = idxProcessTriggers(p, pzErr);
  if (rc == 0) {
    rc = idxCreateCandidates(p);
  } else if (rc == (5 | (3 << 8))) {
    if (pzErr)
      *pzErr = sqlite3_mprintf("Cannot find a unique index name to propose.");
    return rc;
  }
  if (rc == 0) {
    rc = idxPopulateStat1(p, pzErr);
  }
  for (pEntry = p->hIdx.pFirst; pEntry; pEntry = pEntry->pNext) {
    p->zCandidates =
        idxAppendText(&rc, p->zCandidates, "%s;%s%s\n", pEntry->zVal,
                      pEntry->zVal2 ? " -- stat1: " : "", pEntry->zVal2);
  }
  if (rc == 0) {
    rc = idxFindIndexes(p, pzErr);
  }
  if (rc == 0) {
    p->bRun = 1;
  }
  return rc;
}
int sqlite3_expert_count(sqlite3expert *p) {
  int nRet = 0;
  if (p->pStatement)
    nRet = p->pStatement->iId + 1;
  return nRet;
}
const char *sqlite3_expert_report(sqlite3expert *p, int iStmt, int eReport) {
  const char *zRet = 0;
  IdxStatement *pStmt;
  if (p->bRun == 0)
    return 0;
  for (pStmt = p->pStatement; pStmt && pStmt->iId != iStmt;
       pStmt = pStmt->pNext)
    ;
  switch (eReport) {
  case 1:
    if (pStmt)
      zRet = pStmt->zSql;
    break;
  case 2:
    if (pStmt)
      zRet = pStmt->zIdx;
    break;
  case 3:
    if (pStmt)
      zRet = pStmt->zEQP;
    break;
  case 4:
    zRet = p->zCandidates;
    break;
  }
  return zRet;
}
void sqlite3_expert_destroy(sqlite3expert *p) {
  if (p) {
    sqlite3_close(p->dbm);
    sqlite3_close(p->dbv);
    idxScanFree(p->pScan, 0);
    idxStatementFree(p->pStatement, 0);
    idxTableFree(p->pTable);
    idxWriteFree(p->pWrite);
    idxHashClear(&p->hIdx);
    sqlite3_free(p->zCandidates);
    sqlite3_free(p);
  }
}
typedef struct ExpertInfo ExpertInfo;
struct ExpertInfo {
  sqlite3expert *pExpert;
  int bVerbose;
};
typedef struct EQPGraphRow EQPGraphRow;
struct EQPGraphRow {
  int iEqpId;
  int iParentId;
  EQPGraphRow *pNext;
  char zText[1];
};
typedef struct EQPGraph EQPGraph;
struct EQPGraph {
  EQPGraphRow *pRow;
  EQPGraphRow *pLast;
  char zPrefix[100];
};
typedef struct ColModeOpts {
  int iWrap;
  u8 bQuote;
  u8 bWordWrap;
} ColModeOpts;
typedef struct ShellState ShellState;
struct ShellState {
  sqlite3 *db;
  u8 autoExplain;
  u8 autoEQP;
  u8 autoEQPtest;
  u8 autoEQPtrace;
  u8 scanstatsOn;
  u8 openMode;
  u8 doXdgOpen;
  u8 nEqpLevel;
  u8 eTraceType;
  u8 bSafeMode;
  u8 bSafeModePersist;
  ColModeOpts cmOpts;
  unsigned statsOn;
  unsigned mEqpLines;
  int inputNesting;
  int outCount;
  int cnt;
  int lineno;
  int openFlags;
  FILE *in;
  FILE *out;
  FILE *traceOut;
  int nErr;
  int mode;
  int modePrior;
  int cMode;
  int normalMode;
  int writableSchema;
  int showHeader;
  int nCheck;
  unsigned nProgress;
  unsigned mxProgress;
  unsigned flgProgress;
  unsigned shellFlgs;
  unsigned priorShFlgs;
  sqlite3_int64 szMax;
  char *zDestTable;
  char *zTempFile;
  char zTestcase[30];
  char colSeparator[20];
  char rowSeparator[20];
  char colSepPrior[20];
  char rowSepPrior[20];
  int *colWidth;
  int *actualWidth;
  int nWidth;
  char nullValue[20];
  char outfile[4096];
  sqlite3_stmt *pStmt;
  FILE *pLog;
  struct AuxDb {
    sqlite3 *db;
    const char *zDbFilename;
    char *zFreeOnClose;
  } aAuxDb[5], *pAuxDb;
  int *aiIndent;
  int nIndent;
  int iIndent;
  char *zNonce;
  EQPGraph sGraph;
  ExpertInfo expert;
};
static const char *modeDescr[] = {
    "line",     "column", "list",    "semi",  "html",        "insert", "quote",
    "tcl",      "csv",    "explain", "ascii", "prettyprint", "eqp",    "json",
    "markdown", "table",  "box",     "count", "off"};
static void shellLog(void *pArg, int iErrCode, const char *zMsg) {
  ShellState *p = (ShellState *)pArg;
  if (p->pLog == 0)
    return;
  fprintf(p->pLog, "(%d) %s\n", iErrCode, zMsg);
  fflush(p->pLog);
}
static void shellPutsFunc(sqlite3_context *pCtx, int nVal,
                          sqlite3_value **apVal) {
  ShellState *p = (ShellState *)sqlite3_user_data(pCtx);
  (void)nVal;
  fprintf(p->out, "%s\n", sqlite3_value_text(apVal[0]));
  sqlite3_result_value(pCtx, apVal[0]);
}
static void failIfSafeMode(ShellState *p, const char *zErrMsg, ...) {
  if (p->bSafeMode) {
    va_list ap;
    char *zMsg;
    __builtin_va_start(ap, zErrMsg);
    zMsg = sqlite3_vmprintf(zErrMsg, ap);
    __builtin_va_end(ap);
    fprintf(stderr, "line %d: ", p->lineno);
    fprintf(stderr, "%s\n", zMsg);
    exit(1);
  }
}
static void editFunc(sqlite3_context *context, int argc, sqlite3_value **argv) {
  const char *zEditor;
  char *zTempFile = 0;
  sqlite3 *db;
  char *zCmd = 0;
  int bBin;
  int rc;
  int hasCRNL = 0;
  FILE *f = 0;
  sqlite3_int64 sz;
  sqlite3_int64 x;
  unsigned char *p = 0;
  if (argc == 2) {
    zEditor = (const char *)sqlite3_value_text(argv[1]);
  } else {
    zEditor = getenv("VISUAL");
  }
  if (zEditor == 0) {
    sqlite3_result_error(context, "no editor for edit()", -1);
    return;
  }
  if (sqlite3_value_type(argv[0]) == 5) {
    sqlite3_result_error(context, "NULL input to edit()", -1);
    return;
  }
  db = sqlite3_context_db_handle(context);
  zTempFile = 0;
  sqlite3_file_control(db, 0, 16, &zTempFile);
  if (zTempFile == 0) {
    sqlite3_uint64 r = 0;
    sqlite3_randomness(sizeof(r), &r);
    zTempFile = sqlite3_mprintf("temp%llx", r);
    if (zTempFile == 0) {
      sqlite3_result_error_nomem(context);
      return;
    }
  }
  bBin = sqlite3_value_type(argv[0]) == 4;
  f = fopen(zTempFile, bBin ? "wb" : "w");
  if (f == 0) {
    sqlite3_result_error(context, "edit() cannot open temp file", -1);
    goto edit_func_end;
  }
  sz = sqlite3_value_bytes(argv[0]);
  if (bBin) {
    x = fwrite(sqlite3_value_blob(argv[0]), 1, (size_t)sz, f);
  } else {
    const char *z = (const char *)sqlite3_value_text(argv[0]);
    if (z && strstr(z, "\x0d\n") != 0)
      hasCRNL = 1;
    x = fwrite(sqlite3_value_text(argv[0]), 1, (size_t)sz, f);
  }
  fclose(f);
  f = 0;
  if (x != sz) {
    sqlite3_result_error(context, "edit() could not write the whole file", -1);
    goto edit_func_end;
  }
  zCmd = sqlite3_mprintf("%s \"%s\"", zEditor, zTempFile);
  if (zCmd == 0) {
    sqlite3_result_error_nomem(context);
    goto edit_func_end;
  }
  rc = system(zCmd);
  sqlite3_free(zCmd);
  if (rc) {
    sqlite3_result_error(context, "EDITOR returned non-zero", -1);
    goto edit_func_end;
  }
  f = fopen(zTempFile, "rb");
  if (f == 0) {
    sqlite3_result_error(context, "edit() cannot reopen temp file after edit",
                         -1);
    goto edit_func_end;
  }
  fseek(f, 0, 2);
  sz = ftell(f);
  rewind(f);
  p = sqlite3_malloc64(sz + 1);
  if (p == 0) {
    sqlite3_result_error_nomem(context);
    goto edit_func_end;
  }
  x = fread(p, 1, (size_t)sz, f);
  fclose(f);
  f = 0;
  if (x != sz) {
    sqlite3_result_error(context, "could not read back the whole file", -1);
    goto edit_func_end;
  }
  if (bBin) {
    sqlite3_result_blob64(context, p, sz, sqlite3_free);
  } else {
    sqlite3_int64 i, j;
    if (hasCRNL) {
    } else {
      p[sz] = 0;
      for (i = j = 0; i < sz; i++) {
        if (p[i] == '\x0d' && p[i + 1] == '\n')
          i++;
        p[j++] = p[i];
      }
      sz = j;
      p[sz] = 0;
    }
    sqlite3_result_text64(context, (const char *)p, sz, sqlite3_free, 1);
  }
  p = 0;
edit_func_end:
  if (f)
    fclose(f);
  unlink(zTempFile);
  sqlite3_free(zTempFile);
  sqlite3_free(p);
}
static void outputModePush(ShellState *p) {
  p->modePrior = p->mode;
  p->priorShFlgs = p->shellFlgs;
  memcpy(p->colSepPrior, p->colSeparator, sizeof(p->colSeparator));
  memcpy(p->rowSepPrior, p->rowSeparator, sizeof(p->rowSeparator));
}
static void outputModePop(ShellState *p) {
  p->mode = p->modePrior;
  p->shellFlgs = p->priorShFlgs;
  memcpy(p->colSeparator, p->colSepPrior, sizeof(p->colSeparator));
  memcpy(p->rowSeparator, p->rowSepPrior, sizeof(p->rowSeparator));
}
static void output_hex_blob(FILE *out, const void *pBlob, int nBlob) {
  int i;
  unsigned char *aBlob = (unsigned char *)pBlob;
  char *zStr = sqlite3_malloc(nBlob * 2 + 1);
  shell_check_oom(zStr);
  for (i = 0; i < nBlob; i++) {
    static const char aHex[] = {'0', '1', '2', '3', '4', '5', '6', '7',
                                '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    zStr[i * 2] = aHex[(aBlob[i] >> 4)];
    zStr[i * 2 + 1] = aHex[(aBlob[i] & 15)];
  }
  zStr[i * 2] = 'A';
  fprintf(out, "X'%s'", zStr);
  sqlite3_free(zStr);
}
static const char *unused_string(const char *z, const char *zA, const char *zB,
                                 char *zBuf) {
  unsigned i = 0;
  if (strstr(z, zA) == 0)
    return zA;
  if (strstr(z, zB) == 0)
    return zB;
  do {
    sqlite3_snprintf(20, zBuf, "(%s%u)", zA, i++);
  } while (strstr(z, zBuf) != 0);
  return zBuf;
}
static void output_quoted_string(FILE *out, const char *z) {
  int i;
  char c;
  ;
  if (z == 0)
    return;
  for (i = 0; (c = z[i]) != 0 && c != '\''; i++) {
  }
  if (c == 0) {
    fprintf(out, "'%s'", z);
  } else {
    fprintf(out, "'");
    while (*z) {
      for (i = 0; (c = z[i]) != 0 && c != '\''; i++) {
      }
      if (c == '\'')
        i++;
      if (i) {
        fprintf(out, "%.*s", i, z);
        z += i;
      }
      if (c == '\'') {
        fprintf(out, "'");
        continue;
      }
      if (c == 0) {
        break;
      }
      z++;
    }
    fprintf(out, "'");
  };
}
static void output_quoted_escaped_string(FILE *out, const char *z) {
  int i;
  char c;
  ;
  for (i = 0; (c = z[i]) != 0 && c != '\'' && c != '\n' && c != '\x0d'; i++) {
  }
  if (c == 0) {
    fprintf(out, "'%s'", z);
  } else {
    const char *zNL = 0;
    const char *zCR = 0;
    int nNL = 0;
    int nCR = 0;
    char zBuf1[20], zBuf2[20];
    for (i = 0; z[i]; i++) {
      if (z[i] == '\n')
        nNL++;
      if (z[i] == '\x0d')
        nCR++;
    }
    if (nNL) {
      fprintf(out, "replace(");
      zNL = unused_string(z, "\\n", "\\012", zBuf1);
    }
    if (nCR) {
      fprintf(out, "replace(");
      zCR = unused_string(z, "\\r", "\\015", zBuf2);
    }
    fprintf(out, "'");
    while (*z) {
      for (i = 0; (c = z[i]) != 0 && c != '\n' && c != '\x0d' && c != '\'';
           i++) {
      }
      if (c == '\'')
        i++;
      if (i) {
        fprintf(out, "%.*s", i, z);
        z += i;
      }
      if (c == '\'') {
        fprintf(out, "'");
        continue;
      }
      if (c == 0) {
        break;
      }
      z++;
      if (c == '\n') {
        fprintf(out, "%s", zNL);
        continue;
      }
      fprintf(out, "%s", zCR);
    }
    fprintf(out, "'");
    if (nCR) {
      fprintf(out, ",'%s',char(13))", zCR);
    }
    if (nNL) {
      fprintf(out, ",'%s',char(10))", zNL);
    }
  };
}
static void output_c_string(FILE *out, const char *z) {
  unsigned int c;
  fputc('\"', out);
  while ((c = *(z++)) != 0) {
    if (c == '\\') {
      fputc(c, out);
      fputc(c, out);
    } else if (c == '\"') {
      fputc('\\', out);
      fputc('\"', out);
    } else if (c == '\t') {
      fputc('\\', out);
      fputc('t', out);
    } else if (c == '\n') {
      fputc('\\', out);
      fputc('n', out);
    } else if (c == '\x0d') {
      fputc('\\', out);
      fputc('r', out);
    } else if (!((*__ctype_b_loc())[(int)((c & 255))] &
                 (unsigned short int)_ISprint)) {
      fprintf(out, "\\%03o", c & 255);
    } else {
      fputc(c, out);
    }
  }
  fputc('\"', out);
}
static void output_json_string(FILE *out, const char *z, i64 n) {
  unsigned int c;
  if (z == 0)
    z = "";
  if (n < 0)
    n = strlen(z);
  fputc('\"', out);
  while (n--) {
    c = *(z++);
    if (c == '\\' || c == '\"') {
      fputc('\\', out);
      fputc(c, out);
    } else if (c <= 31) {
      fputc('\\', out);
      if (c == 'A') {
        fputc('b', out);
      } else if (c == 'A') {
        fputc('f', out);
      } else if (c == '\n') {
        fputc('n', out);
      } else if (c == '\x0d') {
        fputc('r', out);
      } else if (c == '\t') {
        fputc('t', out);
      } else {
        fprintf(out, "u%04x", c);
      }
    } else {
      fputc(c, out);
    }
  }
  fputc('\"', out);
}
static void output_html_string(FILE *out, const char *z) {
  int i;
  if (z == 0)
    z = "";
  while (*z) {
    for (i = 0; z[i] && z[i] != '<' && z[i] != '&' && z[i] != '>' &&
                z[i] != '\"' && z[i] != '\'';
         i++) {
    }
    if (i > 0) {
      fprintf(out, "%.*s", i, z);
    }
    if (z[i] == '<') {
      fprintf(out, "&lt;");
    } else if (z[i] == '&') {
      fprintf(out, "&amp;");
    } else if (z[i] == '>') {
      fprintf(out, "&gt;");
    } else if (z[i] == '\"') {
      fprintf(out, "&quot;");
    } else if (z[i] == '\'') {
    } else {
      break;
    }
    z += i + 1;
  }
}
static const char needCsvQuote[] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
static void output_csv(ShellState *p, const char *z, int bSep) {
  FILE *out = p->out;
  if (z == 0) {
    fprintf(out, "%s", p->nullValue);
  } else {
    unsigned i;
    for (i = 0; z[i]; i++) {
      if (needCsvQuote[((unsigned char *)z)[i]]) {
        i = 0;
        break;
      }
    }
    if (i == 0 || strstr(z, p->colSeparator) != 0) {
      char *zQuoted = sqlite3_mprintf("\"%w\"", z);
      shell_check_oom(zQuoted);
      fprintf(out, "%s", zQuoted);
      sqlite3_free(zQuoted);
    } else {
      fprintf(out, "%s", z);
    }
  }
  if (bSep) {
    fprintf(p->out, "%s", p->colSeparator);
  }
}
static void interrupt_handler(int NotUsed) {
  (void)(NotUsed);
  if (++seenInterrupt > 1)
    exit(1);
  if (globalDb)
    sqlite3_interrupt(globalDb);
}
static int safeModeAuth(void *pClientData, int op, const char *zA1,
                        const char *zA2, const char *zA3, const char *zA4) {
  ShellState *p = (ShellState *)pClientData;
  static const char *azProhibitedFunctions[] = {
      "edit",      "fts3_tokenizer", "load_extension", "readfile",
      "writefile", "zipfile",        "zipfile_cds"};
  (void)(zA1);
  (void)(zA3);
  (void)(zA4);
  switch (op) {
  case 24: {
    failIfSafeMode(p, "cannot run ATTACH in safe mode");
    break;
  }
  case 31: {
    int i;
    for (i = 0; i < (int)(sizeof(azProhibitedFunctions) /
                          sizeof(azProhibitedFunctions[0]));
         i++) {
      if (sqlite3_stricmp(zA2, azProhibitedFunctions[i]) == 0) {
        failIfSafeMode(p, "cannot use the %s() function in safe mode",
                       azProhibitedFunctions[i]);
      }
    }
    break;
  }
  }
  return 0;
}
static int shellAuth(void *pClientData, int op, const char *zA1,
                     const char *zA2, const char *zA3, const char *zA4) {
  ShellState *p = (ShellState *)pClientData;
  static const char *azAction[] = {0,
                                   "CREATE_INDEX",
                                   "CREATE_TABLE",
                                   "CREATE_TEMP_INDEX",
                                   "CREATE_TEMP_TABLE",
                                   "CREATE_TEMP_TRIGGER",
                                   "CREATE_TEMP_VIEW",
                                   "CREATE_TRIGGER",
                                   "CREATE_VIEW",
                                   "DELETE",
                                   "DROP_INDEX",
                                   "DROP_TABLE",
                                   "DROP_TEMP_INDEX",
                                   "DROP_TEMP_TABLE",
                                   "DROP_TEMP_TRIGGER",
                                   "DROP_TEMP_VIEW",
                                   "DROP_TRIGGER",
                                   "DROP_VIEW",
                                   "INSERT",
                                   "PRAGMA",
                                   "READ",
                                   "SELECT",
                                   "TRANSACTION",
                                   "UPDATE",
                                   "ATTACH",
                                   "DETACH",
                                   "ALTER_TABLE",
                                   "REINDEX",
                                   "ANALYZE",
                                   "CREATE_VTABLE",
                                   "DROP_VTABLE",
                                   "FUNCTION",
                                   "SAVEPOINT",
                                   "RECURSIVE"};
  int i;
  const char *az[4];
  az[0] = zA1;
  az[1] = zA2;
  az[2] = zA3;
  az[3] = zA4;
  fprintf(p->out, "authorizer: %s", azAction[op]);
  for (i = 0; i < 4; i++) {
    fprintf(p->out, " ");
    if (az[i]) {
      output_c_string(p->out, az[i]);
    } else {
      fprintf(p->out, "NULL");
    }
  }
  fprintf(p->out, "\n");
  if (p->bSafeMode)
    (void)safeModeAuth(pClientData, op, zA1, zA2, zA3, zA4);
  return 0;
}
static void printSchemaLine(FILE *out, const char *z, const char *zTail) {
  char *zToFree = 0;
  if (z == 0)
    return;
  if (zTail == 0)
    return;
  if (zTail[0] == ';' && (strstr(z, "/*") != 0 || strstr(z, "--") != 0)) {
    const char *zOrig = z;
    static const char *azTerm[] = {"", "*/", "\n"};
    int i;
    for (i = 0; i < (int)(sizeof(azTerm) / sizeof(azTerm[0])); i++) {
      char *zNew = sqlite3_mprintf("%s%s;", zOrig, azTerm[i]);
      shell_check_oom(zNew);
      if (sqlite3_complete(zNew)) {
        size_t n = strlen(zNew);
        zNew[n - 1] = 0;
        zToFree = zNew;
        z = zNew;
        break;
      }
      sqlite3_free(zNew);
    }
  }
  if (sqlite3_strglob("CREATE TABLE ['\"]*", z) == 0) {
    fprintf(out, "CREATE TABLE IF NOT EXISTS %s%s", z + 13, zTail);
  } else {
    fprintf(out, "%s%s", z, zTail);
  }
  sqlite3_free(zToFree);
}
static void printSchemaLineN(FILE *out, char *z, int n, const char *zTail) {
  char c = z[n];
  z[n] = 0;
  printSchemaLine(out, z, zTail);
  z[n] = c;
}
static int wsToEol(const char *z) {
  int i;
  for (i = 0; z[i]; i++) {
    if (z[i] == '\n')
      return 1;
    if (((*__ctype_b_loc())[(int)(((unsigned char)z[i]))] &
         (unsigned short int)_ISspace))
      continue;
    if (z[i] == '-' && z[i + 1] == '-')
      return 1;
    return 0;
  }
  return 1;
}
static void eqp_append(ShellState *p, int iEqpId, int p2, const char *zText) {
  EQPGraphRow *pNew;
  i64 nText;
  if (zText == 0)
    return;
  nText = strlen(zText);
  if (p->autoEQPtest) {
    fprintf(p->out, "%d,%d,%s\n", iEqpId, p2, zText);
  }
  pNew = sqlite3_malloc64(sizeof(*pNew) + nText);
  shell_check_oom(pNew);
  pNew->iEqpId = iEqpId;
  pNew->iParentId = p2;
  memcpy(pNew->zText, zText, nText + 1);
  pNew->pNext = 0;
  if (p->sGraph.pLast) {
    p->sGraph.pLast->pNext = pNew;
  } else {
    p->sGraph.pRow = pNew;
  }
  p->sGraph.pLast = pNew;
}
static void eqp_reset(ShellState *p) {
  EQPGraphRow *pRow, *pNext;
  for (pRow = p->sGraph.pRow; pRow; pRow = pNext) {
    pNext = pRow->pNext;
    sqlite3_free(pRow);
  }
  memset(&p->sGraph, 0, sizeof(p->sGraph));
}
static EQPGraphRow *eqp_next_row(ShellState *p, int iEqpId, EQPGraphRow *pOld) {
  EQPGraphRow *pRow = pOld ? pOld->pNext : p->sGraph.pRow;
  while (pRow && pRow->iParentId != iEqpId)
    pRow = pRow->pNext;
  return pRow;
}
static void eqp_render_level(ShellState *p, int iEqpId) {
  EQPGraphRow *pRow, *pNext;
  i64 n = strlen(p->sGraph.zPrefix);
  char *z;
  for (pRow = eqp_next_row(p, iEqpId, 0); pRow; pRow = pNext) {
    pNext = eqp_next_row(p, iEqpId, pRow);
    z = pRow->zText;
    fprintf(p->out, "%s%s%s\n", p->sGraph.zPrefix, pNext ? "|--" : "`--", z);
    if (n < (i64)sizeof(p->sGraph.zPrefix) - 7) {
      memcpy(&p->sGraph.zPrefix[n], pNext ? "|  " : "   ", 4);
      eqp_render_level(p, pRow->iEqpId);
      p->sGraph.zPrefix[n] = 0;
    }
  }
}
static void eqp_render(ShellState *p, i64 nCycle) {
  EQPGraphRow *pRow = p->sGraph.pRow;
  if (pRow) {
    if (pRow->zText[0] == '-') {
      if (pRow->pNext == 0) {
        eqp_reset(p);
        return;
      }
      fprintf(p->out, "%s\n", pRow->zText + 3);
      p->sGraph.pRow = pRow->pNext;
      sqlite3_free(pRow);
    } else if (nCycle > 0) {
      fprintf(p->out, "QUERY PLAN (cycles=%lld [100%%])\n", nCycle);
    } else {
      fprintf(p->out, "QUERY PLAN\n");
    }
    p->sGraph.zPrefix[0] = 0;
    eqp_render_level(p, 0);
    eqp_reset(p);
  }
}
static int progress_handler(void *pClientData) {
  ShellState *p = (ShellState *)pClientData;
  p->nProgress++;
  if (p->nProgress >= p->mxProgress && p->mxProgress > 0) {
    fprintf(p->out, "Progress limit reached (%u)\n", p->nProgress);
    if (p->flgProgress & 2)
      p->nProgress = 0;
    if (p->flgProgress & 4)
      p->mxProgress = 0;
    return 1;
  }
  if ((p->flgProgress & 1) == 0) {
    fprintf(p->out, "Progress %u\n", p->nProgress);
  }
  return 0;
}
static void print_dashes(FILE *out, int N) {
  const char zDash[] = "--------------------------------------------------";
  const int nDash = sizeof(zDash) - 1;
  while (N > nDash) {
    fputs(zDash, out);
    N -= nDash;
  }
  fprintf(out, "%.*s", N, zDash);
}
static void print_row_separator(ShellState *p, int nArg, const char *zSep) {
  int i;
  if (nArg > 0) {
    fputs(zSep, p->out);
    print_dashes(p->out, p->actualWidth[0] + 2);
    for (i = 1; i < nArg; i++) {
      fputs(zSep, p->out);
      print_dashes(p->out, p->actualWidth[i] + 2);
    }
    fputs(zSep, p->out);
  }
  fputs("\n", p->out);
}
static int shell_callback(void *pArg, int nArg, char **azArg, char **azCol,
                          int *aiType) {
  int i;
  ShellState *p = (ShellState *)pArg;
  if (azArg == 0)
    return 0;
  switch (p->cMode) {
  case 17:
  case 18: {
    break;
  }
  case 0: {
    int w = 5;
    if (azArg == 0)
      break;
    for (i = 0; i < nArg; i++) {
      int len = strlen30(azCol[i] ? azCol[i] : "");
      if (len > w)
        w = len;
    }
    if (p->cnt++ > 0)
      fprintf(p->out, "%s", p->rowSeparator);
    for (i = 0; i < nArg; i++) {
      fprintf(p->out, "%*s = %s%s", w, azCol[i],
              azArg[i] ? azArg[i] : p->nullValue, p->rowSeparator);
    }
    break;
  }
  case 9: {
    static const int aExplainWidth[] = {4, 13, 4, 4, 4, 13, 2, 13};
    if (nArg > (int)(sizeof(aExplainWidth) / sizeof(aExplainWidth[0]))) {
      nArg = (int)(sizeof(aExplainWidth) / sizeof(aExplainWidth[0]));
    }
    if (p->cnt++ == 0) {
      for (i = 0; i < nArg; i++) {
        int w = aExplainWidth[i];
        utf8_width_print(p->out, w, azCol[i]);
        fputs(i == nArg - 1 ? "\n" : "  ", p->out);
      }
      for (i = 0; i < nArg; i++) {
        int w = aExplainWidth[i];
        print_dashes(p->out, w);
        fputs(i == nArg - 1 ? "\n" : "  ", p->out);
      }
    }
    if (azArg == 0)
      break;
    for (i = 0; i < nArg; i++) {
      int w = aExplainWidth[i];
      if (i == nArg - 1)
        w = 0;
      if (azArg[i] && strlenChar(azArg[i]) > w) {
        w = strlenChar(azArg[i]);
      }
      if (i == 1 && p->aiIndent && p->pStmt) {
        if (p->iIndent < p->nIndent) {
          fprintf(p->out, "%*.s", p->aiIndent[p->iIndent], "");
        }
        p->iIndent++;
      }
      utf8_width_print(p->out, w, azArg[i] ? azArg[i] : p->nullValue);
      fputs(i == nArg - 1 ? "\n" : "  ", p->out);
    }
    break;
  }
  case 3: {
    printSchemaLine(p->out, azArg[0], ";\n");
    break;
  }
  case 11: {
    char *z;
    int j;
    int nParen = 0;
    char cEnd = 0;
    char c;
    int nLine = 0;
    ((void)sizeof((nArg == 1) ? 1 : 0), ({
       if (nArg == 1)
         ;
       else
         __assert_fail("nArg==1", "shell.c", 17850, __PRETTY_FUNCTION__);
     }));
    if (azArg[0] == 0)
      break;
    if (sqlite3_strlike("CREATE VIEW%", azArg[0], 0) == 0 ||
        sqlite3_strlike("CREATE TRIG%", azArg[0], 0) == 0) {
      fprintf(p->out, "%s;\n", azArg[0]);
      break;
    }
    z = sqlite3_mprintf("%s", azArg[0]);
    shell_check_oom(z);
    j = 0;
    for (i = 0; ((*__ctype_b_loc())[(int)(((unsigned char)z[i]))] &
                 (unsigned short int)_ISspace);
         i++) {
    }
    for (; (c = z[i]) != 0; i++) {
      if (((*__ctype_b_loc())[(int)(((unsigned char)c))] &
           (unsigned short int)_ISspace)) {
        if (z[j - 1] == '\x0d')
          z[j - 1] = '\n';
        if (((*__ctype_b_loc())[(int)(((unsigned char)z[j - 1]))] &
             (unsigned short int)_ISspace) ||
            z[j - 1] == '(')
          continue;
      } else if ((c == '(' || c == ')') && j > 0 &&
                 ((*__ctype_b_loc())[(int)(((unsigned char)z[j - 1]))] &
                  (unsigned short int)_ISspace)) {
        j--;
      }
      z[j++] = c;
    }
    while (j > 0 && ((*__ctype_b_loc())[(int)(((unsigned char)z[j - 1]))] &
                     (unsigned short int)_ISspace)) {
      j--;
    }
    z[j] = 0;
    if (strlen30(z) >= 79) {
      for (i = j = 0; (c = z[i]) != 0; i++) {
        if (c == cEnd) {
          cEnd = 0;
        } else if (c == '\"' || c == '\'' || c == '`') {
          cEnd = c;
        } else if (c == '[') {
          cEnd = ']';
        } else if (c == '-' && z[i + 1] == '-') {
          cEnd = '\n';
        } else if (c == '(') {
          nParen++;
        } else if (c == ')') {
          nParen--;
          if (nLine > 0 && nParen == 0 && j > 0) {
            printSchemaLineN(p->out, z, j, "\n");
            j = 0;
          }
        }
        z[j++] = c;
        if (nParen == 1 && cEnd == 0 &&
            (c == '(' || c == '\n' || (c == ',' && !wsToEol(z + i + 1)))) {
          if (c == '\n')
            j--;
          printSchemaLineN(p->out, z, j, "\n  ");
          j = 0;
          nLine++;
          while (((*__ctype_b_loc())[(int)(((unsigned char)z[i + 1]))] &
                  (unsigned short int)_ISspace)) {
            i++;
          }
        }
      }
      z[j] = 0;
    }
    printSchemaLine(p->out, z, ";\n");
    sqlite3_free(z);
    break;
  }
  case 2: {
    if (p->cnt++ == 0 && p->showHeader) {
      for (i = 0; i < nArg; i++) {
        fprintf(p->out, "%s%s", azCol[i],
                i == nArg - 1 ? p->rowSeparator : p->colSeparator);
      }
    }
    if (azArg == 0)
      break;
    for (i = 0; i < nArg; i++) {
      char *z = azArg[i];
      if (z == 0)
        z = p->nullValue;
      fprintf(p->out, "%s", z);
      if (i < nArg - 1) {
        fprintf(p->out, "%s", p->colSeparator);
      } else {
        fprintf(p->out, "%s", p->rowSeparator);
      }
    }
    break;
  }
  case 4: {
    if (p->cnt++ == 0 && p->showHeader) {
      fprintf(p->out, "<TR>");
      for (i = 0; i < nArg; i++) {
        fprintf(p->out, "<TH>");
        output_html_string(p->out, azCol[i]);
        fprintf(p->out, "</TH>\n");
      }
      fprintf(p->out, "</TR>\n");
    }
    if (azArg == 0)
      break;
    fprintf(p->out, "<TR>");
    for (i = 0; i < nArg; i++) {
      fprintf(p->out, "<TD>");
      output_html_string(p->out, azArg[i] ? azArg[i] : p->nullValue);
      fprintf(p->out, "</TD>\n");
    }
    fprintf(p->out, "</TR>\n");
    break;
  }
  case 7: {
    if (p->cnt++ == 0 && p->showHeader) {
      for (i = 0; i < nArg; i++) {
        output_c_string(p->out, azCol[i] ? azCol[i] : "");
        if (i < nArg - 1)
          fprintf(p->out, "%s", p->colSeparator);
      }
      fprintf(p->out, "%s", p->rowSeparator);
    }
    if (azArg == 0)
      break;
    for (i = 0; i < nArg; i++) {
      output_c_string(p->out, azArg[i] ? azArg[i] : p->nullValue);
      if (i < nArg - 1)
        fprintf(p->out, "%s", p->colSeparator);
    }
    fprintf(p->out, "%s", p->rowSeparator);
    break;
  }
  case 8: {
    ;
    if (p->cnt++ == 0 && p->showHeader) {
      for (i = 0; i < nArg; i++) {
        output_csv(p, azCol[i] ? azCol[i] : "", i < nArg - 1);
      }
      fprintf(p->out, "%s", p->rowSeparator);
    }
    if (nArg > 0) {
      for (i = 0; i < nArg; i++) {
        output_csv(p, azArg[i], i < nArg - 1);
      }
      fprintf(p->out, "%s", p->rowSeparator);
    };
    break;
  }
  case 5: {
    if (azArg == 0)
      break;
    fprintf(p->out, "INSERT INTO %s", p->zDestTable);
    if (p->showHeader) {
      fprintf(p->out, "(");
      for (i = 0; i < nArg; i++) {
        if (i > 0)
          fprintf(p->out, ",");
        if (quoteChar(azCol[i])) {
          char *z = sqlite3_mprintf("\"%w\"", azCol[i]);
          shell_check_oom(z);
          fprintf(p->out, "%s", z);
          sqlite3_free(z);
        } else {
          fprintf(p->out, "%s", azCol[i]);
        }
      }
      fprintf(p->out, ")");
    }
    p->cnt++;
    for (i = 0; i < nArg; i++) {
      fprintf(p->out, i > 0 ? "," : " VALUES(");
      if ((azArg[i] == 0) || (aiType && aiType[i] == 5)) {
        fprintf(p->out, "NULL");
      } else if (aiType && aiType[i] == 3) {
        if ((((p)->shellFlgs & (16)) != 0)) {
          output_quoted_string(p->out, azArg[i]);
        } else {
          output_quoted_escaped_string(p->out, azArg[i]);
        }
      } else if (aiType && aiType[i] == 1) {
        fprintf(p->out, "%s", azArg[i]);
      } else if (aiType && aiType[i] == 2) {
        char z[50];
        double r = sqlite3_column_double(p->pStmt, i);
        sqlite3_uint64 ur;
        memcpy(&ur, &r, sizeof(r));
        if (ur == 9218868437227405312) {
          fprintf(p->out, "9.0e+999");
        } else if (ur == 18442240474082181120) {
          fprintf(p->out, "-9.0e+999");
        } else {
          sqlite3_int64 ir = (sqlite3_int64)r;
          if (r == (double)ir) {
            sqlite3_snprintf(50, z, "%lld.0", ir);
          } else {
            sqlite3_snprintf(50, z, "%!.20g", r);
          }
          fprintf(p->out, "%s", z);
        }
      } else if (aiType && aiType[i] == 4 && p->pStmt) {
        const void *pBlob = sqlite3_column_blob(p->pStmt, i);
        int nBlob = sqlite3_column_bytes(p->pStmt, i);
        output_hex_blob(p->out, pBlob, nBlob);
      } else if (isNumber(azArg[i], 0)) {
        fprintf(p->out, "%s", azArg[i]);
      } else if ((((p)->shellFlgs & (16)) != 0)) {
        output_quoted_string(p->out, azArg[i]);
      } else {
        output_quoted_escaped_string(p->out, azArg[i]);
      }
    }
    fprintf(p->out, ");\n");
    break;
  }
  case 13: {
    if (azArg == 0)
      break;
    if (p->cnt == 0) {
      fputs("[{", p->out);
    } else {
      fputs(",\n{", p->out);
    }
    p->cnt++;
    for (i = 0; i < nArg; i++) {
      output_json_string(p->out, azCol[i], -1);
      putc(':', p->out);
      if ((azArg[i] == 0) || (aiType && aiType[i] == 5)) {
        fputs("null", p->out);
      } else if (aiType && aiType[i] == 2) {
        char z[50];
        double r = sqlite3_column_double(p->pStmt, i);
        sqlite3_uint64 ur;
        memcpy(&ur, &r, sizeof(r));
        if (ur == 9218868437227405312) {
          fprintf(p->out, "9.0e+999");
        } else if (ur == 18442240474082181120) {
          fprintf(p->out, "-9.0e+999");
        } else {
          sqlite3_snprintf(50, z, "%!.20g", r);
          fprintf(p->out, "%s", z);
        }
      } else if (aiType && aiType[i] == 4 && p->pStmt) {
        const void *pBlob = sqlite3_column_blob(p->pStmt, i);
        int nBlob = sqlite3_column_bytes(p->pStmt, i);
        output_json_string(p->out, pBlob, nBlob);
      } else if (aiType && aiType[i] == 3) {
        output_json_string(p->out, azArg[i], -1);
      } else {
        fprintf(p->out, "%s", azArg[i]);
      }
      if (i < nArg - 1) {
        putc(',', p->out);
      }
    }
    putc('}', p->out);
    break;
  }
  case 6: {
    if (azArg == 0)
      break;
    if (p->cnt == 0 && p->showHeader) {
      for (i = 0; i < nArg; i++) {
        if (i > 0)
          fputs(p->colSeparator, p->out);
        output_quoted_string(p->out, azCol[i]);
      }
      fputs(p->rowSeparator, p->out);
    }
    p->cnt++;
    for (i = 0; i < nArg; i++) {
      if (i > 0)
        fputs(p->colSeparator, p->out);
      if ((azArg[i] == 0) || (aiType && aiType[i] == 5)) {
        fprintf(p->out, "NULL");
      } else if (aiType && aiType[i] == 3) {
        output_quoted_string(p->out, azArg[i]);
      } else if (aiType && aiType[i] == 1) {
        fprintf(p->out, "%s", azArg[i]);
      } else if (aiType && aiType[i] == 2) {
        char z[50];
        double r = sqlite3_column_double(p->pStmt, i);
        sqlite3_snprintf(50, z, "%!.20g", r);
        fprintf(p->out, "%s", z);
      } else if (aiType && aiType[i] == 4 && p->pStmt) {
        const void *pBlob = sqlite3_column_blob(p->pStmt, i);
        int nBlob = sqlite3_column_bytes(p->pStmt, i);
        output_hex_blob(p->out, pBlob, nBlob);
      } else if (isNumber(azArg[i], 0)) {
        fprintf(p->out, "%s", azArg[i]);
      } else {
        output_quoted_string(p->out, azArg[i]);
      }
    }
    fputs(p->rowSeparator, p->out);
    break;
  }
  case 10: {
    if (p->cnt++ == 0 && p->showHeader) {
      for (i = 0; i < nArg; i++) {
        if (i > 0)
          fprintf(p->out, "%s", p->colSeparator);
        fprintf(p->out, "%s", azCol[i] ? azCol[i] : "");
      }
      fprintf(p->out, "%s", p->rowSeparator);
    }
    if (azArg == 0)
      break;
    for (i = 0; i < nArg; i++) {
      if (i > 0)
        fprintf(p->out, "%s", p->colSeparator);
      fprintf(p->out, "%s", azArg[i] ? azArg[i] : p->nullValue);
    }
    fprintf(p->out, "%s", p->rowSeparator);
    break;
  }
  case 12: {
    eqp_append(p, atoi(azArg[0]), atoi(azArg[1]), azArg[3]);
    break;
  }
  }
  return 0;
}
static int callback(void *pArg, int nArg, char **azArg, char **azCol) {
  return shell_callback(pArg, nArg, azArg, azCol, ((void *)0));
}
static int captureOutputCallback(void *pArg, int nArg, char **azArg,
                                 char **az) {
  ShellText *p = (ShellText *)pArg;
  int i;
  (void)(az);
  if (azArg == 0)
    return 0;
  if (p->n)
    appendText(p, "|", 0);
  for (i = 0; i < nArg; i++) {
    if (i)
      appendText(p, ",", 0);
    if (azArg[i])
      appendText(p, azArg[i], 0);
  }
  return 0;
}
static void createSelftestTable(ShellState *p) {
  char *zErrMsg = 0;
  sqlite3_exec(
      p->db,
      "SAVEPOINT selftest_init;\nCREATE TABLE IF NOT EXISTS selftest(\n  tno "
      "INTEGER PRIMARY KEY,\n  op TEXT,\n  cmd TEXT,\n  ans TEXT\n);CREATE "
      "TEMP TABLE [_shell$self](op,cmd,ans);\nINSERT INTO "
      "[_shell$self](rowid,op,cmd)\n  VALUES(coalesce((SELECT "
      "(max(tno)+100)/10 FROM selftest),10),\n         'memo','Tests generated "
      "by --init');\nINSERT INTO [_shell$self]\n  SELECT 'run',\n    'SELECT "
      "hex(sha3_query(''SELECT type,name,tbl_name,sql FROM sqlite_schema ORDER "
      "BY 2'',224))',\n    hex(sha3_query('SELECT type,name,tbl_name,sql FROM "
      "sqlite_schema ORDER BY 2',224));\nINSERT INTO [_shell$self]\n  SELECT "
      "'run',    'SELECT hex(sha3_query(''SELECT * FROM \"' ||        "
      "printf('%w',name) || '\" NOT INDEXED'',224))',\n    "
      "hex(sha3_query(printf('SELECT * FROM \"%w\" NOT INDEXED',name),224))\n  "
      "FROM (\n    SELECT name FROM sqlite_schema\n     WHERE type='table'\n   "
      "    AND name<>'selftest'\n       AND coalesce(rootpage,0)>0\n  )\n "
      "ORDER BY name;\nINSERT INTO [_shell$self]\n  VALUES('run','PRAGMA "
      "integrity_check','ok');\nINSERT INTO selftest(tno,op,cmd,ans)  SELECT "
      "rowid*10,op,cmd,ans FROM [_shell$self];\nDROP TABLE [_shell$self];",
      0, 0, &zErrMsg);
  if (zErrMsg) {
    fprintf(stderr, "SELFTEST initialization failure: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  }
  sqlite3_exec(p->db, "RELEASE selftest_init", 0, 0, 0);
}
static void set_table_name(ShellState *p, const char *zName) {
  int i, n;
  char cQuote;
  char *z;
  if (p->zDestTable) {
    free(p->zDestTable);
    p->zDestTable = 0;
  }
  if (zName == 0)
    return;
  cQuote = quoteChar(zName);
  n = strlen30(zName);
  if (cQuote)
    n += n + 2;
  z = p->zDestTable = malloc(n + 1);
  shell_check_oom(z);
  n = 0;
  if (cQuote)
    z[n++] = cQuote;
  for (i = 0; zName[i]; i++) {
    z[n++] = zName[i];
    if (zName[i] == cQuote)
      z[n++] = cQuote;
  }
  if (cQuote)
    z[n++] = cQuote;
  z[n] = 0;
}
static char *shell_error_context(const char *zSql, sqlite3 *db) {
  int iOffset;
  size_t len;
  char *zCode;
  char *zMsg;
  int i;
  if (db == 0 || zSql == 0 || (iOffset = sqlite3_error_offset(db)) < 0 ||
      iOffset >= (int)strlen(zSql)) {
    return sqlite3_mprintf("");
  }
  while (iOffset > 50) {
    iOffset--;
    zSql++;
    while ((zSql[0] & 192) == 128) {
      zSql++;
      iOffset--;
    }
  }
  len = strlen(zSql);
  if (len > 78) {
    len = 78;
    while (len > 0 && (zSql[len] & 192) == 128)
      len--;
  }
  zCode = sqlite3_mprintf("%.*s", len, zSql);
  shell_check_oom(zCode);
  for (i = 0; zCode[i]; i++) {
    if (((*__ctype_b_loc())[(int)(((unsigned char)zSql[i]))] &
         (unsigned short int)_ISspace))
      zCode[i] = ' ';
  }
  if (iOffset < 25) {
    zMsg = sqlite3_mprintf("\n  %z\n  %*s^--- error here", zCode, iOffset, "");
  } else {
    zMsg = sqlite3_mprintf("\n  %z\n  %*serror here ---^", zCode, iOffset - 14,
                           "");
  }
  return zMsg;
}
static int run_table_dump_query(ShellState *p, const char *zSelect) {
  sqlite3_stmt *pSelect;
  int rc;
  int nResult;
  int i;
  const char *z;
  rc = sqlite3_prepare_v2(p->db, zSelect, -1, &pSelect, 0);
  if (rc != 0 || !pSelect) {
    char *zContext = shell_error_context(zSelect, p->db);
    fprintf(p->out, "/**** ERROR: (%d) %s *****/\n%s", rc,
            sqlite3_errmsg(p->db), zContext);
    sqlite3_free(zContext);
    if ((rc & 255) != 11)
      p->nErr++;
    return rc;
  }
  rc = sqlite3_step(pSelect);
  nResult = sqlite3_column_count(pSelect);
  while (rc == 100) {
    z = (const char *)sqlite3_column_text(pSelect, 0);
    fprintf(p->out, "%s", z);
    for (i = 1; i < nResult; i++) {
      fprintf(p->out, ",%s", sqlite3_column_text(pSelect, i));
    }
    if (z == 0)
      z = "";
    while (z[0] && (z[0] != '-' || z[1] != '-'))
      z++;
    if (z[0]) {
      fprintf(p->out, "\n;\n");
    } else {
      fprintf(p->out, ";\n");
    }
    rc = sqlite3_step(pSelect);
  }
  rc = sqlite3_finalize(pSelect);
  if (rc != 0) {
    fprintf(p->out, "/**** ERROR: (%d) %s *****/\n", rc, sqlite3_errmsg(p->db));
    if ((rc & 255) != 11)
      p->nErr++;
  }
  return rc;
}
static char *save_err_msg(sqlite3 *db, const char *zPhase, int rc,
                          const char *zSql) {
  char *zErr;
  char *zContext;
  sqlite3_str *pStr = sqlite3_str_new(0);
  sqlite3_str_appendf(pStr, "%s, %s", zPhase, sqlite3_errmsg(db));
  if (rc > 1) {
    sqlite3_str_appendf(pStr, " (%d)", rc);
  }
  zContext = shell_error_context(zSql, db);
  if (zContext) {
    sqlite3_str_appendall(pStr, zContext);
    sqlite3_free(zContext);
  }
  zErr = sqlite3_str_finish(pStr);
  shell_check_oom(zErr);
  return zErr;
}
static void displayLinuxIoStats(FILE *out) {
  FILE *in;
  char z[200];
  sqlite3_snprintf(sizeof(z), z, "/proc/%d/io", getpid());
  in = fopen(z, "rb");
  if (in == 0)
    return;
  while (fgets(z, sizeof(z), in) != 0) {
    static const struct {
      const char *zPattern;
      const char *zDesc;
    } aTrans[] = {{"rchar: ", "Bytes received by read():"},
                  {"wchar: ", "Bytes sent to write():"},
                  {"syscr: ", "Read() system calls:"},
                  {"syscw: ", "Write() system calls:"},
                  {"read_bytes: ", "Bytes read from storage:"},
                  {"write_bytes: ", "Bytes written to storage:"},
                  {"cancelled_write_bytes: ", "Cancelled write bytes:"}};
    int i;
    for (i = 0; i < (int)(sizeof(aTrans) / sizeof(aTrans[0])); i++) {
      int n = strlen30(aTrans[i].zPattern);
      if (cli_strncmp(aTrans[i].zPattern, z, n) == 0) {
        fprintf(out, "%-36s %s", aTrans[i].zDesc, &z[n]);
        break;
      }
    }
  }
  fclose(in);
}
static void displayStatLine(ShellState *p, char *zLabel, char *zFormat,
                            int iStatusCtrl, int bReset) {
  sqlite3_int64 iCur = -1;
  sqlite3_int64 iHiwtr = -1;
  int i, nPercent;
  char zLine[200];
  sqlite3_status64(iStatusCtrl, &iCur, &iHiwtr, bReset);
  for (i = 0, nPercent = 0; zFormat[i]; i++) {
    if (zFormat[i] == '%')
      nPercent++;
  }
  if (nPercent > 1) {
    sqlite3_snprintf(sizeof(zLine), zLine, zFormat, iCur, iHiwtr);
  } else {
    sqlite3_snprintf(sizeof(zLine), zLine, zFormat, iHiwtr);
  }
  fprintf(p->out, "%-36s %s\n", zLabel, zLine);
}
static int display_stats(sqlite3 *db, ShellState *pArg, int bReset) {
  int iCur;
  int iHiwtr;
  FILE *out;
  if (pArg == 0 || pArg->out == 0)
    return 0;
  out = pArg->out;
  if (pArg->pStmt && pArg->statsOn == 2) {
    int nCol, i, x;
    sqlite3_stmt *pStmt = pArg->pStmt;
    char z[100];
    nCol = sqlite3_column_count(pStmt);
    fprintf(out, "%-36s %d\n", "Number of output columns:", nCol);
    for (i = 0; i < nCol; i++) {
      sqlite3_snprintf(sizeof(z), z, "Column %d %nname:", i, &x);
      fprintf(out, "%-36s %s\n", z, sqlite3_column_name(pStmt, i));
      sqlite3_snprintf(30, z + x, "declared type:");
      fprintf(out, "%-36s %s\n", z, sqlite3_column_decltype(pStmt, i));
    }
  }
  if (pArg->statsOn == 3) {
    if (pArg->pStmt) {
      iCur = sqlite3_stmt_status(pArg->pStmt, 4, bReset);
      fprintf(pArg->out, "VM-steps: %d\n", iCur);
    }
    return 0;
  }
  displayStatLine(pArg, "Memory Used:", "%lld (max %lld) bytes", 0, bReset);
  displayStatLine(pArg, "Number of Outstanding Allocations:", "%lld (max %lld)",
                  9, bReset);
  if (pArg->shellFlgs & 1) {
    displayStatLine(pArg,
                    "Number of Pcache Pages Used:", "%lld (max %lld) pages", 1,
                    bReset);
  }
  displayStatLine(pArg,
                  "Number of Pcache Overflow Bytes:", "%lld (max %lld) bytes",
                  2, bReset);
  displayStatLine(pArg, "Largest Allocation:", "%lld bytes", 5, bReset);
  displayStatLine(pArg, "Largest Pcache Allocation:", "%lld bytes", 7, bReset);
  if (db) {
    if (pArg->shellFlgs & 2) {
      iHiwtr = iCur = -1;
      sqlite3_db_status(db, 0, &iCur, &iHiwtr, bReset);
      fprintf(pArg->out, "Lookaside Slots Used:                %d (max %d)\n",
              iCur, iHiwtr);
      sqlite3_db_status(db, 4, &iCur, &iHiwtr, bReset);
      fprintf(pArg->out, "Successful lookaside attempts:       %d\n", iHiwtr);
      sqlite3_db_status(db, 5, &iCur, &iHiwtr, bReset);
      fprintf(pArg->out, "Lookaside failures due to size:      %d\n", iHiwtr);
      sqlite3_db_status(db, 6, &iCur, &iHiwtr, bReset);
      fprintf(pArg->out, "Lookaside failures due to OOM:       %d\n", iHiwtr);
    }
    iHiwtr = iCur = -1;
    sqlite3_db_status(db, 1, &iCur, &iHiwtr, bReset);
    fprintf(pArg->out, "Pager Heap Usage:                    %d bytes\n", iCur);
    iHiwtr = iCur = -1;
    sqlite3_db_status(db, 7, &iCur, &iHiwtr, 1);
    fprintf(pArg->out, "Page cache hits:                     %d\n", iCur);
    iHiwtr = iCur = -1;
    sqlite3_db_status(db, 8, &iCur, &iHiwtr, 1);
    fprintf(pArg->out, "Page cache misses:                   %d\n", iCur);
    iHiwtr = iCur = -1;
    sqlite3_db_status(db, 9, &iCur, &iHiwtr, 1);
    fprintf(pArg->out, "Page cache writes:                   %d\n", iCur);
    iHiwtr = iCur = -1;
    sqlite3_db_status(db, 12, &iCur, &iHiwtr, 1);
    fprintf(pArg->out, "Page cache spills:                   %d\n", iCur);
    iHiwtr = iCur = -1;
    sqlite3_db_status(db, 2, &iCur, &iHiwtr, bReset);
    fprintf(pArg->out, "Schema Heap Usage:                   %d bytes\n", iCur);
    iHiwtr = iCur = -1;
    sqlite3_db_status(db, 3, &iCur, &iHiwtr, bReset);
    fprintf(pArg->out, "Statement Heap/Lookaside Usage:      %d bytes\n", iCur);
  }
  if (pArg->pStmt) {
    int iHit, iMiss;
    iCur = sqlite3_stmt_status(pArg->pStmt, 1, bReset);
    fprintf(pArg->out, "Fullscan Steps:                      %d\n", iCur);
    iCur = sqlite3_stmt_status(pArg->pStmt, 2, bReset);
    fprintf(pArg->out, "Sort Operations:                     %d\n", iCur);
    iCur = sqlite3_stmt_status(pArg->pStmt, 3, bReset);
    fprintf(pArg->out, "Autoindex Inserts:                   %d\n", iCur);
    iHit = sqlite3_stmt_status(pArg->pStmt, 8, bReset);
    iMiss = sqlite3_stmt_status(pArg->pStmt, 7, bReset);
    if (iHit || iMiss) {
      fprintf(pArg->out, "Bloom filter bypass taken:           %d/%d\n", iHit,
              iHit + iMiss);
    }
    iCur = sqlite3_stmt_status(pArg->pStmt, 4, bReset);
    fprintf(pArg->out, "Virtual Machine Steps:               %d\n", iCur);
    iCur = sqlite3_stmt_status(pArg->pStmt, 5, bReset);
    fprintf(pArg->out, "Reprepare operations:                %d\n", iCur);
    iCur = sqlite3_stmt_status(pArg->pStmt, 6, bReset);
    fprintf(pArg->out, "Number of times run:                 %d\n", iCur);
    iCur = sqlite3_stmt_status(pArg->pStmt, 99, bReset);
    fprintf(pArg->out, "Memory used by prepared stmt:        %d\n", iCur);
  }
  displayLinuxIoStats(pArg->out);
  return 0;
}
static void display_scanstats(sqlite3 *db, ShellState *pArg) {
  (void)(db);
  (void)(pArg);
}
static int str_in_array(const char *zStr, const char **azArray) {
  int i;
  for (i = 0; azArray[i]; i++) {
    if (0 == cli_strcmp(zStr, azArray[i]))
      return 1;
  }
  return 0;
}
static void explain_data_prepare(ShellState *p, sqlite3_stmt *pSql) {
  const char *zSql;
  const char *z;
  int *abYield = 0;
  int nAlloc = 0;
  int iOp;
  const char *azNext[] = {"Next",       "Prev",   "VPrev", "VNext",
                          "SorterNext", "Return", 0};
  const char *azYield[] = {"Yield",      "SeekLT", "SeekGT",
                           "RowSetRead", "Rewind", 0};
  const char *azGoto[] = {"Goto", 0};
  if (sqlite3_column_count(pSql) != 8) {
    p->cMode = p->mode;
    return;
  }
  zSql = sqlite3_sql(pSql);
  if (zSql == 0)
    return;
  for (z = zSql;
       *z == ' ' || *z == '\t' || *z == '\n' || *z == 'A' || *z == '\x0d'; z++)
    ;
  if (sqlite3_strnicmp(z, "explain", 7)) {
    p->cMode = p->mode;
    return;
  }
  for (iOp = 0; 100 == sqlite3_step(pSql); iOp++) {
    int i;
    int iAddr = sqlite3_column_int(pSql, 0);
    const char *zOp = (const char *)sqlite3_column_text(pSql, 1);
    int p2 = sqlite3_column_int(pSql, 3);
    int p2op = (p2 + (iOp - iAddr));
    if (iOp >= nAlloc) {
      if (iOp == 0) {
        static const char *explainCols[] = {"addr", "opcode", "p1", "p2",
                                            "p3",   "p4",     "p5", "comment"};
        int jj;
        for (jj = 0; jj < (int)(sizeof(explainCols) / sizeof(explainCols[0]));
             jj++) {
          if (cli_strcmp(sqlite3_column_name(pSql, jj), explainCols[jj]) != 0) {
            p->cMode = p->mode;
            sqlite3_reset(pSql);
            return;
          }
        }
      }
      nAlloc += 100;
      p->aiIndent = (int *)sqlite3_realloc64(p->aiIndent, nAlloc * sizeof(int));
      shell_check_oom(p->aiIndent);
      abYield = (int *)sqlite3_realloc64(abYield, nAlloc * sizeof(int));
      shell_check_oom(abYield);
    }
    abYield[iOp] = str_in_array(zOp, azYield);
    p->aiIndent[iOp] = 0;
    p->nIndent = iOp + 1;
    if (str_in_array(zOp, azNext) && p2op > 0) {
      for (i = p2op; i < iOp; i++)
        p->aiIndent[i] += 2;
    }
    if (str_in_array(zOp, azGoto) && p2op < p->nIndent &&
        (abYield[p2op] || sqlite3_column_int(pSql, 2))) {
      for (i = p2op; i < iOp; i++)
        p->aiIndent[i] += 2;
    }
  }
  p->iIndent = 0;
  sqlite3_free(abYield);
  sqlite3_reset(pSql);
}
static void explain_data_delete(ShellState *p) {
  sqlite3_free(p->aiIndent);
  p->aiIndent = 0;
  p->nIndent = 0;
  p->iIndent = 0;
}
static unsigned int savedSelectTrace;
static unsigned int savedWhereTrace;
static void disable_debug_trace_modes(void) {
  unsigned int zero = 0;
  sqlite3_test_control(31, 0, &savedSelectTrace);
  sqlite3_test_control(31, 1, &zero);
  sqlite3_test_control(31, 2, &savedWhereTrace);
  sqlite3_test_control(31, 3, &zero);
}
static void restore_debug_trace_modes(void) {
  sqlite3_test_control(31, 1, &savedSelectTrace);
  sqlite3_test_control(31, 3, &savedWhereTrace);
}
static void bind_table_init(ShellState *p) {
  int wrSchema = 0;
  int defensiveMode = 0;
  sqlite3_db_config(p->db, 1010, -1, &defensiveMode);
  sqlite3_db_config(p->db, 1010, 0, 0);
  sqlite3_db_config(p->db, 1011, -1, &wrSchema);
  sqlite3_db_config(p->db, 1011, 1, 0);
  sqlite3_exec(p->db,
               "CREATE TABLE IF NOT EXISTS temp.sqlite_parameters(\n  key TEXT "
               "PRIMARY KEY,\n  value\n) WITHOUT ROWID;",
               0, 0, 0);
  sqlite3_db_config(p->db, 1011, wrSchema, 0);
  sqlite3_db_config(p->db, 1010, defensiveMode, 0);
}
static void bind_prepared_stmt(ShellState *pArg, sqlite3_stmt *pStmt) {
  int nVar;
  int i;
  int rc;
  sqlite3_stmt *pQ = 0;
  nVar = sqlite3_bind_parameter_count(pStmt);
  if (nVar == 0)
    return;
  if (sqlite3_table_column_metadata(pArg->db, "TEMP", "sqlite_parameters",
                                    "key", 0, 0, 0, 0, 0) != 0) {
    rc = 12;
    pQ = 0;
  } else {
    rc = sqlite3_prepare_v2(
        pArg->db, "SELECT value FROM temp.sqlite_parameters WHERE key=?1", -1,
        &pQ, 0);
  }
  for (i = 1; i <= nVar; i++) {
    char zNum[30];
    const char *zVar = sqlite3_bind_parameter_name(pStmt, i);
    if (zVar == 0) {
      sqlite3_snprintf(sizeof(zNum), zNum, "?%d", i);
      zVar = zNum;
    }
    sqlite3_bind_text(pQ, 1, zVar, -1, ((sqlite3_destructor_type)0));
    if (rc == 0 && pQ && sqlite3_step(pQ) == 100) {
      sqlite3_bind_value(pStmt, i, sqlite3_column_value(pQ, 0));
    } else if (sqlite3_strlike("_NAN", zVar, 0) == 0) {
      sqlite3_bind_double(pStmt, i, (__builtin_nanf("")));
    } else if (sqlite3_strlike("_INF", zVar, 0) == 0) {
      sqlite3_bind_double(pStmt, i, (__builtin_inff()));
    } else {
      sqlite3_bind_null(pStmt, i);
    }
    sqlite3_reset(pQ);
  }
  sqlite3_finalize(pQ);
}
static void print_box_line(FILE *out, int N) {
  const char zDash[] = "";
  const int nDash = sizeof(zDash) - 1;
  N *= 3;
  while (N > nDash) {
    fprintf(out, zDash);
    N -= nDash;
  }
  fprintf(out, "%.*s", N, zDash);
}
static void print_box_row_separator(ShellState *p, int nArg, const char *zSep1,
                                    const char *zSep2, const char *zSep3) {
  int i;
  if (nArg > 0) {
    fprintf(p->out, "%s", zSep1);
    print_box_line(p->out, p->actualWidth[0] + 2);
    for (i = 1; i < nArg; i++) {
      fprintf(p->out, "%s", zSep2);
      print_box_line(p->out, p->actualWidth[i] + 2);
    }
    fprintf(p->out, "%s", zSep3);
  }
  fputs("\n", p->out);
}
static char *translateForDisplayAndDup(const unsigned char *z,
                                       const unsigned char **pzTail,
                                       int mxWidth, u8 bWordWrap) {
  int i;
  int j;
  int k;
  int n;
  unsigned char *zOut;
  if (z == 0) {
    *pzTail = 0;
    return 0;
  }
  if (mxWidth < 0)
    mxWidth = -mxWidth;
  if (mxWidth == 0)
    mxWidth = 1000000;
  i = j = n = 0;
  while (n < mxWidth) {
    if (z[i] >= ' ') {
      n++;
      do {
        i++;
        j++;
      } while ((z[i] & 192) == 128);
      continue;
    }
    if (z[i] == '\t') {
      do {
        n++;
        j++;
      } while ((n & 7) != 0 && n < mxWidth);
      i++;
      continue;
    }
    break;
  }
  if (n >= mxWidth && bWordWrap) {
    for (k = i; k > i / 2; k--) {
      if (((*__ctype_b_loc())[(int)((z[k - 1]))] &
           (unsigned short int)_ISspace))
        break;
    }
    if (k <= i / 2) {
      for (k = i; k > i / 2; k--) {
        if (((*__ctype_b_loc())[(int)((z[k - 1]))] &
             (unsigned short int)_ISalnum) !=
                ((*__ctype_b_loc())[(int)((z[k]))] &
                 (unsigned short int)_ISalnum) &&
            (z[k] & 192) != 128)
          break;
      }
    }
    if (k <= i / 2) {
      k = i;
    } else {
      i = k;
      while (z[i] == ' ')
        i++;
    }
  } else {
    k = i;
  }
  if (n >= mxWidth && z[i] >= ' ') {
    *pzTail = &z[i];
  } else if (z[i] == '\x0d' && z[i + 1] == '\n') {
    *pzTail = z[i + 2] ? &z[i + 2] : 0;
  } else if (z[i] == 0 || z[i + 1] == 0) {
    *pzTail = 0;
  } else {
    *pzTail = &z[i + 1];
  }
  zOut = malloc(j + 1);
  shell_check_oom(zOut);
  i = j = n = 0;
  while (i < k) {
    if (z[i] >= ' ') {
      n++;
      do {
        zOut[j++] = z[i++];
      } while ((z[i] & 192) == 128);
      continue;
    }
    if (z[i] == '\t') {
      do {
        n++;
        zOut[j++] = ' ';
      } while ((n & 7) != 0 && n < mxWidth);
      i++;
      continue;
    }
    break;
  }
  zOut[j] = 0;
  return (char *)zOut;
}
static char *quoted_column(sqlite3_stmt *pStmt, int i) {
  switch (sqlite3_column_type(pStmt, i)) {
  case 5: {
    return sqlite3_mprintf("NULL");
  }
  case 1:
  case 2: {
    return sqlite3_mprintf("%s", sqlite3_column_text(pStmt, i));
  }
  case 3: {
    return sqlite3_mprintf("%Q", sqlite3_column_text(pStmt, i));
  }
  case 4: {
    int j;
    sqlite3_str *pStr = sqlite3_str_new(0);
    const unsigned char *a = sqlite3_column_blob(pStmt, i);
    int n = sqlite3_column_bytes(pStmt, i);
    sqlite3_str_append(pStr, "x'", 2);
    for (j = 0; j < n; j++) {
      sqlite3_str_appendf(pStr, "%02x", a[j]);
    }
    sqlite3_str_append(pStr, "'", 1);
    return sqlite3_str_finish(pStr);
  }
  }
  return 0;
}
static void exec_prepared_stmt_columnar(ShellState *p, sqlite3_stmt *pStmt) {
  sqlite3_int64 nRow = 0;
  int nColumn = 0;
  char **azData = 0;
  sqlite3_int64 nAlloc = 0;
  char *abRowDiv = 0;
  const unsigned char *uz;
  const char *z;
  char **azQuoted = 0;
  int rc;
  sqlite3_int64 i, nData;
  int j, nTotal, w, n;
  const char *colSep = 0;
  const char *rowSep = 0;
  const unsigned char **azNextLine = 0;
  int bNextLine = 0;
  int bMultiLineRowExists = 0;
  int bw = p->cmOpts.bWordWrap;
  const char *zEmpty = "";
  const char *zShowNull = p->nullValue;
  rc = sqlite3_step(pStmt);
  if (rc != 100)
    return;
  nColumn = sqlite3_column_count(pStmt);
  nAlloc = nColumn * 4;
  if (nAlloc <= 0)
    nAlloc = 1;
  azData = sqlite3_malloc64(nAlloc * sizeof(char *));
  shell_check_oom(azData);
  azNextLine = sqlite3_malloc64(nColumn * sizeof(char *));
  shell_check_oom(azNextLine);
  memset((void *)azNextLine, 0, nColumn * sizeof(char *));
  if (p->cmOpts.bQuote) {
    azQuoted = sqlite3_malloc64(nColumn * sizeof(char *));
    shell_check_oom(azQuoted);
    memset(azQuoted, 0, nColumn * sizeof(char *));
  }
  abRowDiv = sqlite3_malloc64(nAlloc / nColumn);
  shell_check_oom(abRowDiv);
  if (nColumn > p->nWidth) {
    p->colWidth = realloc(p->colWidth, (nColumn + 1) * 2 * sizeof(int));
    shell_check_oom(p->colWidth);
    for (i = p->nWidth; i < nColumn; i++)
      p->colWidth[i] = 0;
    p->nWidth = nColumn;
    p->actualWidth = &p->colWidth[nColumn];
  }
  memset(p->actualWidth, 0, nColumn * sizeof(int));
  for (i = 0; i < nColumn; i++) {
    w = p->colWidth[i];
    if (w < 0)
      w = -w;
    p->actualWidth[i] = w;
  }
  for (i = 0; i < nColumn; i++) {
    const unsigned char *zNotUsed;
    int wx = p->colWidth[i];
    if (wx == 0) {
      wx = p->cmOpts.iWrap;
    }
    if (wx < 0)
      wx = -wx;
    uz = (const unsigned char *)sqlite3_column_name(pStmt, i);
    if (uz == 0)
      uz = (u8 *)"";
    azData[i] = translateForDisplayAndDup(uz, &zNotUsed, wx, bw);
  }
  do {
    int useNextLine = bNextLine;
    bNextLine = 0;
    if ((nRow + 2) * nColumn >= nAlloc) {
      nAlloc *= 2;
      azData = sqlite3_realloc64(azData, nAlloc * sizeof(char *));
      shell_check_oom(azData);
      abRowDiv = sqlite3_realloc64(abRowDiv, nAlloc / nColumn);
      shell_check_oom(abRowDiv);
    }
    abRowDiv[nRow] = 1;
    nRow++;
    for (i = 0; i < nColumn; i++) {
      int wx = p->colWidth[i];
      if (wx == 0) {
        wx = p->cmOpts.iWrap;
      }
      if (wx < 0)
        wx = -wx;
      if (useNextLine) {
        uz = azNextLine[i];
        if (uz == 0)
          uz = (u8 *)zEmpty;
      } else if (p->cmOpts.bQuote) {
        sqlite3_free(azQuoted[i]);
        azQuoted[i] = quoted_column(pStmt, i);
        uz = (const unsigned char *)azQuoted[i];
      } else {
        uz = (const unsigned char *)sqlite3_column_text(pStmt, i);
        if (uz == 0)
          uz = (u8 *)zShowNull;
      }
      azData[nRow * nColumn + i] =
          translateForDisplayAndDup(uz, &azNextLine[i], wx, bw);
      if (azNextLine[i]) {
        bNextLine = 1;
        abRowDiv[nRow - 1] = 0;
        bMultiLineRowExists = 1;
      }
    }
  } while (bNextLine || sqlite3_step(pStmt) == 100);
  nTotal = nColumn * (nRow + 1);
  for (i = 0; i < nTotal; i++) {
    z = azData[i];
    if (z == 0)
      z = (char *)zEmpty;
    n = strlenChar(z);
    j = i % nColumn;
    if (n > p->actualWidth[j])
      p->actualWidth[j] = n;
  }
  if (seenInterrupt)
    goto columnar_end;
  if (nColumn == 0)
    goto columnar_end;
  switch (p->cMode) {
  case 1: {
    colSep = "  ";
    rowSep = "\n";
    if (p->showHeader) {
      for (i = 0; i < nColumn; i++) {
        w = p->actualWidth[i];
        if (p->colWidth[i] < 0)
          w = -w;
        utf8_width_print(p->out, w, azData[i]);
        fputs(i == nColumn - 1 ? "\n" : "  ", p->out);
      }
      for (i = 0; i < nColumn; i++) {
        print_dashes(p->out, p->actualWidth[i]);
        fputs(i == nColumn - 1 ? "\n" : "  ", p->out);
      }
    }
    break;
  }
  case 15: {
    colSep = " | ";
    rowSep = " |\n";
    print_row_separator(p, nColumn, "+");
    fputs("| ", p->out);
    for (i = 0; i < nColumn; i++) {
      w = p->actualWidth[i];
      n = strlenChar(azData[i]);
      fprintf(p->out, "%*s%s%*s", (w - n) / 2, "", azData[i], (w - n + 1) / 2,
              "");
      fputs(i == nColumn - 1 ? " |\n" : " | ", p->out);
    }
    print_row_separator(p, nColumn, "+");
    break;
  }
  case 14: {
    colSep = " | ";
    rowSep = " |\n";
    fputs("| ", p->out);
    for (i = 0; i < nColumn; i++) {
      w = p->actualWidth[i];
      n = strlenChar(azData[i]);
      fprintf(p->out, "%*s%s%*s", (w - n) / 2, "", azData[i], (w - n + 1) / 2,
              "");
      fputs(i == nColumn - 1 ? " |\n" : " | ", p->out);
    }
    print_row_separator(p, nColumn, "|");
    break;
  }
  case 16: {
    colSep = "  ";
    rowSep = " \n";
    print_box_row_separator(p, nColumn, "", "", "");
    fprintf(p->out, " ");
    for (i = 0; i < nColumn; i++) {
      w = p->actualWidth[i];
      n = strlenChar(azData[i]);
      fprintf(p->out, "%*s%s%*s%s", (w - n) / 2, "", azData[i], (w - n + 1) / 2,
              "", i == nColumn - 1 ? " \n" : "  ");
    }
    print_box_row_separator(p, nColumn, "", "", "");
    break;
  }
  }
  for (i = nColumn, j = 0; i < nTotal; i++, j++) {
    if (j == 0 && p->cMode != 1) {
      fprintf(p->out, "%s", p->cMode == 16 ? " " : "| ");
    }
    z = azData[i];
    if (z == 0)
      z = p->nullValue;
    w = p->actualWidth[j];
    if (p->colWidth[j] < 0)
      w = -w;
    utf8_width_print(p->out, w, z);
    if (j == nColumn - 1) {
      fprintf(p->out, "%s", rowSep);
      if (bMultiLineRowExists && abRowDiv[i / nColumn - 1] && i + 1 < nTotal) {
        if (p->cMode == 15) {
          print_row_separator(p, nColumn, "+");
        } else if (p->cMode == 16) {
          print_box_row_separator(p, nColumn, "", "", "");
        } else if (p->cMode == 1) {
          fprintf(p->out, "\n");
        }
      }
      j = -1;
      if (seenInterrupt)
        goto columnar_end;
    } else {
      fprintf(p->out, "%s", colSep);
    }
  }
  if (p->cMode == 15) {
    print_row_separator(p, nColumn, "+");
  } else if (p->cMode == 16) {
    print_box_row_separator(p, nColumn, "", "", "");
  }
columnar_end:
  if (seenInterrupt) {
    fprintf(p->out, "Interrupt\n");
  }
  nData = (nRow + 1) * nColumn;
  for (i = 0; i < nData; i++) {
    z = azData[i];
    if (z != zEmpty && z != zShowNull)
      free(azData[i]);
  }
  sqlite3_free(azData);
  sqlite3_free((void *)azNextLine);
  sqlite3_free(abRowDiv);
  if (azQuoted) {
    for (i = 0; i < nColumn; i++)
      sqlite3_free(azQuoted[i]);
    sqlite3_free(azQuoted);
  }
}
static void exec_prepared_stmt(ShellState *pArg, sqlite3_stmt *pStmt) {
  int rc;
  sqlite3_uint64 nRow = 0;
  if (pArg->cMode == 1 || pArg->cMode == 15 || pArg->cMode == 16 ||
      pArg->cMode == 14) {
    exec_prepared_stmt_columnar(pArg, pStmt);
    return;
  }
  rc = sqlite3_step(pStmt);
  if (100 == rc) {
    int nCol = sqlite3_column_count(pStmt);
    void *pData = sqlite3_malloc64(3 * nCol * sizeof(const char *) + 1);
    if (!pData) {
      shell_out_of_memory();
    } else {
      char **azCols = (char **)pData;
      char **azVals = &azCols[nCol];
      int *aiTypes = (int *)&azVals[nCol];
      int i, x;
      ((void)sizeof((sizeof(int) <= sizeof(char *)) ? 1 : 0), ({
         if (sizeof(int) <= sizeof(char *))
           ;
         else
           __assert_fail("sizeof(int) <= sizeof(char *)", "shell.c", 19378,
                         __PRETTY_FUNCTION__);
       }));
      for (i = 0; i < nCol; i++) {
        azCols[i] = (char *)sqlite3_column_name(pStmt, i);
      }
      do {
        nRow++;
        for (i = 0; i < nCol; i++) {
          aiTypes[i] = x = sqlite3_column_type(pStmt, i);
          if (x == 4 && pArg && (pArg->cMode == 5 || pArg->cMode == 6)) {
            azVals[i] = "";
          } else {
            azVals[i] = (char *)sqlite3_column_text(pStmt, i);
          }
          if (!azVals[i] && (aiTypes[i] != 5)) {
            rc = 7;
            break;
          }
        }
        if (100 == rc) {
          if (shell_callback(pArg, nCol, azVals, azCols, aiTypes)) {
            rc = 4;
          } else {
            rc = sqlite3_step(pStmt);
          }
        }
      } while (100 == rc);
      sqlite3_free(pData);
      if (pArg->cMode == 13) {
        fputs("]\n", pArg->out);
      } else if (pArg->cMode == 17) {
        char zBuf[200];
        sqlite3_snprintf(sizeof(zBuf), zBuf, "%llu row%s\n", nRow,
                         nRow != 1 ? "s" : "");
        printf("%s", zBuf);
      }
    }
  }
}
static int expertHandleSQL(ShellState *pState, const char *zSql, char **pzErr) {
  ((void)sizeof((pState->expert.pExpert) ? 1 : 0), ({
     if (pState->expert.pExpert)
       ;
     else
       __assert_fail("pState->expert.pExpert", "shell.c", 19441,
                     __PRETTY_FUNCTION__);
   }));
  ((void)sizeof((pzErr == 0 || *pzErr == 0) ? 1 : 0), ({
     if (pzErr == 0 || *pzErr == 0)
       ;
     else
       __assert_fail("pzErr==0 || *pzErr==0", "shell.c", 19442,
                     __PRETTY_FUNCTION__);
   }));
  return sqlite3_expert_sql(pState->expert.pExpert, zSql, pzErr);
}
static int expertFinish(ShellState *pState, int bCancel, char **pzErr) {
  int rc = 0;
  sqlite3expert *p = pState->expert.pExpert;
  ((void)sizeof((p) ? 1 : 0), ({
     if (p)
       ;
     else
       __assert_fail("p", "shell.c", 19463, __PRETTY_FUNCTION__);
   }));
  ((void)sizeof((bCancel || pzErr == 0 || *pzErr == 0) ? 1 : 0), ({
     if (bCancel || pzErr == 0 || *pzErr == 0)
       ;
     else
       __assert_fail("bCancel || pzErr==0 || *pzErr==0", "shell.c", 19464,
                     __PRETTY_FUNCTION__);
   }));
  if (bCancel == 0) {
    FILE *out = pState->out;
    int bVerbose = pState->expert.bVerbose;
    rc = sqlite3_expert_analyze(p, pzErr);
    if (rc == 0) {
      int nQuery = sqlite3_expert_count(p);
      int i;
      if (bVerbose) {
        const char *zCand = sqlite3_expert_report(p, 0, 4);
        fprintf(out, "-- Candidates -----------------------------\n");
        fprintf(out, "%s\n", zCand);
      }
      for (i = 0; i < nQuery; i++) {
        const char *zSql = sqlite3_expert_report(p, i, 1);
        const char *zIdx = sqlite3_expert_report(p, i, 2);
        const char *zEQP = sqlite3_expert_report(p, i, 3);
        if (zIdx == 0)
          zIdx = "(no new indexes)\n";
        if (bVerbose) {
          fprintf(out, "-- Query %d --------------------------------\n", i + 1);
          fprintf(out, "%s\n\n", zSql);
        }
        fprintf(out, "%s\n", zIdx);
        fprintf(out, "%s\n", zEQP);
      }
    }
  }
  sqlite3_expert_destroy(p);
  pState->expert.pExpert = 0;
  return rc;
}
static int expertDotCommand(ShellState *pState, char **azArg, int nArg) {
  int rc = 0;
  char *zErr = 0;
  int i;
  int iSample = 0;
  ((void)sizeof((pState->expert.pExpert == 0) ? 1 : 0), ({
     if (pState->expert.pExpert == 0)
       ;
     else
       __assert_fail("pState->expert.pExpert==0", "shell.c", 19511,
                     __PRETTY_FUNCTION__);
   }));
  memset(&pState->expert, 0, sizeof(ExpertInfo));
  for (i = 1; rc == 0 && i < nArg; i++) {
    char *z = azArg[i];
    int n;
    if (z[0] == '-' && z[1] == '-')
      z++;
    n = strlen30(z);
    if (n >= 2 && 0 == cli_strncmp(z, "-verbose", n)) {
      pState->expert.bVerbose = 1;
    } else if (n >= 2 && 0 == cli_strncmp(z, "-sample", n)) {
      if (i == (nArg - 1)) {
        fprintf(stderr, "option requires an argument: %s\n", z);
        rc = 1;
      } else {
        iSample = (int)integerValue(azArg[++i]);
        if (iSample < 0 || iSample > 100) {
          fprintf(stderr, "value out of range: %s\n", azArg[i]);
          rc = 1;
        }
      }
    } else {
      fprintf(stderr, "unknown option: %s\n", z);
      rc = 1;
    }
  }
  if (rc == 0) {
    pState->expert.pExpert = sqlite3_expert_new(pState->db, &zErr);
    if (pState->expert.pExpert == 0) {
      fprintf(stderr, "sqlite3_expert_new: %s\n",
              zErr ? zErr : "out of memory");
      rc = 1;
    } else {
      sqlite3_expert_config(pState->expert.pExpert, 1, iSample);
    }
  }
  sqlite3_free(zErr);
  return rc;
}
static int shell_exec(ShellState *pArg, const char *zSql, char **pzErrMsg) {
  sqlite3_stmt *pStmt = ((void *)0);
  int rc = 0;
  int rc2;
  const char *zLeftover;
  sqlite3 *db = pArg->db;
  if (pzErrMsg) {
    *pzErrMsg = ((void *)0);
  }
  if (pArg->expert.pExpert) {
    rc = expertHandleSQL(pArg, zSql, pzErrMsg);
    return expertFinish(pArg, (rc != 0), pzErrMsg);
  }
  while (zSql[0] && (0 == rc)) {
    static const char *zStmtSql;
    rc = sqlite3_prepare_v2(db, zSql, -1, &pStmt, &zLeftover);
    if (0 != rc) {
      if (pzErrMsg) {
        *pzErrMsg = save_err_msg(db, "in prepare", rc, zSql);
      }
    } else {
      if (!pStmt) {
        zSql = zLeftover;
        while (((*__ctype_b_loc())[(int)(((unsigned char)zSql[0]))] &
                (unsigned short int)_ISspace))
          zSql++;
        continue;
      }
      zStmtSql = sqlite3_sql(pStmt);
      if (zStmtSql == 0)
        zStmtSql = "";
      while (((*__ctype_b_loc())[(int)(((unsigned char)zStmtSql[0]))] &
              (unsigned short int)_ISspace))
        zStmtSql++;
      if (pArg) {
        pArg->pStmt = pStmt;
        pArg->cnt = 0;
      }
      if (pArg && pArg->autoEQP && sqlite3_stmt_isexplain(pStmt) == 0) {
        sqlite3_stmt *pExplain;
        char *zEQP;
        int triggerEQP = 0;
        disable_debug_trace_modes();
        sqlite3_db_config(db, 1008, -1, &triggerEQP);
        if (pArg->autoEQP >= 2) {
          sqlite3_db_config(db, 1008, 1, 0);
        }
        zEQP = sqlite3_mprintf("EXPLAIN QUERY PLAN %s", zStmtSql);
        shell_check_oom(zEQP);
        rc = sqlite3_prepare_v2(db, zEQP, -1, &pExplain, 0);
        if (rc == 0) {
          while (sqlite3_step(pExplain) == 100) {
            const char *zEQPLine =
                (const char *)sqlite3_column_text(pExplain, 3);
            int iEqpId = sqlite3_column_int(pExplain, 0);
            int iParentId = sqlite3_column_int(pExplain, 1);
            if (zEQPLine == 0)
              zEQPLine = "";
            if (zEQPLine[0] == '-')
              eqp_render(pArg, 0);
            eqp_append(pArg, iEqpId, iParentId, zEQPLine);
          }
          eqp_render(pArg, 0);
        }
        sqlite3_finalize(pExplain);
        sqlite3_free(zEQP);
        if (pArg->autoEQP >= 3) {
          zEQP = sqlite3_mprintf("EXPLAIN %s", zStmtSql);
          shell_check_oom(zEQP);
          rc = sqlite3_prepare_v2(db, zEQP, -1, &pExplain, 0);
          if (rc == 0) {
            pArg->cMode = 9;
            explain_data_prepare(pArg, pExplain);
            exec_prepared_stmt(pArg, pExplain);
            explain_data_delete(pArg);
          }
          sqlite3_finalize(pExplain);
          sqlite3_free(zEQP);
        }
        if (pArg->autoEQP >= 2 && triggerEQP == 0) {
          sqlite3_db_config(db, 1008, 0, 0);
          sqlite3_finalize(pStmt);
          sqlite3_prepare_v2(db, zSql, -1, &pStmt, 0);
          if (pArg)
            pArg->pStmt = pStmt;
        }
        restore_debug_trace_modes();
      }
      if (pArg) {
        pArg->cMode = pArg->mode;
        if (pArg->autoExplain) {
          if (sqlite3_stmt_isexplain(pStmt) == 1) {
            pArg->cMode = 9;
          }
          if (sqlite3_stmt_isexplain(pStmt) == 2) {
            pArg->cMode = 12;
          }
        }
        if (pArg->cMode == 9) {
          explain_data_prepare(pArg, pStmt);
        }
      }
      bind_prepared_stmt(pArg, pStmt);
      exec_prepared_stmt(pArg, pStmt);
      explain_data_delete(pArg);
      eqp_render(pArg, 0);
      if (pArg && pArg->statsOn) {
        display_stats(db, pArg, 0);
      }
      if (pArg && pArg->scanstatsOn) {
        display_scanstats(db, pArg);
      }
      rc2 = sqlite3_finalize(pStmt);
      if (rc != 7)
        rc = rc2;
      if (rc == 0) {
        zSql = zLeftover;
        while (((*__ctype_b_loc())[(int)(((unsigned char)zSql[0]))] &
                (unsigned short int)_ISspace))
          zSql++;
      } else if (pzErrMsg) {
        *pzErrMsg = save_err_msg(db, "stepping", rc, 0);
      }
      if (pArg) {
        pArg->pStmt = ((void *)0);
      }
    }
  }
  return rc;
}
static void freeColumnList(char **azCol) {
  int i;
  for (i = 1; azCol[i]; i++) {
    sqlite3_free(azCol[i]);
  }
  sqlite3_free(azCol);
}
static char **tableColumnList(ShellState *p, const char *zTab) {
  char **azCol = 0;
  sqlite3_stmt *pStmt;
  char *zSql;
  int nCol = 0;
  int nAlloc = 0;
  int nPK = 0;
  int isIPK = 0;
  int preserveRowid = (((p)->shellFlgs & (8)) != 0);
  int rc;
  zSql = sqlite3_mprintf("PRAGMA table_info=%Q", zTab);
  shell_check_oom(zSql);
  rc = sqlite3_prepare_v2(p->db, zSql, -1, &pStmt, 0);
  sqlite3_free(zSql);
  if (rc)
    return 0;
  while (sqlite3_step(pStmt) == 100) {
    if (nCol >= nAlloc - 2) {
      nAlloc = nAlloc * 2 + nCol + 10;
      azCol = sqlite3_realloc(azCol, nAlloc * sizeof(azCol[0]));
      shell_check_oom(azCol);
    }
    azCol[++nCol] = sqlite3_mprintf("%s", sqlite3_column_text(pStmt, 1));
    shell_check_oom(azCol[nCol]);
    if (sqlite3_column_int(pStmt, 5)) {
      nPK++;
      if (nPK == 1 &&
          sqlite3_stricmp((const char *)sqlite3_column_text(pStmt, 2),
                          "INTEGER") == 0) {
        isIPK = 1;
      } else {
        isIPK = 0;
      }
    }
  }
  sqlite3_finalize(pStmt);
  if (azCol == 0)
    return 0;
  azCol[0] = 0;
  azCol[nCol + 1] = 0;
  if (preserveRowid && isIPK) {
    zSql = sqlite3_mprintf(
        "SELECT 1 FROM pragma_index_list(%Q) WHERE origin='pk'", zTab);
    shell_check_oom(zSql);
    rc = sqlite3_prepare_v2(p->db, zSql, -1, &pStmt, 0);
    sqlite3_free(zSql);
    if (rc) {
      freeColumnList(azCol);
      return 0;
    }
    rc = sqlite3_step(pStmt);
    sqlite3_finalize(pStmt);
    preserveRowid = rc == 100;
  }
  if (preserveRowid) {
    static char *azRowid[] = {"rowid", "_rowid_", "oid"};
    int i, j;
    for (j = 0; j < 3; j++) {
      for (i = 1; i <= nCol; i++) {
        if (sqlite3_stricmp(azRowid[j], azCol[i]) == 0)
          break;
      }
      if (i > nCol) {
        rc = sqlite3_table_column_metadata(p->db, 0, zTab, azRowid[j], 0, 0, 0,
                                           0, 0);
        if (rc == 0)
          azCol[0] = azRowid[j];
        break;
      }
    }
  }
  return azCol;
}
static void toggleSelectOrder(sqlite3 *db) {
  sqlite3_stmt *pStmt = 0;
  int iSetting = 0;
  char zStmt[100];
  sqlite3_prepare_v2(db, "PRAGMA reverse_unordered_selects", -1, &pStmt, 0);
  if (sqlite3_step(pStmt) == 100) {
    iSetting = sqlite3_column_int(pStmt, 0);
  }
  sqlite3_finalize(pStmt);
  sqlite3_snprintf(sizeof(zStmt), zStmt, "PRAGMA reverse_unordered_selects(%d)",
                   !iSetting);
  sqlite3_exec(db, zStmt, 0, 0, 0);
}
static int dump_callback(void *pArg, int nArg, char **azArg, char **azNotUsed) {
  int rc;
  const char *zTable;
  const char *zType;
  const char *zSql;
  ShellState *p = (ShellState *)pArg;
  int dataOnly;
  int noSys;
  (void)(azNotUsed);
  if (nArg != 3 || azArg == 0)
    return 0;
  zTable = azArg[0];
  zType = azArg[1];
  zSql = azArg[2];
  if (zTable == 0)
    return 0;
  if (zType == 0)
    return 0;
  dataOnly = (p->shellFlgs & 256) != 0;
  noSys = (p->shellFlgs & 512) != 0;
  if (cli_strcmp(zTable, "sqlite_sequence") == 0 && !noSys) {
    if (!dataOnly)
      fprintf(p->out, "DELETE FROM sqlite_sequence;\n");
  } else if (sqlite3_strglob("sqlite_stat?", zTable) == 0 && !noSys) {
    if (!dataOnly)
      fprintf(p->out, "ANALYZE sqlite_schema;\n");
  } else if (cli_strncmp(zTable, "sqlite_", 7) == 0) {
    return 0;
  } else if (dataOnly) {
  } else if (cli_strncmp(zSql, "CREATE VIRTUAL TABLE", 20) == 0) {
    char *zIns;
    if (!p->writableSchema) {
      fprintf(p->out, "PRAGMA writable_schema=ON;\n");
      p->writableSchema = 1;
    }
    zIns = sqlite3_mprintf("INSERT INTO "
                           "sqlite_schema(type,name,tbl_name,rootpage,sql)"
                           "VALUES('table','%q','%q',0,'%q');",
                           zTable, zTable, zSql);
    shell_check_oom(zIns);
    fprintf(p->out, "%s\n", zIns);
    sqlite3_free(zIns);
    return 0;
  } else {
    printSchemaLine(p->out, zSql, ";\n");
  }
  if (cli_strcmp(zType, "table") == 0) {
    ShellText sSelect;
    ShellText sTable;
    char **azCol;
    int i;
    char *savedDestTable;
    int savedMode;
    azCol = tableColumnList(p, zTable);
    if (azCol == 0) {
      p->nErr++;
      return 0;
    }
    initText(&sTable);
    appendText(&sTable, zTable, quoteChar(zTable));
    if (azCol[0]) {
      appendText(&sTable, "(", 0);
      appendText(&sTable, azCol[0], 0);
      for (i = 1; azCol[i]; i++) {
        appendText(&sTable, ",", 0);
        appendText(&sTable, azCol[i], quoteChar(azCol[i]));
      }
      appendText(&sTable, ")", 0);
    }
    initText(&sSelect);
    appendText(&sSelect, "SELECT ", 0);
    if (azCol[0]) {
      appendText(&sSelect, azCol[0], 0);
      appendText(&sSelect, ",", 0);
    }
    for (i = 1; azCol[i]; i++) {
      appendText(&sSelect, azCol[i], quoteChar(azCol[i]));
      if (azCol[i + 1]) {
        appendText(&sSelect, ",", 0);
      }
    }
    freeColumnList(azCol);
    appendText(&sSelect, " FROM ", 0);
    appendText(&sSelect, zTable, quoteChar(zTable));
    savedDestTable = p->zDestTable;
    savedMode = p->mode;
    p->zDestTable = sTable.z;
    p->mode = p->cMode = 5;
    rc = shell_exec(p, sSelect.z, 0);
    if ((rc & 255) == 11) {
      fprintf(p->out, "/****** CORRUPTION ERROR *******/\n");
      toggleSelectOrder(p->db);
      shell_exec(p, sSelect.z, 0);
      toggleSelectOrder(p->db);
    }
    p->zDestTable = savedDestTable;
    p->mode = savedMode;
    freeText(&sTable);
    freeText(&sSelect);
    if (rc)
      p->nErr++;
  }
  return 0;
}
static int run_schema_dump_query(ShellState *p, const char *zQuery) {
  int rc;
  char *zErr = 0;
  rc = sqlite3_exec(p->db, zQuery, dump_callback, p, &zErr);
  if (rc == 11) {
    char *zQ2;
    int len = strlen30(zQuery);
    fprintf(p->out, "/****** CORRUPTION ERROR *******/\n");
    if (zErr) {
      fprintf(p->out, "/****** %s ******/\n", zErr);
      sqlite3_free(zErr);
      zErr = 0;
    }
    zQ2 = malloc(len + 100);
    if (zQ2 == 0)
      return rc;
    sqlite3_snprintf(len + 100, zQ2, "%s ORDER BY rowid DESC", zQuery);
    rc = sqlite3_exec(p->db, zQ2, dump_callback, p, &zErr);
    if (rc) {
      fprintf(p->out, "/****** ERROR: %s ******/\n", zErr);
    } else {
      rc = 11;
    }
    sqlite3_free(zErr);
    free(zQ2);
  }
  return rc;
}
static const char *(azHelp[]) = {
    ".auth ON|OFF             Show authorizer callbacks",
    ".backup ?DB? FILE        Backup DB (default \"main\") to FILE",
    "   Options:",
    "       --append            Use the appendvfs",
    "       --async             Write to FILE without journal and fsync()",
    ".bail on|off             Stop after hitting an error.  Default OFF",
    ".binary on|off           Turn binary output on or off.  Default OFF",
    ".cd DIRECTORY            Change the working directory to DIRECTORY",
    ".changes on|off          Show number of rows changed by SQL",
    ".check GLOB              Fail if output since .testcase does not match",
    ".clone NEWDB             Clone data into NEWDB from the existing database",
    ".databases               List names and files of attached databases",
    ".dbconfig ?op? ?val?     List or change sqlite3_db_config() options",
    ".dump ?OBJECTS?          Render database content as SQL",
    "   Options:",
    "     --data-only            Output only INSERT statements",
    "     --newlines             Allow unescaped newline characters in output",
    "     --nosys                Omit system tables (ex: \"sqlite_stat1\")",
    "     --preserve-rowids      Include ROWID values in the output",
    "   OBJECTS is a LIKE pattern for tables, indexes, triggers or views to "
    "dump",
    "   Additional LIKE patterns can be given in subsequent arguments",
    ".echo on|off             Turn command echo on or off",
    ".eqp on|off|full|...     Enable or disable automatic EXPLAIN QUERY PLAN",
    "   Other Modes:",
    "      trigger               Like \"full\" but also show trigger bytecode",
    ".excel                   Display the output of next command in "
    "spreadsheet",
    "   --bom                   Put a UTF8 byte-order mark on intermediate "
    "file",
    ".exit ?CODE?             Exit this program with return-code CODE",
    ".expert                  EXPERIMENTAL. Suggest indexes for queries",
    ".explain ?on|off|auto?   Change the EXPLAIN formatting mode.  Default: "
    "auto",
    ".filectrl CMD ...        Run various sqlite3_file_control() operations",
    "   --schema SCHEMA         Use SCHEMA instead of \"main\"",
    "   --help                  Show CMD details",
    ".fullschema ?--indent?   Show schema and the content of sqlite_stat "
    "tables",
    ".headers on|off          Turn display of headers on or off",
    ".help ?-all? ?PATTERN?   Show help text for PATTERN",
    ".import FILE TABLE       Import data from FILE into TABLE",
    "   Options:",
    "     --ascii               Use \\037 and \\036 as column and row "
    "separators",
    "     --csv                 Use , and \\n as column and row separators",
    "     --skip N              Skip the first N rows of input",
    "     --schema S            Target table to be S.TABLE",
    "     -v                    \"Verbose\" - increase auxiliary output",
    "   Notes:",
    "     *  If TABLE does not exist, it is created.  The first row of input",
    "        determines the column names.",
    "     *  If neither --csv or --ascii are used, the input mode is derived",
    "        from the \".mode\" output mode",
    "     *  If FILE begins with \"|\" then it is a command that generates the",
    "        input text.",
    ",imposter INDEX TABLE    Create imposter table TABLE on index INDEX",
    ".indexes ?TABLE?         Show names of indexes",
    "                           If TABLE is specified, only show indexes for",
    "                           tables matching TABLE using the LIKE operator.",
    ".limit ?LIMIT? ?VAL?     Display or change the value of an SQLITE_LIMIT",
    ".lint OPTIONS            Report potential schema issues.",
    "     Options:",
    "        fkey-indexes     Find missing foreign key indexes",
    ".load FILE ?ENTRY?       Load an extension library",
    ".log FILE|on|off         Turn logging on or off.  FILE can be "
    "stderr/stdout",
    ".mode MODE ?OPTIONS?     Set output mode",
    "   MODE is one of:",
    "     ascii       Columns/rows delimited by 0x1F and 0x1E",
    "     box         Tables using unicode box-drawing characters",
    "     csv         Comma-separated values",
    "     column      Output in columns.  (See .width)",
    "     html        HTML <table> code",
    "     insert      SQL insert statements for TABLE",
    "     json        Results in a JSON array",
    "     line        One value per line",
    "     list        Values delimited by \"|\"",
    "     markdown    Markdown table format",
    "     qbox        Shorthand for \"box --wrap 60 --quote\"",
    "     quote       Escape answers as for SQL",
    "     table       ASCII-art table",
    "     tabs        Tab-separated values",
    "     tcl         TCL list elements",
    "   OPTIONS: (for columnar modes or insert mode):",
    "     --wrap N       Wrap output lines to no longer than N characters",
    "     --wordwrap B   Wrap or not at word boundaries per B (on/off)",
    "     --ww           Shorthand for \"--wordwrap 1\"",
    "     --quote        Quote output text as SQL literals",
    "     --noquote      Do not quote output text",
    "     TABLE          The name of SQL table used for \"insert\" mode",
    ".nonce STRING            Suspend safe mode for one command if nonce "
    "matches",
    ".nullvalue STRING        Use STRING in place of NULL values",
    ".once ?OPTIONS? ?FILE?   Output for the next SQL command only to FILE",
    "     If FILE begins with '|' then open as a pipe",
    "       --bom  Put a UTF8 byte-order mark at the beginning",
    "       -e     Send output to the system text editor",
    "       -x     Send output as CSV to a spreadsheet (same as \".excel\")",
    ".open ?OPTIONS? ?FILE?   Close existing database and reopen FILE",
    "     Options:",
    "        --append        Use appendvfs to append database to the end of "
    "FILE",
    "        --deserialize   Load into memory using sqlite3_deserialize()",
    "        --hexdb         Load the output of \"dbtotxt\" as an in-memory db",
    "        --maxsize N     Maximum size for --hexdb or --deserialized "
    "database",
    "        --new           Initialize FILE to an empty database",
    "        --nofollow      Do not follow symbolic links",
    "        --readonly      Open FILE readonly",
    "        --zip           FILE is a ZIP archive",
    ".output ?FILE?           Send output to FILE or stdout if FILE is omitted",
    "   If FILE begins with '|' then open it as a pipe.",
    "   Options:",
    "     --bom                 Prefix output with a UTF8 byte-order mark",
    "     -e                    Send output to the system text editor",
    "     -x                    Send output as CSV to a spreadsheet",
    ".parameter CMD ...       Manage SQL parameter bindings",
    "   clear                   Erase all bindings",
    "   init                    Initialize the TEMP table that holds bindings",
    "   list                    List the current parameter bindings",
    "   set PARAMETER VALUE     Given SQL parameter PARAMETER a value of VALUE",
    "                           PARAMETER should start with one of: $ : @ ?",
    "   unset PARAMETER         Remove PARAMETER from the binding table",
    ".print STRING...         Print literal STRING",
    ".progress N              Invoke progress handler after every N opcodes",
    "   --limit N                 Interrupt after N progress callbacks",
    "   --once                    Do no more than one progress interrupt",
    "   --quiet|-q                No output except at interrupts",
    "   --reset                   Reset the count for each input and interrupt",
    ".prompt MAIN CONTINUE    Replace the standard prompts",
    ".quit                    Stop interpreting input stream, exit if primary.",
    ".read FILE               Read input from FILE or command output",
    "    If FILE begins with \"|\", it is a command that generates the input.",
    ".restore ?DB? FILE       Restore content of DB (default \"main\") from "
    "FILE",
    ".save ?OPTIONS? FILE     Write database to FILE (an alias for .backup "
    "...)",
    ".scanstats on|off|est    Turn sqlite3_stmt_scanstatus() metrics on or off",
    ".schema ?PATTERN?        Show the CREATE statements matching PATTERN",
    "   Options:",
    "      --indent             Try to pretty-print the schema",
    "      --nosys              Omit objects whose names start with "
    "\"sqlite_\"",
    ",selftest ?OPTIONS?      Run tests defined in the SELFTEST table",
    "    Options:",
    "       --init               Create a new SELFTEST table",
    "       -v                   Verbose output",
    ".separator COL ?ROW?     Change the column and row separators",
    ".sha3sum ...             Compute a SHA3 hash of database content",
    "    Options:",
    "      --schema              Also hash the sqlite_schema table",
    "      --sha3-224            Use the sha3-224 algorithm",
    "      --sha3-256            Use the sha3-256 algorithm (default)",
    "      --sha3-384            Use the sha3-384 algorithm",
    "      --sha3-512            Use the sha3-512 algorithm",
    "    Any other argument is a LIKE pattern for tables to hash",
    ".shell CMD ARGS...       Run CMD ARGS... in a system shell",
    ".show                    Show the current values for various settings",
    ".stats ?ARG?             Show stats or turn stats on or off",
    "   off                      Turn off automatic stat display",
    "   on                       Turn on automatic stat display",
    "   stmt                     Show statement stats",
    "   vmstep                   Show the virtual machine step count only",
    ".system CMD ARGS...      Run CMD ARGS... in a system shell",
    ".tables ?TABLE?          List names of tables matching LIKE pattern TABLE",
    ",testcase NAME           Begin redirecting output to 'testcase-out.txt'",
    ",testctrl CMD ...        Run various sqlite3_test_control() operations",
    "                           Run \".testctrl\" with no arguments for "
    "details",
    ".timeout MS              Try opening locked tables for MS milliseconds",
    ".timer on|off            Turn SQL timer on or off",
    ".trace ?OPTIONS?         Output each SQL statement as it is run",
    "    FILE                    Send output to FILE",
    "    stdout                  Send output to stdout",
    "    stderr                  Send output to stderr",
    "    off                     Disable tracing",
    "    --expanded              Expand query parameters",
    "    --plain                 Show SQL as it is input",
    "    --stmt                  Trace statement execution (SQLITE_TRACE_STMT)",
    "    --profile               Profile statements (SQLITE_TRACE_PROFILE)",
    "    --row                   Trace each row (SQLITE_TRACE_ROW)",
    "    --close                 Trace connection close (SQLITE_TRACE_CLOSE)",
    ".version                 Show source, library and compiler versions",
    ".vfsinfo ?AUX?           Information about the top-level VFS",
    ".vfslist                 List all available VFSes",
    ".vfsname ?AUX?           Print the name of the VFS stack",
    ".width NUM1 NUM2 ...     Set minimum column widths for columnar output",
    "     Negative values right-justify"};
static int showHelp(FILE *out, const char *zPattern) {
  int i = 0;
  int j = 0;
  int n = 0;
  char *zPat;
  if (zPattern == 0 || zPattern[0] == '0' || cli_strcmp(zPattern, "-a") == 0 ||
      cli_strcmp(zPattern, "-all") == 0 || cli_strcmp(zPattern, "--all") == 0) {
    enum HelpWanted { HW_NoCull = 0, HW_SummaryOnly = 1, HW_Undoc = 2 };
    enum HelpHave { HH_Undoc = 2, HH_Summary = 1, HH_More = 0 };
    enum HelpWanted hw = HW_SummaryOnly;
    enum HelpHave hh = HH_More;
    if (zPattern != 0) {
      hw = (*zPattern == '0') ? HW_NoCull | HW_Undoc : HW_NoCull;
    }
    for (i = 0; i < (int)(sizeof(azHelp) / sizeof(azHelp[0])); i++) {
      switch (azHelp[i][0]) {
      case ',':
        hh = HH_Summary | HH_Undoc;
        break;
      case '.':
        hh = HH_Summary;
        break;
      default:
        hh &= ~HH_Summary;
        break;
      }
      if (((hw ^ hh) & HH_Undoc) == 0) {
        if ((hh & HH_Summary) != 0) {
          fprintf(out, ".%s\n", azHelp[i] + 1);
          ++n;
        } else if ((hw & HW_SummaryOnly) == 0) {
          fprintf(out, "%s\n", azHelp[i]);
        }
      }
    }
  } else {
    zPat = sqlite3_mprintf(".%s*", zPattern);
    shell_check_oom(zPat);
    for (i = 0; i < (int)(sizeof(azHelp) / sizeof(azHelp[0])); i++) {
      if (sqlite3_strglob(zPat, azHelp[i]) == 0) {
        fprintf(out, "%s\n", azHelp[i]);
        j = i + 1;
        n++;
      }
    }
    sqlite3_free(zPat);
    if (n) {
      if (n == 1) {
        while (j < (int)(sizeof(azHelp) / sizeof(azHelp[0])) - 1 &&
               azHelp[j][0] == ' ') {
          fprintf(out, "%s\n", azHelp[j]);
          j++;
        }
      }
      return n;
    }
    zPat = sqlite3_mprintf("%%%s%%", zPattern);
    shell_check_oom(zPat);
    for (i = 0; i < (int)(sizeof(azHelp) / sizeof(azHelp[0])); i++) {
      if (azHelp[i][0] == ',') {
        while (i < (int)(sizeof(azHelp) / sizeof(azHelp[0])) - 1 &&
               azHelp[i + 1][0] == ' ')
          ++i;
        continue;
      }
      if (azHelp[i][0] == '.')
        j = i;
      if (sqlite3_strlike(zPat, azHelp[i], 0) == 0) {
        fprintf(out, "%s\n", azHelp[j]);
        while (j < (int)(sizeof(azHelp) / sizeof(azHelp[0])) - 1 &&
               azHelp[j + 1][0] == ' ') {
          j++;
          fprintf(out, "%s\n", azHelp[j]);
        }
        i = j;
        n++;
      }
    }
    sqlite3_free(zPat);
  }
  return n;
}
static int process_input(ShellState *p);
static char *readFile(const char *zName, int *pnByte) {
  FILE *in = fopen(zName, "rb");
  long nIn;
  size_t nRead;
  char *pBuf;
  int rc;
  if (in == 0)
    return 0;
  rc = fseek(in, 0, 2);
  if (rc != 0) {
    fprintf(stderr, "Error: '%s' not seekable\n", zName);
    fclose(in);
    return 0;
  }
  nIn = ftell(in);
  rewind(in);
  pBuf = sqlite3_malloc64(nIn + 1);
  if (pBuf == 0) {
    fprintf(stderr, "Error: out of memory\n");
    fclose(in);
    return 0;
  }
  nRead = fread(pBuf, nIn, 1, in);
  fclose(in);
  if (nRead != 1) {
    sqlite3_free(pBuf);
    fprintf(stderr, "Error: cannot read '%s'\n", zName);
    return 0;
  }
  pBuf[nIn] = 0;
  if (pnByte)
    *pnByte = nIn;
  return pBuf;
}
int deduceDatabaseType(const char *zName, int dfltZip) {
  FILE *f = fopen(zName, "rb");
  size_t n;
  int rc = 0;
  char zBuf[100];
  if (f == 0) {
    if (dfltZip && sqlite3_strlike("%.zip", zName, 0) == 0) {
      return 3;
    } else {
      return 1;
    }
  }
  n = fread(zBuf, 16, 1, f);
  if (n == 1 && memcmp(zBuf, "SQLite format 3", 16) == 0) {
    fclose(f);
    return 1;
  }
  fseek(f, -25, 2);
  n = fread(zBuf, 25, 1, f);
  if (n == 1 && memcmp(zBuf, "Start-Of-SQLite3-", 17) == 0) {
    rc = 2;
  } else {
    fseek(f, -22, 2);
    n = fread(zBuf, 22, 1, f);
    if (n == 1 && zBuf[0] == 80 && zBuf[1] == 75 && zBuf[2] == 5 &&
        zBuf[3] == 6) {
      rc = 3;
    } else if (n == 0 && dfltZip && sqlite3_strlike("%.zip", zName, 0) == 0) {
      rc = 3;
    }
  }
  fclose(f);
  return rc;
}
static unsigned char *readHexDb(ShellState *p, int *pnData) {
  unsigned char *a = 0;
  int nLine;
  int n = 0;
  int pgsz = 0;
  int iOffset = 0;
  int j, k;
  int rc;
  FILE *in;
  const char *zDbFilename = p->pAuxDb->zDbFilename;
  unsigned int x[16];
  char zLine[1000];
  if (zDbFilename) {
    in = fopen(zDbFilename, "r");
    if (in == 0) {
      fprintf(stderr, "cannot open \"%s\" for reading\n", zDbFilename);
      return 0;
    }
    nLine = 0;
  } else {
    in = p->in;
    nLine = p->lineno;
    if (in == 0)
      in = stdin;
  }
  *pnData = 0;
  nLine++;
  if (fgets(zLine, sizeof(zLine), in) == 0)
    goto readHexDb_error;
  rc = sscanf(zLine, "| size %d pagesize %d", &n, &pgsz);
  if (rc != 2)
    goto readHexDb_error;
  if (n < 0)
    goto readHexDb_error;
  if (pgsz < 512 || pgsz > 65536 || (pgsz & (pgsz - 1)) != 0)
    goto readHexDb_error;
  n = (n + pgsz - 1) & ~(pgsz - 1);
  a = sqlite3_malloc(n ? n : 1);
  shell_check_oom(a);
  memset(a, 0, n);
  if (pgsz < 512 || pgsz > 65536 || (pgsz & (pgsz - 1)) != 0) {
    fprintf(stderr, "invalid pagesize\n");
    goto readHexDb_error;
  }
  for (nLine++; fgets(zLine, sizeof(zLine), in) != 0; nLine++) {
    rc = sscanf(zLine, "| page %d offset %d", &j, &k);
    if (rc == 2) {
      iOffset = k;
      continue;
    }
    if (cli_strncmp(zLine, "| end ", 6) == 0) {
      break;
    }
    rc = sscanf(zLine, "| %d: %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x",
                &j, &x[0], &x[1], &x[2], &x[3], &x[4], &x[5], &x[6], &x[7],
                &x[8], &x[9], &x[10], &x[11], &x[12], &x[13], &x[14], &x[15]);
    if (rc == 17) {
      k = iOffset + j;
      if (k + 16 <= n && k >= 0) {
        int ii;
        for (ii = 0; ii < 16; ii++)
          a[k + ii] = x[ii] & 255;
      }
    }
  }
  *pnData = n;
  if (in != p->in) {
    fclose(in);
  } else {
    p->lineno = nLine;
  }
  return a;
readHexDb_error:
  if (in != p->in) {
    fclose(in);
  } else {
    while (fgets(zLine, sizeof(zLine), p->in) != 0) {
      nLine++;
      if (cli_strncmp(zLine, "| end ", 6) == 0)
        break;
    }
    p->lineno = nLine;
  }
  sqlite3_free(a);
  fprintf(stderr, "Error on line %d of --hexdb input\n", nLine);
  return 0;
}
static void shellUSleepFunc(sqlite3_context *context, int argcUnused,
                            sqlite3_value **argv) {
  int sleep = sqlite3_value_int(argv[0]);
  (void)argcUnused;
  sqlite3_sleep(sleep / 1000);
  sqlite3_result_int(context, sleep);
}
static void open_db(ShellState *p, int openFlags) {
  if (p->db == 0) {
    const char *zDbFilename = p->pAuxDb->zDbFilename;
    if (p->openMode == 0) {
      if (zDbFilename == 0 || zDbFilename[0] == 0) {
        p->openMode = 1;
      } else {
        p->openMode = (u8)deduceDatabaseType(zDbFilename, (openFlags & 2) != 0);
      }
    }
    switch (p->openMode) {
    case 2: {
      sqlite3_open_v2(zDbFilename, &p->db, 2 | 4 | p->openFlags, "apndvfs");
      break;
    }
    case 6:
    case 5: {
      sqlite3_open(0, &p->db);
      break;
    }
    case 3: {
      sqlite3_open(":memory:", &p->db);
      break;
    }
    case 4: {
      sqlite3_open_v2(zDbFilename, &p->db, 1 | p->openFlags, 0);
      break;
    }
    case 0:
    case 1: {
      sqlite3_open_v2(zDbFilename, &p->db, 2 | 4 | p->openFlags, 0);
      break;
    }
    }
    globalDb = p->db;
    if (p->db == 0 || 0 != sqlite3_errcode(p->db)) {
      fprintf(stderr, "Error: unable to open database \"%s\": %s\n",
              zDbFilename, sqlite3_errmsg(p->db));
      if ((openFlags & 1) == 0) {
        exit(1);
      }
      sqlite3_close(p->db);
      sqlite3_open(":memory:", &p->db);
      if (p->db == 0 || 0 != sqlite3_errcode(p->db)) {
        fprintf(stderr,
                "Also: unable to open substitute in-memory database.\n");
        exit(1);
      } else {
        fprintf(
            stderr,
            "Notice: using substitute in-memory database instead of \"%s\"\n",
            zDbFilename);
      }
    }
    sqlite3_db_config(p->db, 1018, (int)0, (int *)0);
    {
      int testmode_on = (((p)->shellFlgs & (1024)) != 0);
      sqlite3_db_config(p->db, 1017, testmode_on, 0);
      sqlite3_db_config(p->db, 1010, !testmode_on, 0);
    }
    sqlite3_enable_load_extension(p->db, 1);
    sqlite3_shathree_init(p->db, 0, 0);
    sqlite3_uint_init(p->db, 0, 0);
    sqlite3_decimal_init(p->db, 0, 0);
    sqlite3_base64_init(p->db, 0, 0);
    sqlite3_base85_init(p->db, 0, 0);
    sqlite3_regexp_init(p->db, 0, 0);
    sqlite3_ieee_init(p->db, 0, 0);
    sqlite3_series_init(p->db, 0, 0);
    sqlite3_fileio_init(p->db, 0, 0);
    sqlite3_completion_init(p->db, 0, 0);
    sqlite3_create_function(p->db, "shell_add_schema", 3, 1, 0,
                            shellAddSchemaName, 0, 0);
    sqlite3_create_function(p->db, "shell_module_schema", 1, 1, 0,
                            shellModuleSchema, 0, 0);
    sqlite3_create_function(p->db, "shell_putsnl", 1, 1, p, shellPutsFunc, 0,
                            0);
    sqlite3_create_function(p->db, "usleep", 1, 1, 0, shellUSleepFunc, 0, 0);
    sqlite3_create_function(p->db, "edit", 1, 1, 0, editFunc, 0, 0);
    sqlite3_create_function(p->db, "edit", 2, 1, 0, editFunc, 0, 0);
    if (p->openMode == 3) {
      char *zSql = sqlite3_mprintf(
          "CREATE VIRTUAL TABLE zip USING zipfile(%Q);", zDbFilename);
      shell_check_oom(zSql);
      sqlite3_exec(p->db, zSql, 0, 0, 0);
      sqlite3_free(zSql);
    } else if (p->openMode == 5 || p->openMode == 6) {
      int rc;
      int nData = 0;
      unsigned char *aData;
      if (p->openMode == 5) {
        aData = (unsigned char *)readFile(zDbFilename, &nData);
      } else {
        aData = readHexDb(p, &nData);
      }
      if (aData == 0) {
        return;
      }
      rc = sqlite3_deserialize(p->db, "main", aData, nData, nData, 2 | 1);
      if (rc) {
        fprintf(stderr, "Error: sqlite3_deserialize() returns %d\n", rc);
      }
      if (p->szMax > 0) {
        sqlite3_file_control(p->db, "main", 36, &p->szMax);
      }
    }
  }
  if (p->db != 0) {
    if (p->bSafeModePersist) {
      sqlite3_set_authorizer(p->db, safeModeAuth, p);
    }
    sqlite3_db_config(p->db, 1018, p->scanstatsOn, (int *)0);
  }
}
void close_db(sqlite3 *db) {
  int rc = sqlite3_close(db);
  if (rc) {
    fprintf(stderr, "Error: sqlite3_close() returns %d: %s\n", rc,
            sqlite3_errmsg(db));
  }
}
static void resolve_backslashes(char *z) {
  int i, j;
  char c;
  while (*z && *z != '\\')
    z++;
  for (i = j = 0; (c = z[i]) != 0; i++, j++) {
    if (c == '\\' && z[i + 1] != 0) {
      c = z[++i];
      if (c == 'a') {
        c = 'A';
      } else if (c == 'b') {
        c = 'A';
      } else if (c == 't') {
        c = '\t';
      } else if (c == 'n') {
        c = '\n';
      } else if (c == 'v') {
        c = 'A';
      } else if (c == 'f') {
        c = 'A';
      } else if (c == 'r') {
        c = '\x0d';
      } else if (c == '\"') {
        c = '\"';
      } else if (c == '\'') {
        c = '\'';
      } else if (c == '\\') {
        c = '\\';
      } else if (c == 'x') {
        int nhd = 0, hdv;
        u8 hv = 0;
        while (nhd < 2 && (c = z[i + 1 + nhd]) != 0 &&
               (hdv = hexDigitValue(c)) >= 0) {
          hv = (u8)((hv << 4) | hdv);
          ++nhd;
        }
        i += nhd;
        c = (u8)hv;
      } else if (c >= '0' && c <= '7') {
        c -= '0';
        if (z[i + 1] >= '0' && z[i + 1] <= '7') {
          i++;
          c = (c << 3) + z[i] - '0';
          if (z[i + 1] >= '0' && z[i + 1] <= '7') {
            i++;
            c = (c << 3) + z[i] - '0';
          }
        }
      }
    }
    z[j] = c;
  }
  if (j < i)
    z[j] = 0;
}
static int booleanValue(const char *zArg) {
  int i;
  if (zArg[0] == '0' && zArg[1] == 'x') {
    for (i = 2; hexDigitValue(zArg[i]) >= 0; i++) {
    }
  } else {
    for (i = 0; zArg[i] >= '0' && zArg[i] <= '9'; i++) {
    }
  }
  if (i > 0 && zArg[i] == 0)
    return (int)(integerValue(zArg) & 4294967295);
  if (sqlite3_stricmp(zArg, "on") == 0 || sqlite3_stricmp(zArg, "yes") == 0) {
    return 1;
  }
  if (sqlite3_stricmp(zArg, "off") == 0 || sqlite3_stricmp(zArg, "no") == 0) {
    return 0;
  }
  fprintf(stderr, "ERROR: Not a boolean value: \"%s\". Assuming \"no\".\n",
          zArg);
  return 0;
}
static void setOrClearFlag(ShellState *p, unsigned mFlag, const char *zArg) {
  if (booleanValue(zArg)) {
    ((p)->shellFlgs |= (mFlag));
  } else {
    ((p)->shellFlgs &= (~(mFlag)));
  }
}
static void output_file_close(FILE *f) {
  if (f && f != stdout && f != stderr)
    fclose(f);
}
static FILE *output_file_open(const char *zFile, int bTextMode) {
  FILE *f;
  if (cli_strcmp(zFile, "stdout") == 0) {
    f = stdout;
  } else if (cli_strcmp(zFile, "stderr") == 0) {
    f = stderr;
  } else if (cli_strcmp(zFile, "off") == 0) {
    f = 0;
  } else {
    f = fopen(zFile, bTextMode ? "w" : "wb");
    if (f == 0) {
      fprintf(stderr, "Error: cannot open \"%s\"\n", zFile);
    }
  }
  return f;
}
static int sql_trace_callback(unsigned mType, void *pArg, void *pP, void *pX) {
  ShellState *p = (ShellState *)pArg;
  sqlite3_stmt *pStmt;
  const char *zSql;
  i64 nSql;
  if (p->traceOut == 0)
    return 0;
  if (mType == 8) {
    fprintf(p->traceOut, "-- closing database connection\n");
    return 0;
  }
  if (mType != 4 && pX != 0 && ((const char *)pX)[0] == '-') {
    zSql = (const char *)pX;
  } else {
    pStmt = (sqlite3_stmt *)pP;
    switch (p->eTraceType) {
    case 1: {
      zSql = sqlite3_expanded_sql(pStmt);
      break;
    }
    default: {
      zSql = sqlite3_sql(pStmt);
      break;
    }
    }
  }
  if (zSql == 0)
    return 0;
  nSql = strlen(zSql);
  if (nSql > 1000000000)
    nSql = 1000000000;
  while (nSql > 0 && zSql[nSql - 1] == ';') {
    nSql--;
  }
  switch (mType) {
  case 4:
  case 1: {
    fprintf(p->traceOut, "%.*s;\n", (int)nSql, zSql);
    break;
  }
  case 2: {
    sqlite3_int64 nNanosec = pX ? *(sqlite3_int64 *)pX : 0;
    fprintf(p->traceOut, "%.*s; -- %lld ns\n", (int)nSql, zSql, nNanosec);
    break;
  }
  }
  return 0;
}
static void test_breakpoint(void) {
  static unsigned int nCall = 0;
  if ((nCall++) == 4294967295)
    printf("Many .breakpoints have run\n");
}
typedef struct ImportCtx ImportCtx;
struct ImportCtx {
  const char *zFile;
  FILE *in;
  int (*xCloser)(FILE *);
  char *z;
  int n;
  int nAlloc;
  int nLine;
  int nRow;
  int nErr;
  int bNotFirst;
  int cTerm;
  int cColSep;
  int cRowSep;
};
static void import_cleanup(ImportCtx *p) {
  if (p->in != 0 && p->xCloser != 0) {
    p->xCloser(p->in);
    p->in = 0;
  }
  sqlite3_free(p->z);
  p->z = 0;
}
static void import_append_char(ImportCtx *p, int c) {
  if (p->n + 1 >= p->nAlloc) {
    p->nAlloc += p->nAlloc + 100;
    p->z = sqlite3_realloc64(p->z, p->nAlloc);
    shell_check_oom(p->z);
  }
  p->z[p->n++] = (char)c;
}
static char *csv_read_one_field(ImportCtx *p) {
  int c;
  int cSep = (u8)p->cColSep;
  int rSep = (u8)p->cRowSep;
  p->n = 0;
  c = fgetc(p->in);
  if (c == (-1) || seenInterrupt) {
    p->cTerm = (-1);
    return 0;
  }
  if (c == '\"') {
    int pc, ppc;
    int startLine = p->nLine;
    int cQuote = c;
    pc = ppc = 0;
    while (1) {
      c = fgetc(p->in);
      if (c == rSep)
        p->nLine++;
      if (c == cQuote) {
        if (pc == cQuote) {
          pc = 0;
          continue;
        }
      }
      if ((c == cSep && pc == cQuote) || (c == rSep && pc == cQuote) ||
          (c == rSep && pc == '\x0d' && ppc == cQuote) ||
          (c == (-1) && pc == cQuote)) {
        do {
          p->n--;
        } while (p->z[p->n] != cQuote);
        p->cTerm = c;
        break;
      }
      if (pc == cQuote && c != '\x0d') {
        fprintf(stderr, "%s:%d: unescaped %c character\n", p->zFile, p->nLine,
                cQuote);
      }
      if (c == (-1)) {
        fprintf(stderr, "%s:%d: unterminated %c-quoted field\n", p->zFile,
                startLine, cQuote);
        p->cTerm = c;
        break;
      }
      import_append_char(p, c);
      ppc = pc;
      pc = c;
    }
  } else {
    if ((c & 255) == 239 && p->bNotFirst == 0) {
      import_append_char(p, c);
      c = fgetc(p->in);
      if ((c & 255) == 187) {
        import_append_char(p, c);
        c = fgetc(p->in);
        if ((c & 255) == 191) {
          p->bNotFirst = 1;
          p->n = 0;
          return csv_read_one_field(p);
        }
      }
    }
    while (c != (-1) && c != cSep && c != rSep) {
      import_append_char(p, c);
      c = fgetc(p->in);
    }
    if (c == rSep) {
      p->nLine++;
      if (p->n > 0 && p->z[p->n - 1] == '\x0d')
        p->n--;
    }
    p->cTerm = c;
  }
  if (p->z)
    p->z[p->n] = 0;
  p->bNotFirst = 1;
  return p->z;
}
static char *ascii_read_one_field(ImportCtx *p) {
  int c;
  int cSep = (u8)p->cColSep;
  int rSep = (u8)p->cRowSep;
  p->n = 0;
  c = fgetc(p->in);
  if (c == (-1) || seenInterrupt) {
    p->cTerm = (-1);
    return 0;
  }
  while (c != (-1) && c != cSep && c != rSep) {
    import_append_char(p, c);
    c = fgetc(p->in);
  }
  if (c == rSep) {
    p->nLine++;
  }
  p->cTerm = c;
  if (p->z)
    p->z[p->n] = 0;
  return p->z;
}
static void tryToCloneData(ShellState *p, sqlite3 *newDb, const char *zTable) {
  sqlite3_stmt *pQuery = 0;
  sqlite3_stmt *pInsert = 0;
  char *zQuery = 0;
  char *zInsert = 0;
  int rc;
  int i, j, n;
  int nTable = strlen30(zTable);
  int k = 0;
  int cnt = 0;
  const int spinRate = 10000;
  zQuery = sqlite3_mprintf("SELECT * FROM \"%w\"", zTable);
  shell_check_oom(zQuery);
  rc = sqlite3_prepare_v2(p->db, zQuery, -1, &pQuery, 0);
  if (rc) {
    fprintf(stderr, "Error %d: %s on [%s]\n", sqlite3_extended_errcode(p->db),
            sqlite3_errmsg(p->db), zQuery);
    goto end_data_xfer;
  }
  n = sqlite3_column_count(pQuery);
  zInsert = sqlite3_malloc64(200 + nTable + n * 3);
  shell_check_oom(zInsert);
  sqlite3_snprintf(200 + nTable, zInsert,
                   "INSERT OR IGNORE INTO \"%s\" VALUES(?", zTable);
  i = strlen30(zInsert);
  for (j = 1; j < n; j++) {
    memcpy(zInsert + i, ",?", 2);
    i += 2;
  }
  memcpy(zInsert + i, ");", 3);
  rc = sqlite3_prepare_v2(newDb, zInsert, -1, &pInsert, 0);
  if (rc) {
    fprintf(stderr, "Error %d: %s on [%s]\n", sqlite3_extended_errcode(newDb),
            sqlite3_errmsg(newDb), zQuery);
    goto end_data_xfer;
  }
  for (k = 0; k < 2; k++) {
    while ((rc = sqlite3_step(pQuery)) == 100) {
      for (i = 0; i < n; i++) {
        switch (sqlite3_column_type(pQuery, i)) {
        case 5: {
          sqlite3_bind_null(pInsert, i + 1);
          break;
        }
        case 1: {
          sqlite3_bind_int64(pInsert, i + 1, sqlite3_column_int64(pQuery, i));
          break;
        }
        case 2: {
          sqlite3_bind_double(pInsert, i + 1, sqlite3_column_double(pQuery, i));
          break;
        }
        case 3: {
          sqlite3_bind_text(pInsert, i + 1,
                            (const char *)sqlite3_column_text(pQuery, i), -1,
                            ((sqlite3_destructor_type)0));
          break;
        }
        case 4: {
          sqlite3_bind_blob(pInsert, i + 1, sqlite3_column_blob(pQuery, i),
                            sqlite3_column_bytes(pQuery, i),
                            ((sqlite3_destructor_type)0));
          break;
        }
        }
      }
      rc = sqlite3_step(pInsert);
      if (rc != 0 && rc != 100 && rc != 101) {
        fprintf(stderr, "Error %d: %s\n", sqlite3_extended_errcode(newDb),
                sqlite3_errmsg(newDb));
      }
      sqlite3_reset(pInsert);
      cnt++;
      if ((cnt % spinRate) == 0) {
        printf("", "|/-\\"[(cnt / spinRate) % 4]);
        fflush(stdout);
      }
    }
    if (rc == 101)
      break;
    sqlite3_finalize(pQuery);
    sqlite3_free(zQuery);
    zQuery =
        sqlite3_mprintf("SELECT * FROM \"%w\" ORDER BY rowid DESC;", zTable);
    shell_check_oom(zQuery);
    rc = sqlite3_prepare_v2(p->db, zQuery, -1, &pQuery, 0);
    if (rc) {
      fprintf(stderr, "Warning: cannot step \"%s\" backwards", zTable);
      break;
    }
  }
end_data_xfer:
  sqlite3_finalize(pQuery);
  sqlite3_finalize(pInsert);
  sqlite3_free(zQuery);
  sqlite3_free(zInsert);
}
static void tryToCloneSchema(ShellState *p, sqlite3 *newDb, const char *zWhere,
                             void (*xForEach)(ShellState *, sqlite3 *,
                                              const char *)) {
  sqlite3_stmt *pQuery = 0;
  char *zQuery = 0;
  int rc;
  const unsigned char *zName;
  const unsigned char *zSql;
  char *zErrMsg = 0;
  zQuery = sqlite3_mprintf(
      "SELECT name, sql FROM sqlite_schema WHERE %s ORDER BY rowid ASC",
      zWhere);
  shell_check_oom(zQuery);
  rc = sqlite3_prepare_v2(p->db, zQuery, -1, &pQuery, 0);
  if (rc) {
    fprintf(stderr, "Error: (%d) %s on [%s]\n", sqlite3_extended_errcode(p->db),
            sqlite3_errmsg(p->db), zQuery);
    goto end_schema_xfer;
  }
  while ((rc = sqlite3_step(pQuery)) == 100) {
    zName = sqlite3_column_text(pQuery, 0);
    zSql = sqlite3_column_text(pQuery, 1);
    if (zName == 0 || zSql == 0)
      continue;
    if (sqlite3_stricmp((char *)zName, "sqlite_sequence") != 0) {
      printf("%s... ", zName);
      fflush(stdout);
      sqlite3_exec(newDb, (const char *)zSql, 0, 0, &zErrMsg);
      if (zErrMsg) {
        fprintf(stderr, "Error: %s\nSQL: [%s]\n", zErrMsg, zSql);
        sqlite3_free(zErrMsg);
        zErrMsg = 0;
      }
    }
    if (xForEach) {
      xForEach(p, newDb, (const char *)zName);
    }
    printf("done\n");
  }
  if (rc != 101) {
    sqlite3_finalize(pQuery);
    sqlite3_free(zQuery);
    zQuery = sqlite3_mprintf(
        "SELECT name, sql FROM sqlite_schema WHERE %s ORDER BY rowid DESC",
        zWhere);
    shell_check_oom(zQuery);
    rc = sqlite3_prepare_v2(p->db, zQuery, -1, &pQuery, 0);
    if (rc) {
      fprintf(stderr, "Error: (%d) %s on [%s]\n",
              sqlite3_extended_errcode(p->db), sqlite3_errmsg(p->db), zQuery);
      goto end_schema_xfer;
    }
    while (sqlite3_step(pQuery) == 100) {
      zName = sqlite3_column_text(pQuery, 0);
      zSql = sqlite3_column_text(pQuery, 1);
      if (zName == 0 || zSql == 0)
        continue;
      if (sqlite3_stricmp((char *)zName, "sqlite_sequence") == 0)
        continue;
      printf("%s... ", zName);
      fflush(stdout);
      sqlite3_exec(newDb, (const char *)zSql, 0, 0, &zErrMsg);
      if (zErrMsg) {
        fprintf(stderr, "Error: %s\nSQL: [%s]\n", zErrMsg, zSql);
        sqlite3_free(zErrMsg);
        zErrMsg = 0;
      }
      if (xForEach) {
        xForEach(p, newDb, (const char *)zName);
      }
      printf("done\n");
    }
  }
end_schema_xfer:
  sqlite3_finalize(pQuery);
  sqlite3_free(zQuery);
}
static void tryToClone(ShellState *p, const char *zNewDb) {
  int rc;
  sqlite3 *newDb = 0;
  if (access(zNewDb, 0) == 0) {
    fprintf(stderr, "File \"%s\" already exists.\n", zNewDb);
    return;
  }
  rc = sqlite3_open(zNewDb, &newDb);
  if (rc) {
    fprintf(stderr, "Cannot create output database: %s\n",
            sqlite3_errmsg(newDb));
  } else {
    sqlite3_exec(p->db, "PRAGMA writable_schema=ON;", 0, 0, 0);
    sqlite3_exec(newDb, "BEGIN EXCLUSIVE;", 0, 0, 0);
    tryToCloneSchema(p, newDb, "type='table'", tryToCloneData);
    tryToCloneSchema(p, newDb, "type!='table'", 0);
    sqlite3_exec(newDb, "COMMIT;", 0, 0, 0);
    sqlite3_exec(p->db, "PRAGMA writable_schema=OFF;", 0, 0, 0);
  }
  close_db(newDb);
}
static void output_reset(ShellState *p) {
  if (p->outfile[0] == '|') {
    pclose(p->out);
  } else {
    output_file_close(p->out);
    if (p->doXdgOpen) {
      const char *zXdgOpenCmd = "xdg-open";
      char *zCmd;
      zCmd = sqlite3_mprintf("%s %s", zXdgOpenCmd, p->zTempFile);
      if (system(zCmd)) {
        fprintf(stderr, "Failed: [%s]\n", zCmd);
      } else {
        sqlite3_sleep(2000);
      }
      sqlite3_free(zCmd);
      outputModePop(p);
      p->doXdgOpen = 0;
    }
  }
  p->outfile[0] = 0;
  p->out = stdout;
}
static int db_int(sqlite3 *db, const char *zSql) {
  sqlite3_stmt *pStmt;
  int res = 0;
  sqlite3_prepare_v2(db, zSql, -1, &pStmt, 0);
  if (pStmt && sqlite3_step(pStmt) == 100) {
    res = sqlite3_column_int(pStmt, 0);
  }
  sqlite3_finalize(pStmt);
  return res;
}
static int shellDatabaseError(sqlite3 *db) {
  const char *zErr = sqlite3_errmsg(db);
  fprintf(stderr, "Error: %s\n", zErr);
  return 1;
}
static int testcase_glob(const char *zGlob, const char *z) {
  int c, c2;
  int invert;
  int seen;
  while ((c = (*(zGlob++))) != 0) {
    if (((*__ctype_b_loc())[(int)(((unsigned char)c))] &
         (unsigned short int)_ISspace)) {
      if (!((*__ctype_b_loc())[(int)(((unsigned char)*z))] &
            (unsigned short int)_ISspace))
        return 0;
      while (((*__ctype_b_loc())[(int)(((unsigned char)*zGlob))] &
              (unsigned short int)_ISspace))
        zGlob++;
      while (((*__ctype_b_loc())[(int)(((unsigned char)*z))] &
              (unsigned short int)_ISspace))
        z++;
    } else if (c == '*') {
      while ((c = (*(zGlob++))) == '*' || c == '?') {
        if (c == '?' && (*(z++)) == 0)
          return 0;
      }
      if (c == 0) {
        return 1;
      } else if (c == '[') {
        while (*z && testcase_glob(zGlob - 1, z) == 0) {
          z++;
        }
        return (*z) != 0;
      }
      while ((c2 = (*(z++))) != 0) {
        while (c2 != c) {
          c2 = *(z++);
          if (c2 == 0)
            return 0;
        }
        if (testcase_glob(zGlob, z))
          return 1;
      }
      return 0;
    } else if (c == '?') {
      if ((*(z++)) == 0)
        return 0;
    } else if (c == '[') {
      int prior_c = 0;
      seen = 0;
      invert = 0;
      c = *(z++);
      if (c == 0)
        return 0;
      c2 = *(zGlob++);
      if (c2 == '^') {
        invert = 1;
        c2 = *(zGlob++);
      }
      if (c2 == ']') {
        if (c == ']')
          seen = 1;
        c2 = *(zGlob++);
      }
      while (c2 && c2 != ']') {
        if (c2 == '-' && zGlob[0] != ']' && zGlob[0] != 0 && prior_c > 0) {
          c2 = *(zGlob++);
          if (c >= prior_c && c <= c2)
            seen = 1;
          prior_c = 0;
        } else {
          if (c == c2) {
            seen = 1;
          }
          prior_c = c2;
        }
        c2 = *(zGlob++);
      }
      if (c2 == 0 || (seen ^ invert) == 0)
        return 0;
      if ((z[0] == '-' || z[0] == '+') &&
          ((*__ctype_b_loc())[(int)(((unsigned char)z[1]))] &
           (unsigned short int)_ISdigit))
        z++;
      if (!((*__ctype_b_loc())[(int)(((unsigned char)z[0]))] &
            (unsigned short int)_ISdigit))
        return 0;
      z++;
      while (((*__ctype_b_loc())[(int)(((unsigned char)z[0]))] &
              (unsigned short int)_ISdigit)) {
        z++;
      }
    } else {
      if (c != (*(z++)))
        return 0;
    }
  }
  while (((*__ctype_b_loc())[(int)(((unsigned char)*z))] &
          (unsigned short int)_ISspace)) {
    z++;
  }
  return *z == 0;
}
static int optionMatch(const char *zStr, const char *zOpt) {
  if (zStr[0] != '-')
    return 0;
  zStr++;
  if (zStr[0] == '-')
    zStr++;
  return cli_strcmp(zStr, zOpt) == 0;
}
int shellDeleteFile(const char *zFilename) {
  int rc;
  rc = unlink(zFilename);
  return rc;
}
static void clearTempFile(ShellState *p) {
  if (p->zTempFile == 0)
    return;
  if (p->doXdgOpen)
    return;
  if (shellDeleteFile(p->zTempFile))
    return;
  sqlite3_free(p->zTempFile);
  p->zTempFile = 0;
}
static void newTempFile(ShellState *p, const char *zSuffix) {
  clearTempFile(p);
  sqlite3_free(p->zTempFile);
  p->zTempFile = 0;
  if (p->db) {
    sqlite3_file_control(p->db, 0, 16, &p->zTempFile);
  }
  if (p->zTempFile == 0) {
    char *zTemp;
    sqlite3_uint64 r;
    sqlite3_randomness(sizeof(r), &r);
    zTemp = getenv("TEMP");
    if (zTemp == 0)
      zTemp = getenv("TMP");
    if (zTemp == 0) {
      zTemp = "/tmp";
    }
    p->zTempFile = sqlite3_mprintf("%s/temp%llx.%s", zTemp, r, zSuffix);
  } else {
    p->zTempFile = sqlite3_mprintf("%z.%s", p->zTempFile, zSuffix);
  }
  shell_check_oom(p->zTempFile);
}
static void shellFkeyCollateClause(sqlite3_context *pCtx, int nVal,
                                   sqlite3_value **apVal) {
  sqlite3 *db = sqlite3_context_db_handle(pCtx);
  const char *zParent;
  const char *zParentCol;
  const char *zParentSeq;
  const char *zChild;
  const char *zChildCol;
  const char *zChildSeq = 0;
  int rc;
  ((void)sizeof((nVal == 4) ? 1 : 0), ({
     if (nVal == 4)
       ;
     else
       __assert_fail("nVal==4", "shell.c", 21892, __PRETTY_FUNCTION__);
   }));
  zParent = (const char *)sqlite3_value_text(apVal[0]);
  zParentCol = (const char *)sqlite3_value_text(apVal[1]);
  zChild = (const char *)sqlite3_value_text(apVal[2]);
  zChildCol = (const char *)sqlite3_value_text(apVal[3]);
  sqlite3_result_text(pCtx, "", -1, ((sqlite3_destructor_type)0));
  rc = sqlite3_table_column_metadata(db, "main", zParent, zParentCol, 0,
                                     &zParentSeq, 0, 0, 0);
  if (rc == 0) {
    rc = sqlite3_table_column_metadata(db, "main", zChild, zChildCol, 0,
                                       &zChildSeq, 0, 0, 0);
  }
  if (rc == 0 && sqlite3_stricmp(zParentSeq, zChildSeq)) {
    char *z = sqlite3_mprintf(" COLLATE %s", zParentSeq);
    sqlite3_result_text(pCtx, z, -1, ((sqlite3_destructor_type)-1));
    sqlite3_free(z);
  }
}
static int lintFkeyIndexes(ShellState *pState, char **azArg, int nArg) {
  sqlite3 *db = pState->db;
  FILE *out = pState->out;
  int bVerbose = 0;
  int bGroupByParent = 0;
  int i;
  const char *zIndent = "";
  int rc;
  sqlite3_stmt *pSql = 0;
  const char *zSql =
      "SELECT      'EXPLAIN QUERY PLAN SELECT 1 FROM ' || quote(s.name) || ' "
      "WHERE '  || group_concat(quote(s.name) || '.' || quote(f.[from]) || "
      "'=?'   || fkey_collate_clause(       f.[table], COALESCE(f.[to], "
      "p.[name]), s.name, f.[from]),' AND '),      'SEARCH ' || s.name || ' "
      "USING COVERING INDEX*('  || group_concat('*=?', ' AND ') || ')',      "
      "s.name  || '(' || group_concat(f.[from],  ', ') || ')',      f.[table] "
      "|| '(' || group_concat(COALESCE(f.[to], p.[name])) || ')',      'CREATE "
      "INDEX ' || quote(s.name ||'_'|| group_concat(f.[from], '_'))  || ' ON ' "
      "|| quote(s.name) || '('  || group_concat(quote(f.[from]) ||        "
      "fkey_collate_clause(          f.[table], COALESCE(f.[to], p.[name]), "
      "s.name, f.[from]), ', ')  || ');',      f.[table] FROM sqlite_schema AS "
      "s, pragma_foreign_key_list(s.name) AS f LEFT JOIN pragma_table_info AS "
      "p ON (pk-1=seq AND p.arg=f.[table]) GROUP BY s.name, f.id ORDER BY "
      "(CASE WHEN ? THEN f.[table] ELSE s.name END)";
  const char *zGlobIPK = "SEARCH * USING INTEGER PRIMARY KEY (rowid=?)";
  for (i = 2; i < nArg; i++) {
    int n = strlen30(azArg[i]);
    if (n > 1 && sqlite3_strnicmp("-verbose", azArg[i], n) == 0) {
      bVerbose = 1;
    } else if (n > 1 && sqlite3_strnicmp("-groupbyparent", azArg[i], n) == 0) {
      bGroupByParent = 1;
      zIndent = "    ";
    } else {
      fprintf(stderr, "Usage: %s %s ?-verbose? ?-groupbyparent?\n", azArg[0],
              azArg[1]);
      return 1;
    }
  }
  rc = sqlite3_create_function(db, "fkey_collate_clause", 4, 1, 0,
                               shellFkeyCollateClause, 0, 0);
  if (rc == 0) {
    rc = sqlite3_prepare_v2(db, zSql, -1, &pSql, 0);
  }
  if (rc == 0) {
    sqlite3_bind_int(pSql, 1, bGroupByParent);
  }
  if (rc == 0) {
    int rc2;
    char *zPrev = 0;
    while (100 == sqlite3_step(pSql)) {
      int res = -1;
      sqlite3_stmt *pExplain = 0;
      const char *zEQP = (const char *)sqlite3_column_text(pSql, 0);
      const char *zGlob = (const char *)sqlite3_column_text(pSql, 1);
      const char *zFrom = (const char *)sqlite3_column_text(pSql, 2);
      const char *zTarget = (const char *)sqlite3_column_text(pSql, 3);
      const char *zCI = (const char *)sqlite3_column_text(pSql, 4);
      const char *zParent = (const char *)sqlite3_column_text(pSql, 5);
      if (zEQP == 0)
        continue;
      if (zGlob == 0)
        continue;
      rc = sqlite3_prepare_v2(db, zEQP, -1, &pExplain, 0);
      if (rc != 0)
        break;
      if (100 == sqlite3_step(pExplain)) {
        const char *zPlan = (const char *)sqlite3_column_text(pExplain, 3);
        res = zPlan != 0 && (0 == sqlite3_strglob(zGlob, zPlan) ||
                             0 == sqlite3_strglob(zGlobIPK, zPlan));
      }
      rc = sqlite3_finalize(pExplain);
      if (rc != 0)
        break;
      if (res < 0) {
        fprintf(stderr, "Error: internal error");
        break;
      } else {
        if (bGroupByParent && (bVerbose || res == 0) &&
            (zPrev == 0 || sqlite3_stricmp(zParent, zPrev))) {
          fprintf(out, "-- Parent table %s\n", zParent);
          sqlite3_free(zPrev);
          zPrev = sqlite3_mprintf("%s", zParent);
        }
        if (res == 0) {
          fprintf(out, "%s%s --> %s\n", zIndent, zCI, zTarget);
        } else if (bVerbose) {
          fprintf(out, "%s/* no extra indexes required for %s -> %s */\n",
                  zIndent, zFrom, zTarget);
        }
      }
    }
    sqlite3_free(zPrev);
    if (rc != 0) {
      fprintf(stderr, "%s\n", sqlite3_errmsg(db));
    }
    rc2 = sqlite3_finalize(pSql);
    if (rc == 0 && rc2 != 0) {
      rc = rc2;
      fprintf(stderr, "%s\n", sqlite3_errmsg(db));
    }
  } else {
    fprintf(stderr, "%s\n", sqlite3_errmsg(db));
  }
  return rc;
}
static int lintDotCommand(ShellState *pState, char **azArg, int nArg) {
  int n;
  n = (nArg >= 2 ? strlen30(azArg[1]) : 0);
  if (n < 1 || sqlite3_strnicmp(azArg[1], "fkey-indexes", n))
    goto usage;
  return lintFkeyIndexes(pState, azArg, nArg);
usage:
  fprintf(stderr, "Usage %s sub-command ?switches...?\n", azArg[0]);
  fprintf(stderr, "Where sub-commands are:\n");
  fprintf(stderr, "    fkey-indexes\n");
  return 1;
}
static void shellPrepare(sqlite3 *db, int *pRc, const char *zSql,
                         sqlite3_stmt **ppStmt) {
  *ppStmt = 0;
  if (*pRc == 0) {
    int rc = sqlite3_prepare_v2(db, zSql, -1, ppStmt, 0);
    if (rc != 0) {
      fprintf(stderr, "sql error: %s (%d)\n", sqlite3_errmsg(db),
              sqlite3_errcode(db));
      *pRc = rc;
    }
  }
}
void shellPreparePrintf(sqlite3 *db, int *pRc, sqlite3_stmt **ppStmt,
                        const char *zFmt, ...) {
  *ppStmt = 0;
  if (*pRc == 0) {
    va_list ap;
    char *z;
    __builtin_va_start(ap, zFmt);
    z = sqlite3_vmprintf(zFmt, ap);
    __builtin_va_end(ap);
    if (z == 0) {
      *pRc = 7;
    } else {
      shellPrepare(db, pRc, z, ppStmt);
      sqlite3_free(z);
    }
  }
}
void shellFinalize(int *pRc, sqlite3_stmt *pStmt) {
  if (pStmt) {
    sqlite3 *db = sqlite3_db_handle(pStmt);
    int rc = sqlite3_finalize(pStmt);
    if (*pRc == 0) {
      if (rc != 0) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
      }
      *pRc = rc;
    }
  }
}
void shellReset(int *pRc, sqlite3_stmt *pStmt) {
  int rc = sqlite3_reset(pStmt);
  if (*pRc == 0) {
    if (rc != 0) {
      sqlite3 *db = sqlite3_db_handle(pStmt);
      fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
    }
    *pRc = rc;
  }
}
static void rc_err_oom_die(int rc) {
  if (rc == 7)
    shell_check_oom(0);
  ((void)sizeof((rc == 0 || rc == 101) ? 1 : 0), ({
     if (rc == 0 || rc == 101)
       ;
     else
       __assert_fail("rc==SQLITE_OK||rc==SQLITE_DONE", "shell.c", 23058,
                     __PRETTY_FUNCTION__);
   }));
}
static const char *zCOL_DB = ":memory:";
static char *zAutoColumn(const char *zColNew, sqlite3 **pDb, char **pzRenamed) {
  static const char *const zTabMake =
      "CREATE TABLE ColNames( cpos INTEGER PRIMARY KEY, name TEXT, nlen INT, "
      "chop INT, reps INT, suff TEXT);CREATE VIEW RepeatedNames AS SELECT "
      "DISTINCT t.name FROM ColNames t WHERE t.name COLLATE NOCASE IN ( SELECT "
      "o.name FROM ColNames o WHERE o.cpos<>t.cpos);";
  static const char *const zTabFill =
      "INSERT INTO ColNames(name,nlen,chop,reps,suff) "
      "VALUES(iif(length(?1)>0,?1,'?'),max(length(?1),1),0,0,'')";
  static const char *const zHasDupes =
      "SELECT count(DISTINCT (substring(name,1,nlen-chop)||suff) COLLATE "
      "NOCASE) <count(name) FROM ColNames";
  static const char *const zSetReps =
      "UPDATE ColNames AS t SET reps=(SELECT count(*) FROM ColNames d  WHERE "
      "substring(t.name,1,t.nlen-t.chop)=substring(d.name,1,d.nlen-d.chop) "
      "COLLATE NOCASE)";
  static const char *const zColDigits =
      "SELECT CASE WHEN (nc < 10) THEN 1 WHEN (nc < 100) THEN 2  WHEN (nc < "
      "1000) THEN 3 WHEN (nc < 10000) THEN 4  ELSE 5 FROM (SELECT count(*) AS "
      "nc FROM ColNames) ";
  static const char *const zRenameRank =
      "WITH Lzn(nlz) AS (  SELECT 0 AS nlz  UNION  SELECT nlz+1 AS nlz FROM "
      "Lzn  WHERE EXISTS(   SELECT 1   FROM ColNames t, ColNames o   WHERE    "
      "iif(t.name IN (SELECT * FROM RepeatedNames),     printf('%s_%s',      "
      "t.name, substring(printf('%.*c%0.*d',nlz+1,'0',$1,t.cpos),2)),     "
      "t.name    )    =    iif(o.name IN (SELECT * FROM RepeatedNames),     "
      "printf('%s_%s',      o.name, "
      "substring(printf('%.*c%0.*d',nlz+1,'0',$1,o.cpos),2)),     o.name    )  "
      "  COLLATE NOCASE    AND o.cpos<>t.cpos   GROUP BY t.cpos  )) UPDATE "
      "Colnames AS t SET chop = 0, suff = iif(name IN (SELECT * FROM "
      "RepeatedNames),  printf('_%s', substring(   printf('%.*c%0.*d',(SELECT "
      "max(nlz) FROM Lzn)+1,'0',1,t.cpos),2)),  '' )";
  static const char *const zCollectVar =
      "SELECT '('||x'0a' || group_concat(  cname||' TEXT',  "
      "','||iif((cpos-1)%4>0, ' ', x'0a'||' ')) ||')' AS ColsSpec FROM ( "
      "SELECT cpos, printf('\"%w\"',printf('%!.*s%s', nlen-chop,name,suff)) AS "
      "cname  FROM ColNames ORDER BY cpos)";
  static const char *const zRenamesDone =
      "SELECT group_concat( printf('\"%w\" to \"%w\"',name,printf('%!.*s%s', "
      "nlen-chop, name, suff)), ','||x'0a')FROM ColNames WHERE suff<>'' OR "
      "chop!=0";
  int rc;
  sqlite3_stmt *pStmt = 0;
  ((void)sizeof((pDb != 0) ? 1 : 0), ({
     if (pDb != 0)
       ;
     else
       __assert_fail("pDb!=0", "shell.c", 23184, __PRETTY_FUNCTION__);
   }));
  if (zColNew) {
    if (*pDb == 0) {
      if (0 != sqlite3_open(zCOL_DB, pDb))
        return 0;
      rc = sqlite3_exec(*pDb, zTabMake, 0, 0, 0);
      rc_err_oom_die(rc);
    }
    ((void)sizeof((*pDb != 0) ? 1 : 0), ({
       if (*pDb != 0)
         ;
       else
         __assert_fail("*pDb!=0", "shell.c", 23197, __PRETTY_FUNCTION__);
     }));
    rc = sqlite3_prepare_v2(*pDb, zTabFill, -1, &pStmt, 0);
    rc_err_oom_die(rc);
    rc = sqlite3_bind_text(pStmt, 1, zColNew, -1, 0);
    rc_err_oom_die(rc);
    rc = sqlite3_step(pStmt);
    rc_err_oom_die(rc);
    sqlite3_finalize(pStmt);
    return 0;
  } else if (*pDb == 0) {
    return 0;
  } else {
    char *zColsSpec = 0;
    int hasDupes = db_int(*pDb, zHasDupes);
    int nDigits = (hasDupes) ? db_int(*pDb, zColDigits) : 0;
    if (hasDupes) {
      rc = sqlite3_exec(*pDb, zSetReps, 0, 0, 0);
      rc_err_oom_die(rc);
      rc = sqlite3_prepare_v2(*pDb, zRenameRank, -1, &pStmt, 0);
      rc_err_oom_die(rc);
      sqlite3_bind_int(pStmt, 1, nDigits);
      rc = sqlite3_step(pStmt);
      sqlite3_finalize(pStmt);
      if (rc != 101)
        rc_err_oom_die(7);
    }
    ((void)sizeof((db_int(*pDb, zHasDupes) == 0) ? 1 : 0), ({
       if (db_int(*pDb, zHasDupes) == 0)
         ;
       else
         __assert_fail("db_int(*pDb, zHasDupes)==0", "shell.c", 23227,
                       __PRETTY_FUNCTION__);
     }));
    rc = sqlite3_prepare_v2(*pDb, zCollectVar, -1, &pStmt, 0);
    rc_err_oom_die(rc);
    rc = sqlite3_step(pStmt);
    if (rc == 100) {
      zColsSpec = sqlite3_mprintf("%s", sqlite3_column_text(pStmt, 0));
    } else {
      zColsSpec = 0;
    }
    if (pzRenamed != 0) {
      if (!hasDupes)
        *pzRenamed = 0;
      else {
        sqlite3_finalize(pStmt);
        if (0 == sqlite3_prepare_v2(*pDb, zRenamesDone, -1, &pStmt, 0) &&
            100 == sqlite3_step(pStmt)) {
          *pzRenamed = sqlite3_mprintf("%s", sqlite3_column_text(pStmt, 0));
        } else
          *pzRenamed = 0;
      }
    }
    sqlite3_finalize(pStmt);
    sqlite3_close(*pDb);
    *pDb = 0;
    return zColsSpec;
  }
}
static int do_meta_command(char *zLine, ShellState *p) {
  int h = 1;
  int nArg = 0;
  int n, c;
  int rc = 0;
  char *azArg[52];
  if (p->expert.pExpert) {
    expertFinish(p, 1, 0);
  }
  while (zLine[h] && nArg < (int)(sizeof(azArg) / sizeof(azArg[0])) - 1) {
    while (((*__ctype_b_loc())[(int)(((unsigned char)zLine[h]))] &
            (unsigned short int)_ISspace)) {
      h++;
    }
    if (zLine[h] == 0)
      break;
    if (zLine[h] == '\'' || zLine[h] == '\"') {
      int delim = zLine[h++];
      azArg[nArg++] = &zLine[h];
      while (zLine[h] && zLine[h] != delim) {
        if (zLine[h] == '\\' && delim == '\"' && zLine[h + 1] != 0)
          h++;
        h++;
      }
      if (zLine[h] == delim) {
        zLine[h++] = 0;
      }
      if (delim == '\"')
        resolve_backslashes(azArg[nArg - 1]);
    } else {
      azArg[nArg++] = &zLine[h];
      while (zLine[h] &&
             !((*__ctype_b_loc())[(int)(((unsigned char)zLine[h]))] &
               (unsigned short int)_ISspace)) {
        h++;
      }
      if (zLine[h])
        zLine[h++] = 0;
      resolve_backslashes(azArg[nArg - 1]);
    }
  }
  azArg[nArg] = 0;
  if (nArg == 0)
    return 0;
  n = strlen30(azArg[0]);
  c = azArg[0][0];
  clearTempFile(p);
  if (c == 'a' && cli_strncmp(azArg[0], "auth", n) == 0) {
    if (nArg != 2) {
      fprintf(stderr, "Usage: .auth ON|OFF\n");
      rc = 1;
      goto meta_command_exit;
    }
    open_db(p, 0);
    if (booleanValue(azArg[1])) {
      sqlite3_set_authorizer(p->db, shellAuth, p);
    } else if (p->bSafeModePersist) {
      sqlite3_set_authorizer(p->db, safeModeAuth, p);
    } else {
      sqlite3_set_authorizer(p->db, 0, 0);
    }
  } else if ((c == 'b' && n >= 3 && cli_strncmp(azArg[0], "backup", n) == 0) ||
             (c == 's' && n >= 3 && cli_strncmp(azArg[0], "save", n) == 0)) {
    const char *zDestFile = 0;
    const char *zDb = 0;
    sqlite3 *pDest;
    sqlite3_backup *pBackup;
    int j;
    int bAsync = 0;
    const char *zVfs = 0;
    failIfSafeMode(p, "cannot run .%s in safe mode", azArg[0]);
    for (j = 1; j < nArg; j++) {
      const char *z = azArg[j];
      if (z[0] == '-') {
        if (z[1] == '-')
          z++;
        if (cli_strcmp(z, "-append") == 0) {
          zVfs = "apndvfs";
        } else if (cli_strcmp(z, "-async") == 0) {
          bAsync = 1;
        } else {
          fprintf(stderr, "unknown option: %s\n", azArg[j]);
          return 1;
        }
      } else if (zDestFile == 0) {
        zDestFile = azArg[j];
      } else if (zDb == 0) {
        zDb = zDestFile;
        zDestFile = azArg[j];
      } else {
        fprintf(stderr, "Usage: .backup ?DB? ?OPTIONS? FILENAME\n");
        return 1;
      }
    }
    if (zDestFile == 0) {
      fprintf(stderr, "missing FILENAME argument on .backup\n");
      return 1;
    }
    if (zDb == 0)
      zDb = "main";
    rc = sqlite3_open_v2(zDestFile, &pDest, 2 | 4, zVfs);
    if (rc != 0) {
      fprintf(stderr, "Error: cannot open \"%s\"\n", zDestFile);
      close_db(pDest);
      return 1;
    }
    if (bAsync) {
      sqlite3_exec(pDest, "PRAGMA synchronous=OFF; PRAGMA journal_mode=OFF;", 0,
                   0, 0);
    }
    open_db(p, 0);
    pBackup = sqlite3_backup_init(pDest, "main", p->db, zDb);
    if (pBackup == 0) {
      fprintf(stderr, "Error: %s\n", sqlite3_errmsg(pDest));
      close_db(pDest);
      return 1;
    }
    while ((rc = sqlite3_backup_step(pBackup, 100)) == 0) {
    }
    sqlite3_backup_finish(pBackup);
    if (rc == 101) {
      rc = 0;
    } else {
      fprintf(stderr, "Error: %s\n", sqlite3_errmsg(pDest));
      rc = 1;
    }
    close_db(pDest);
  } else if (c == 'b' && n >= 3 && cli_strncmp(azArg[0], "bail", n) == 0) {
    if (nArg == 2) {
      bail_on_error = booleanValue(azArg[1]);
    } else {
      fprintf(stderr, "Usage: .bail on|off\n");
      rc = 1;
    }
  } else if (c == 'b' && n >= 3 && cli_strncmp(azArg[0], "binary", n) == 0) {
    if (nArg == 2) {
      if (booleanValue(azArg[1])) {
        ;
      } else {
        ;
      }
    } else {
      fprintf(stderr, "Usage: .binary on|off\n");
      rc = 1;
    }
  } else if (c == 'b' && n >= 3 &&
             cli_strncmp(azArg[0], "breakpoint", n) == 0) {
    test_breakpoint();
  } else if (c == 'c' && cli_strcmp(azArg[0], "cd") == 0) {
    failIfSafeMode(p, "cannot run .cd in safe mode");
    if (nArg == 2) {
      rc = chdir(azArg[1]);
      if (rc) {
        fprintf(stderr, "Cannot change to directory \"%s\"\n", azArg[1]);
        rc = 1;
      }
    } else {
      fprintf(stderr, "Usage: .cd DIRECTORY\n");
      rc = 1;
    }
  } else if (c == 'c' && n >= 3 && cli_strncmp(azArg[0], "changes", n) == 0) {
    if (nArg == 2) {
      setOrClearFlag(p, 32, azArg[1]);
    } else {
      fprintf(stderr, "Usage: .changes on|off\n");
      rc = 1;
    }
  } else if (c == 'c' && n >= 3 && cli_strncmp(azArg[0], "check", n) == 0) {
    char *zRes = 0;
    output_reset(p);
    if (nArg != 2) {
      fprintf(stderr, "Usage: .check GLOB-PATTERN\n");
      rc = 2;
    } else if ((zRes = readFile("testcase-out.txt", 0)) == 0) {
      rc = 2;
    } else if (testcase_glob(azArg[1], zRes) == 0) {
      fprintf(stderr, "testcase-%s FAILED\n Expected: [%s]\n      Got: [%s]\n",
              p->zTestcase, azArg[1], zRes);
      rc = 1;
    } else {
      fprintf(stdout, "testcase-%s ok\n", p->zTestcase);
      p->nCheck++;
    }
    sqlite3_free(zRes);
  } else if (c == 'c' && cli_strncmp(azArg[0], "clone", n) == 0) {
    failIfSafeMode(p, "cannot run .clone in safe mode");
    if (nArg == 2) {
      tryToClone(p, azArg[1]);
    } else {
      fprintf(stderr, "Usage: .clone FILENAME\n");
      rc = 1;
    }
  } else if (c == 'c' && cli_strncmp(azArg[0], "connection", n) == 0) {
    if (nArg == 1) {
      int i;
      for (i = 0; i < (int)(sizeof(p->aAuxDb) / sizeof(p->aAuxDb[0])); i++) {
        const char *zFile = p->aAuxDb[i].zDbFilename;
        if (p->aAuxDb[i].db == 0 && p->pAuxDb != &p->aAuxDb[i]) {
          zFile = "(not open)";
        } else if (zFile == 0) {
          zFile = "(memory)";
        } else if (zFile[0] == 0) {
          zFile = "(temporary-file)";
        }
        if (p->pAuxDb == &p->aAuxDb[i]) {
          fprintf(stdout, "ACTIVE %d: %s\n", i, zFile);
        } else if (p->aAuxDb[i].db != 0) {
          fprintf(stdout, "       %d: %s\n", i, zFile);
        }
      }
    } else if (nArg == 2 &&
               ((*__ctype_b_loc())[(int)(((unsigned char)azArg[1][0]))] &
                (unsigned short int)_ISdigit) &&
               azArg[1][1] == 0) {
      int i = azArg[1][0] - '0';
      if (p->pAuxDb != &p->aAuxDb[i] && i >= 0 &&
          i < (int)(sizeof(p->aAuxDb) / sizeof(p->aAuxDb[0]))) {
        p->pAuxDb->db = p->db;
        p->pAuxDb = &p->aAuxDb[i];
        globalDb = p->db = p->pAuxDb->db;
        p->pAuxDb->db = 0;
      }
    } else if (nArg == 3 && cli_strcmp(azArg[1], "close") == 0 &&
               ((*__ctype_b_loc())[(int)(((unsigned char)azArg[2][0]))] &
                (unsigned short int)_ISdigit) &&
               azArg[2][1] == 0) {
      int i = azArg[2][0] - '0';
      if (i < 0 || i >= (int)(sizeof(p->aAuxDb) / sizeof(p->aAuxDb[0]))) {
      } else if (p->pAuxDb == &p->aAuxDb[i]) {
        fprintf(stderr, "cannot close the active database connection\n");
        rc = 1;
      } else if (p->aAuxDb[i].db) {
        ;
        close_db(p->aAuxDb[i].db);
        p->aAuxDb[i].db = 0;
      }
    } else {
      fprintf(stderr, "Usage: .connection [close] [CONNECTION-NUMBER]\n");
      rc = 1;
    }
  } else if (c == 'd' && n > 1 && cli_strncmp(azArg[0], "databases", n) == 0) {
    char **azName = 0;
    int nName = 0;
    sqlite3_stmt *pStmt;
    int i;
    open_db(p, 0);
    rc = sqlite3_prepare_v2(p->db, "PRAGMA database_list", -1, &pStmt, 0);
    if (rc) {
      fprintf(stderr, "Error: %s\n", sqlite3_errmsg(p->db));
      rc = 1;
    } else {
      while (sqlite3_step(pStmt) == 100) {
        const char *zSchema = (const char *)sqlite3_column_text(pStmt, 1);
        const char *zFile = (const char *)sqlite3_column_text(pStmt, 2);
        if (zSchema == 0 || zFile == 0)
          continue;
        azName = sqlite3_realloc(azName, (nName + 1) * 2 * sizeof(char *));
        shell_check_oom(azName);
        azName[nName * 2] = strdup(zSchema);
        azName[nName * 2 + 1] = strdup(zFile);
        nName++;
      }
    }
    sqlite3_finalize(pStmt);
    for (i = 0; i < nName; i++) {
      int eTxn = sqlite3_txn_state(p->db, azName[i * 2]);
      int bRdonly = sqlite3_db_readonly(p->db, azName[i * 2]);
      const char *z = azName[i * 2 + 1];
      fprintf(p->out, "%s: %s %s%s\n", azName[i * 2], z && z[0] ? z : "\"\"",
              bRdonly ? "r/o" : "r/w",
              eTxn == 0   ? ""
              : eTxn == 1 ? " read-txn"
                          : " write-txn");
      free(azName[i * 2]);
      free(azName[i * 2 + 1]);
    }
    sqlite3_free(azName);
  } else if (c == 'd' && n >= 3 && cli_strncmp(azArg[0], "dbconfig", n) == 0) {
    static const struct DbConfigChoices {
      const char *zName;
      int op;
    } aDbConfig[] = {{"defensive", 1010},
                     {"dqs_ddl", 1014},
                     {"dqs_dml", 1013},
                     {"enable_fkey", 1002},
                     {"enable_qpsg", 1007},
                     {"enable_trigger", 1003},
                     {"enable_view", 1015},
                     {"fts3_tokenizer", 1004},
                     {"legacy_alter_table", 1012},
                     {"legacy_file_format", 1016},
                     {"load_extension", 1005},
                     {"no_ckpt_on_close", 1006},
                     {"reset_database", 1009},
                     {"reverse_scanorder", 1019},
                     {"stmt_scanstatus", 1018},
                     {"trigger_eqp", 1008},
                     {"trusted_schema", 1017},
                     {"writable_schema", 1011}};
    int ii, v;
    open_db(p, 0);
    for (ii = 0; ii < (int)(sizeof(aDbConfig) / sizeof(aDbConfig[0])); ii++) {
      if (nArg > 1 && cli_strcmp(azArg[1], aDbConfig[ii].zName) != 0)
        continue;
      if (nArg >= 3) {
        sqlite3_db_config(p->db, aDbConfig[ii].op, booleanValue(azArg[2]), 0);
      }
      sqlite3_db_config(p->db, aDbConfig[ii].op, -1, &v);
      fprintf(p->out, "%19s %s\n", aDbConfig[ii].zName, v ? "on" : "off");
      if (nArg > 1)
        break;
    }
    if (nArg > 1 && ii == (int)(sizeof(aDbConfig) / sizeof(aDbConfig[0]))) {
      fprintf(stderr, "Error: unknown dbconfig \"%s\"\n", azArg[1]);
      fprintf(stderr, "Enter \".dbconfig\" with no arguments for a list\n");
    }
  } else if (c == 'd' && cli_strncmp(azArg[0], "dump", n) == 0) {
    char *zLike = 0;
    char *zSql;
    int i;
    int savedShowHeader = p->showHeader;
    int savedShellFlags = p->shellFlgs;
    ((p)->shellFlgs &= (~(8 | 16 | 64 | 256 | 512)));
    for (i = 1; i < nArg; i++) {
      if (azArg[i][0] == '-') {
        const char *z = azArg[i] + 1;
        if (z[0] == '-')
          z++;
        if (cli_strcmp(z, "preserve-rowids") == 0) {
          ((p)->shellFlgs |= (8));
        } else if (cli_strcmp(z, "newlines") == 0) {
          ((p)->shellFlgs |= (16));
        } else if (cli_strcmp(z, "data-only") == 0) {
          ((p)->shellFlgs |= (256));
        } else if (cli_strcmp(z, "nosys") == 0) {
          ((p)->shellFlgs |= (512));
        } else {
          fprintf(stderr, "Unknown option \"%s\" on \".dump\"\n", azArg[i]);
          rc = 1;
          sqlite3_free(zLike);
          goto meta_command_exit;
        }
      } else {
        char *zExpr = sqlite3_mprintf(
            "name LIKE %Q ESCAPE '\\' OR EXISTS (  SELECT 1 FROM sqlite_schema "
            "WHERE     name LIKE %Q ESCAPE '\\' AND    sql LIKE 'CREATE "
            "VIRTUAL TABLE%%' AND    substr(o.name, 1, length(name)+1) == "
            "(name||'_'))",
            azArg[i], azArg[i]);
        if (zLike) {
          zLike = sqlite3_mprintf("%z OR %z", zLike, zExpr);
        } else {
          zLike = zExpr;
        }
      }
    }
    open_db(p, 0);
    if ((p->shellFlgs & 256) == 0) {
      fprintf(p->out, "PRAGMA foreign_keys=OFF;\n");
      fprintf(p->out, "BEGIN TRANSACTION;\n");
    }
    p->writableSchema = 0;
    p->showHeader = 0;
    sqlite3_exec(p->db, "SAVEPOINT dump; PRAGMA writable_schema=ON", 0, 0, 0);
    p->nErr = 0;
    if (zLike == 0)
      zLike = sqlite3_mprintf("true");
    zSql = sqlite3_mprintf("SELECT name, type, sql FROM sqlite_schema AS o "
                           "WHERE (%s) AND type=='table'  AND sql NOT NULL "
                           "ORDER BY tbl_name='sqlite_sequence', rowid",
                           zLike);
    run_schema_dump_query(p, zSql);
    sqlite3_free(zSql);
    if ((p->shellFlgs & 256) == 0) {
      zSql = sqlite3_mprintf(
          "SELECT sql FROM sqlite_schema AS o WHERE (%s) AND sql NOT NULL  AND "
          "type IN ('index','trigger','view')",
          zLike);
      run_table_dump_query(p, zSql);
      sqlite3_free(zSql);
    }
    sqlite3_free(zLike);
    if (p->writableSchema) {
      fprintf(p->out, "PRAGMA writable_schema=OFF;\n");
      p->writableSchema = 0;
    }
    sqlite3_exec(p->db, "PRAGMA writable_schema=OFF;", 0, 0, 0);
    sqlite3_exec(p->db, "RELEASE dump;", 0, 0, 0);
    if ((p->shellFlgs & 256) == 0) {
      fprintf(p->out, p->nErr ? "ROLLBACK; -- due to errors\n" : "COMMIT;\n");
    }
    p->showHeader = savedShowHeader;
    p->shellFlgs = savedShellFlags;
  } else if (c == 'e' && cli_strncmp(azArg[0], "echo", n) == 0) {
    if (nArg == 2) {
      setOrClearFlag(p, 64, azArg[1]);
    } else {
      fprintf(stderr, "Usage: .echo on|off\n");
      rc = 1;
    }
  } else if (c == 'e' && cli_strncmp(azArg[0], "eqp", n) == 0) {
    if (nArg == 2) {
      p->autoEQPtest = 0;
      if (p->autoEQPtrace) {
        if (p->db)
          sqlite3_exec(p->db, "PRAGMA vdbe_trace=OFF;", 0, 0, 0);
        p->autoEQPtrace = 0;
      }
      if (cli_strcmp(azArg[1], "full") == 0) {
        p->autoEQP = 3;
      } else if (cli_strcmp(azArg[1], "trigger") == 0) {
        p->autoEQP = 2;
      } else {
        p->autoEQP = (u8)booleanValue(azArg[1]);
      }
    } else {
      fprintf(stderr, "Usage: .eqp off|on|trace|trigger|full\n");
      rc = 1;
    }
  } else if (c == 'e' && cli_strncmp(azArg[0], "exit", n) == 0) {
    if (nArg > 1 && (rc = (int)integerValue(azArg[1])) != 0)
      exit(rc);
    rc = 2;
  } else if (c == 'e' && cli_strncmp(azArg[0], "explain", n) == 0) {
    int val = 1;
    if (nArg >= 2) {
      if (cli_strcmp(azArg[1], "auto") == 0) {
        val = 99;
      } else {
        val = booleanValue(azArg[1]);
      }
    }
    if (val == 1 && p->mode != 9) {
      p->normalMode = p->mode;
      p->mode = 9;
      p->autoExplain = 0;
    } else if (val == 0) {
      if (p->mode == 9)
        p->mode = p->normalMode;
      p->autoExplain = 0;
    } else if (val == 99) {
      if (p->mode == 9)
        p->mode = p->normalMode;
      p->autoExplain = 1;
    }
  } else if (c == 'e' && cli_strncmp(azArg[0], "expert", n) == 0) {
    if (p->bSafeMode) {
      fprintf(stderr,
              "Cannot run experimental commands such as \"%s\" in safe mode\n",
              azArg[0]);
      rc = 1;
    } else {
      open_db(p, 0);
      expertDotCommand(p, azArg, nArg);
    }
  } else if (c == 'f' && cli_strncmp(azArg[0], "filectrl", n) == 0) {
    static const struct {
      const char *zCtrlName;
      int ctrlCode;
      const char *zUsage;
    } aCtrl[] = {{"chunk_size", 6, "SIZE"},
                 {"data_version", 35, ""},
                 {"has_moved", 20, ""},
                 {"lock_timeout", 34, "MILLISEC"},
                 {"persist_wal", 10, "[BOOLEAN]"},
                 {"psow", 13, "[BOOLEAN]"},
                 {"reserve_bytes", 38, "[N]"},
                 {"size_limit", 36, "[LIMIT]"},
                 {"tempfilename", 16, ""}};
    int filectrl = -1;
    int iCtrl = -1;
    sqlite3_int64 iRes = 0;
    int isOk = 0;
    int n2, i;
    const char *zCmd = 0;
    const char *zSchema = 0;
    open_db(p, 0);
    zCmd = nArg >= 2 ? azArg[1] : "help";
    if (zCmd[0] == '-' &&
        (cli_strcmp(zCmd, "--schema") == 0 ||
         cli_strcmp(zCmd, "-schema") == 0) &&
        nArg >= 4) {
      zSchema = azArg[2];
      for (i = 3; i < nArg; i++)
        azArg[i - 2] = azArg[i];
      nArg -= 2;
      zCmd = azArg[1];
    }
    if (zCmd[0] == '-' && zCmd[1]) {
      zCmd++;
      if (zCmd[0] == '-' && zCmd[1])
        zCmd++;
    }
    if (cli_strcmp(zCmd, "help") == 0) {
      fprintf(p->out, "Available file-controls:\n");
      for (i = 0; i < (int)(sizeof(aCtrl) / sizeof(aCtrl[0])); i++) {
        fprintf(p->out, "  .filectrl %s %s\n", aCtrl[i].zCtrlName,
                aCtrl[i].zUsage);
      }
      rc = 1;
      goto meta_command_exit;
    }
    n2 = strlen30(zCmd);
    for (i = 0; i < (int)(sizeof(aCtrl) / sizeof(aCtrl[0])); i++) {
      if (cli_strncmp(zCmd, aCtrl[i].zCtrlName, n2) == 0) {
        if (filectrl < 0) {
          filectrl = aCtrl[i].ctrlCode;
          iCtrl = i;
        } else {
          fprintf(stderr,
                  "Error: ambiguous file-control: \"%s\"\nUse \".filectrl "
                  "--help\" for help\n",
                  zCmd);
          rc = 1;
          goto meta_command_exit;
        }
      }
    }
    if (filectrl < 0) {
      fprintf(stderr,
              "Error: unknown file-control: %s\nUse \".filectrl --help\" for "
              "help\n",
              zCmd);
    } else {
      switch (filectrl) {
      case 36: {
        if (nArg != 2 && nArg != 3)
          break;
        iRes = nArg == 3 ? integerValue(azArg[2]) : -1;
        sqlite3_file_control(p->db, zSchema, 36, &iRes);
        isOk = 1;
        break;
      }
      case 34:
      case 6: {
        int x;
        if (nArg != 3)
          break;
        x = (int)integerValue(azArg[2]);
        sqlite3_file_control(p->db, zSchema, filectrl, &x);
        isOk = 2;
        break;
      }
      case 10:
      case 13: {
        int x;
        if (nArg != 2 && nArg != 3)
          break;
        x = nArg == 3 ? booleanValue(azArg[2]) : -1;
        sqlite3_file_control(p->db, zSchema, filectrl, &x);
        iRes = x;
        isOk = 1;
        break;
      }
      case 35:
      case 20: {
        int x;
        if (nArg != 2)
          break;
        sqlite3_file_control(p->db, zSchema, filectrl, &x);
        iRes = x;
        isOk = 1;
        break;
      }
      case 16: {
        char *z = 0;
        if (nArg != 2)
          break;
        sqlite3_file_control(p->db, zSchema, filectrl, &z);
        if (z) {
          fprintf(p->out, "%s\n", z);
          sqlite3_free(z);
        }
        isOk = 2;
        break;
      }
      case 38: {
        int x;
        if (nArg >= 3) {
          x = atoi(azArg[2]);
          sqlite3_file_control(p->db, zSchema, filectrl, &x);
        }
        x = -1;
        sqlite3_file_control(p->db, zSchema, filectrl, &x);
        fprintf(p->out, "%d\n", x);
        isOk = 2;
        break;
      }
      }
    }
    if (isOk == 0 && iCtrl >= 0) {
      fprintf(p->out, "Usage: .filectrl %s %s\n", zCmd, aCtrl[iCtrl].zUsage);
      rc = 1;
    } else if (isOk == 1) {
      char zBuf[100];
      sqlite3_snprintf(sizeof(zBuf), zBuf, "%lld", iRes);
      fprintf(p->out, "%s\n", zBuf);
    }
  } else if (c == 'f' && cli_strncmp(azArg[0], "fullschema", n) == 0) {
    ShellState data;
    int doStats = 0;
    memcpy(&data, p, sizeof(data));
    data.showHeader = 0;
    data.cMode = data.mode = 3;
    if (nArg == 2 && optionMatch(azArg[1], "indent")) {
      data.cMode = data.mode = 11;
      nArg = 1;
    }
    if (nArg != 1) {
      fprintf(stderr, "Usage: .fullschema ?--indent?\n");
      rc = 1;
      goto meta_command_exit;
    }
    open_db(p, 0);
    rc = sqlite3_exec(
        p->db,
        "SELECT sql FROM  (SELECT sql sql, type type, tbl_name tbl_name, name "
        "name, rowid x     FROM sqlite_schema UNION ALL   SELECT sql, type, "
        "tbl_name, name, rowid FROM sqlite_temp_schema) WHERE type!='meta' AND "
        "sql NOTNULL AND name NOT LIKE 'sqlite_%' ORDER BY x",
        callback, &data, 0);
    if (rc == 0) {
      sqlite3_stmt *pStmt;
      rc = sqlite3_prepare_v2(
          p->db,
          "SELECT rowid FROM sqlite_schema WHERE name GLOB 'sqlite_stat[134]'",
          -1, &pStmt, 0);
      doStats = sqlite3_step(pStmt) == 100;
      sqlite3_finalize(pStmt);
    }
    if (doStats == 0) {
      fprintf(p->out, "/* No STAT tables available */\n");
    } else {
      fprintf(p->out, "ANALYZE sqlite_schema;\n");
      data.cMode = data.mode = 5;
      data.zDestTable = "sqlite_stat1";
      shell_exec(&data, "SELECT * FROM sqlite_stat1", 0);
      data.zDestTable = "sqlite_stat4";
      shell_exec(&data, "SELECT * FROM sqlite_stat4", 0);
      fprintf(p->out, "ANALYZE sqlite_schema;\n");
    }
  } else if (c == 'h' && cli_strncmp(azArg[0], "headers", n) == 0) {
    if (nArg == 2) {
      p->showHeader = booleanValue(azArg[1]);
      p->shellFlgs |= 128;
    } else {
      fprintf(stderr, "Usage: .headers on|off\n");
      rc = 1;
    }
  } else if (c == 'h' && cli_strncmp(azArg[0], "help", n) == 0) {
    if (nArg >= 2) {
      n = showHelp(p->out, azArg[1]);
      if (n == 0) {
        fprintf(p->out, "Nothing matches '%s'\n", azArg[1]);
      }
    } else {
      showHelp(p->out, 0);
    }
  } else if (c == 'i' && cli_strncmp(azArg[0], "import", n) == 0) {
    char *zTable = 0;
    char *zSchema = 0;
    char *zFile = 0;
    sqlite3_stmt *pStmt = ((void *)0);
    int nCol;
    int nByte;
    int i, j;
    int needCommit;
    int nSep;
    char *zSql;
    char *zFullTabName;
    ImportCtx sCtx;
    char *(*xRead)(ImportCtx *);
    int eVerbose = 0;
    int nSkip = 0;
    int useOutputMode = 1;
    char *zCreate = 0;
    failIfSafeMode(p, "cannot run .import in safe mode");
    memset(&sCtx, 0, sizeof(sCtx));
    if (p->mode == 10) {
      xRead = ascii_read_one_field;
    } else {
      xRead = csv_read_one_field;
    }
    rc = 1;
    for (i = 1; i < nArg; i++) {
      char *z = azArg[i];
      if (z[0] == '-' && z[1] == '-')
        z++;
      if (z[0] != '-') {
        if (zFile == 0) {
          zFile = z;
        } else if (zTable == 0) {
          zTable = z;
        } else {
          fprintf(p->out, "ERROR: extra argument: \"%s\".  Usage:\n", z);
          showHelp(p->out, "import");
          goto meta_command_exit;
        }
      } else if (cli_strcmp(z, "-v") == 0) {
        eVerbose++;
      } else if (cli_strcmp(z, "-schema") == 0 && i < nArg - 1) {
        zSchema = azArg[++i];
      } else if (cli_strcmp(z, "-skip") == 0 && i < nArg - 1) {
        nSkip = integerValue(azArg[++i]);
      } else if (cli_strcmp(z, "-ascii") == 0) {
        sCtx.cColSep = "\x1f"[0];
        sCtx.cRowSep = "\x1e"[0];
        xRead = ascii_read_one_field;
        useOutputMode = 0;
      } else if (cli_strcmp(z, "-csv") == 0) {
        sCtx.cColSep = ',';
        sCtx.cRowSep = '\n';
        xRead = csv_read_one_field;
        useOutputMode = 0;
      } else {
        fprintf(p->out, "ERROR: unknown option: \"%s\".  Usage:\n", z);
        showHelp(p->out, "import");
        goto meta_command_exit;
      }
    }
    if (zTable == 0) {
      fprintf(p->out, "ERROR: missing %s argument. Usage:\n",
              zFile == 0 ? "FILE" : "TABLE");
      showHelp(p->out, "import");
      goto meta_command_exit;
    }
    seenInterrupt = 0;
    open_db(p, 0);
    if (useOutputMode) {
      nSep = strlen30(p->colSeparator);
      if (nSep == 0) {
        fprintf(stderr,
                "Error: non-null column separator required for import\n");
        goto meta_command_exit;
      }
      if (nSep > 1) {
        fprintf(stderr, "Error: multi-character column separators not allowed "
                        "for import\n");
        goto meta_command_exit;
      }
      nSep = strlen30(p->rowSeparator);
      if (nSep == 0) {
        fprintf(stderr, "Error: non-null row separator required for import\n");
        goto meta_command_exit;
      }
      if (nSep == 2 && p->mode == 8 &&
          cli_strcmp(p->rowSeparator, "\x0d\n") == 0) {
        sqlite3_snprintf(sizeof(p->rowSeparator), p->rowSeparator, "\n");
        nSep = strlen30(p->rowSeparator);
      }
      if (nSep > 1) {
        fprintf(
            stderr,
            "Error: multi-character row separators not allowed for import\n");
        goto meta_command_exit;
      }
      sCtx.cColSep = (u8)p->colSeparator[0];
      sCtx.cRowSep = (u8)p->rowSeparator[0];
    }
    sCtx.zFile = zFile;
    sCtx.nLine = 1;
    if (sCtx.zFile[0] == '|') {
      sCtx.in = popen(sCtx.zFile + 1, "r");
      sCtx.zFile = "<pipe>";
      sCtx.xCloser = pclose;
    } else {
      sCtx.in = fopen(sCtx.zFile, "rb");
      sCtx.xCloser = fclose;
    }
    if (sCtx.in == 0) {
      fprintf(stderr, "Error: cannot open \"%s\"\n", zFile);
      goto meta_command_exit;
    }
    if (eVerbose >= 2 || (eVerbose >= 1 && useOutputMode)) {
      char zSep[2];
      zSep[1] = 0;
      zSep[0] = sCtx.cColSep;
      fprintf(p->out, "Column separator ");
      output_c_string(p->out, zSep);
      fprintf(p->out, ", row separator ");
      zSep[0] = sCtx.cRowSep;
      output_c_string(p->out, zSep);
      fprintf(p->out, "\n");
    }
    sCtx.z = sqlite3_malloc64(120);
    if (sCtx.z == 0) {
      import_cleanup(&sCtx);
      shell_out_of_memory();
    }
    while ((nSkip--) > 0) {
      while (xRead(&sCtx) && sCtx.cTerm == sCtx.cColSep) {
      }
    }
    if (zSchema != 0) {
      zFullTabName = sqlite3_mprintf("\"%w\".\"%w\"", zSchema, zTable);
    } else {
      zFullTabName = sqlite3_mprintf("\"%w\"", zTable);
    }
    zSql = sqlite3_mprintf("SELECT * FROM %s", zFullTabName);
    if (zSql == 0 || zFullTabName == 0) {
      import_cleanup(&sCtx);
      shell_out_of_memory();
    }
    nByte = strlen30(zSql);
    rc = sqlite3_prepare_v2(p->db, zSql, -1, &pStmt, 0);
    import_append_char(&sCtx, 0);
    if (rc && sqlite3_strglob("no such table: *", sqlite3_errmsg(p->db)) == 0) {
      sqlite3 *dbCols = 0;
      char *zRenames = 0;
      char *zColDefs;
      zCreate = sqlite3_mprintf("CREATE TABLE %s", zFullTabName);
      while (xRead(&sCtx)) {
        zAutoColumn(sCtx.z, &dbCols, 0);
        if (sCtx.cTerm != sCtx.cColSep)
          break;
      }
      zColDefs = zAutoColumn(0, &dbCols, &zRenames);
      if (zRenames != 0) {
        fprintf((stdin_is_interactive && p->in == stdin) ? p->out : stderr,
                "Columns renamed during .import %s due to duplicates:\n%s\n",
                sCtx.zFile, zRenames);
        sqlite3_free(zRenames);
      }
      ((void)sizeof((dbCols == 0) ? 1 : 0), ({
         if (dbCols == 0)
           ;
         else
           __assert_fail("dbCols==0", "shell.c", 24228, __PRETTY_FUNCTION__);
       }));
      if (zColDefs == 0) {
        fprintf(stderr, "%s: empty file\n", sCtx.zFile);
      import_fail:
        sqlite3_free(zCreate);
        sqlite3_free(zSql);
        sqlite3_free(zFullTabName);
        import_cleanup(&sCtx);
        rc = 1;
        goto meta_command_exit;
      }
      zCreate = sqlite3_mprintf("%z%z\n", zCreate, zColDefs);
      if (eVerbose >= 1) {
        fprintf(p->out, "%s\n", zCreate);
      }
      rc = sqlite3_exec(p->db, zCreate, 0, 0, 0);
      if (rc) {
        fprintf(stderr, "%s failed:\n%s\n", zCreate, sqlite3_errmsg(p->db));
        goto import_fail;
      }
      sqlite3_free(zCreate);
      zCreate = 0;
      rc = sqlite3_prepare_v2(p->db, zSql, -1, &pStmt, 0);
    }
    if (rc) {
      if (pStmt)
        sqlite3_finalize(pStmt);
      fprintf(stderr, "Error: %s\n", sqlite3_errmsg(p->db));
      goto import_fail;
    }
    sqlite3_free(zSql);
    nCol = sqlite3_column_count(pStmt);
    sqlite3_finalize(pStmt);
    pStmt = 0;
    if (nCol == 0)
      return 0;
    zSql = sqlite3_malloc64(nByte * 2 + 20 + nCol * 2);
    if (zSql == 0) {
      import_cleanup(&sCtx);
      shell_out_of_memory();
    }
    sqlite3_snprintf(nByte + 20, zSql, "INSERT INTO %s VALUES(?", zFullTabName);
    j = strlen30(zSql);
    for (i = 1; i < nCol; i++) {
      zSql[j++] = ',';
      zSql[j++] = '?';
    }
    zSql[j++] = ')';
    zSql[j] = 0;
    if (eVerbose >= 2) {
      fprintf(p->out, "Insert using: %s\n", zSql);
    }
    rc = sqlite3_prepare_v2(p->db, zSql, -1, &pStmt, 0);
    if (rc) {
      fprintf(stderr, "Error: %s\n", sqlite3_errmsg(p->db));
      if (pStmt)
        sqlite3_finalize(pStmt);
      goto import_fail;
    }
    sqlite3_free(zSql);
    sqlite3_free(zFullTabName);
    needCommit = sqlite3_get_autocommit(p->db);
    if (needCommit)
      sqlite3_exec(p->db, "BEGIN", 0, 0, 0);
    do {
      int startLine = sCtx.nLine;
      for (i = 0; i < nCol; i++) {
        char *z = xRead(&sCtx);
        if (z == 0 && i == 0)
          break;
        if (p->mode == 10 && (z == 0 || z[0] == 0) && i == 0)
          break;
        sqlite3_bind_text(pStmt, i + 1, z, -1, ((sqlite3_destructor_type)-1));
        if (i < nCol - 1 && sCtx.cTerm != sCtx.cColSep) {
          fprintf(stderr,
                  "%s:%d: expected %d columns but found %d - filling the rest "
                  "with NULL\n",
                  sCtx.zFile, startLine, nCol, i + 1);
          i += 2;
          while (i <= nCol) {
            sqlite3_bind_null(pStmt, i);
            i++;
          }
        }
      }
      if (sCtx.cTerm == sCtx.cColSep) {
        do {
          xRead(&sCtx);
          i++;
        } while (sCtx.cTerm == sCtx.cColSep);
        fprintf(stderr,
                "%s:%d: expected %d columns but found %d - extras ignored\n",
                sCtx.zFile, startLine, nCol, i);
      }
      if (i >= nCol) {
        sqlite3_step(pStmt);
        rc = sqlite3_reset(pStmt);
        if (rc != 0) {
          fprintf(stderr, "%s:%d: INSERT failed: %s\n", sCtx.zFile, startLine,
                  sqlite3_errmsg(p->db));
          sCtx.nErr++;
        } else {
          sCtx.nRow++;
        }
      }
    } while (sCtx.cTerm != (-1));
    import_cleanup(&sCtx);
    sqlite3_finalize(pStmt);
    if (needCommit)
      sqlite3_exec(p->db, "COMMIT", 0, 0, 0);
    if (eVerbose > 0) {
      fprintf(p->out, "Added %d rows with %d errors using %d lines of input\n",
              sCtx.nRow, sCtx.nErr, sCtx.nLine - 1);
    }
  } else if (c == 'i' && cli_strncmp(azArg[0], "imposter", n) == 0) {
    char *zSql;
    char *zCollist = 0;
    sqlite3_stmt *pStmt;
    int tnum = 0;
    int isWO = 0;
    int lenPK = 0;
    int i;
    if (!(((p)->shellFlgs & (1024)) != 0)) {
      fprintf(stderr, ".%s unavailable without --unsafe-testing\n", "imposter");
      rc = 1;
      goto meta_command_exit;
    }
    if (!(nArg == 3 || (nArg == 2 && sqlite3_stricmp(azArg[1], "off") == 0))) {
      fprintf(stderr,
              "Usage: .imposter INDEX IMPOSTER\n       .imposter off\n");
      rc = 1;
      goto meta_command_exit;
    }
    open_db(p, 0);
    if (nArg == 2) {
      sqlite3_test_control(25, p->db, "main", 0, 1);
      goto meta_command_exit;
    }
    zSql = sqlite3_mprintf(
        "SELECT rootpage, 0 FROM sqlite_schema WHERE name='%q' AND "
        "type='index'UNION ALL SELECT rootpage, 1 FROM sqlite_schema WHERE "
        "name='%q' AND type='table'   AND sql LIKE '%%without%%rowid%%'",
        azArg[1], azArg[1]);
    sqlite3_prepare_v2(p->db, zSql, -1, &pStmt, 0);
    sqlite3_free(zSql);
    if (sqlite3_step(pStmt) == 100) {
      tnum = sqlite3_column_int(pStmt, 0);
      isWO = sqlite3_column_int(pStmt, 1);
    }
    sqlite3_finalize(pStmt);
    zSql = sqlite3_mprintf("PRAGMA index_xinfo='%q'", azArg[1]);
    rc = sqlite3_prepare_v2(p->db, zSql, -1, &pStmt, 0);
    sqlite3_free(zSql);
    i = 0;
    while (rc == 0 && sqlite3_step(pStmt) == 100) {
      char zLabel[20];
      const char *zCol = (const char *)sqlite3_column_text(pStmt, 2);
      i++;
      if (zCol == 0) {
        if (sqlite3_column_int(pStmt, 1) == -1) {
          zCol = "_ROWID_";
        } else {
          sqlite3_snprintf(sizeof(zLabel), zLabel, "expr%d", i);
          zCol = zLabel;
        }
      }
      if (isWO && lenPK == 0 && sqlite3_column_int(pStmt, 5) == 0 && zCollist) {
        lenPK = (int)strlen(zCollist);
      }
      if (zCollist == 0) {
        zCollist = sqlite3_mprintf("\"%w\"", zCol);
      } else {
        zCollist = sqlite3_mprintf("%z,\"%w\"", zCollist, zCol);
      }
    }
    sqlite3_finalize(pStmt);
    if (i == 0 || tnum == 0) {
      fprintf(stderr, "no such index: \"%s\"\n", azArg[1]);
      rc = 1;
      sqlite3_free(zCollist);
      goto meta_command_exit;
    }
    if (lenPK == 0)
      lenPK = 100000;
    zSql = sqlite3_mprintf(
        "CREATE TABLE \"%w\"(%s,PRIMARY KEY(%.*s))WITHOUT ROWID", azArg[2],
        zCollist, lenPK, zCollist);
    sqlite3_free(zCollist);
    rc = sqlite3_test_control(25, p->db, "main", 1, tnum);
    if (rc == 0) {
      rc = sqlite3_exec(p->db, zSql, 0, 0, 0);
      sqlite3_test_control(25, p->db, "main", 0, 0);
      if (rc) {
        fprintf(stderr, "Error in [%s]: %s\n", zSql, sqlite3_errmsg(p->db));
      } else {
        fprintf(stdout, "%s;\n", zSql);
        fprintf(stdout,
                "WARNING: writing to an imposter table will corrupt the \"%s\" "
                "%s!\n",
                azArg[1], isWO ? "table" : "index");
      }
    } else {
      fprintf(stderr, "SQLITE_TESTCTRL_IMPOSTER returns %d\n", rc);
      rc = 1;
    }
    sqlite3_free(zSql);
  } else if (c == 'l' && n >= 5 && cli_strncmp(azArg[0], "limits", n) == 0) {
    static const struct {
      const char *zLimitName;
      int limitCode;
    } aLimit[] = {{"length", 0},
                  {"sql_length", 1},
                  {"column", 2},
                  {"expr_depth", 3},
                  {"compound_select", 4},
                  {"vdbe_op", 5},
                  {"function_arg", 6},
                  {"attached", 7},
                  {"like_pattern_length", 8},
                  {"variable_number", 9},
                  {"trigger_depth", 10},
                  {"worker_threads", 11}};
    int i, n2;
    open_db(p, 0);
    if (nArg == 1) {
      for (i = 0; i < (int)(sizeof(aLimit) / sizeof(aLimit[0])); i++) {
        printf("%20s %d\n", aLimit[i].zLimitName,
               sqlite3_limit(p->db, aLimit[i].limitCode, -1));
      }
    } else if (nArg > 3) {
      fprintf(stderr, "Usage: .limit NAME ?NEW-VALUE?\n");
      rc = 1;
      goto meta_command_exit;
    } else {
      int iLimit = -1;
      n2 = strlen30(azArg[1]);
      for (i = 0; i < (int)(sizeof(aLimit) / sizeof(aLimit[0])); i++) {
        if (sqlite3_strnicmp(aLimit[i].zLimitName, azArg[1], n2) == 0) {
          if (iLimit < 0) {
            iLimit = i;
          } else {
            fprintf(stderr, "ambiguous limit: \"%s\"\n", azArg[1]);
            rc = 1;
            goto meta_command_exit;
          }
        }
      }
      if (iLimit < 0) {
        fprintf(stderr,
                "unknown limit: \"%s\"\nenter \".limits\" with no arguments "
                "for a list.\n",
                azArg[1]);
        rc = 1;
        goto meta_command_exit;
      }
      if (nArg == 3) {
        sqlite3_limit(p->db, aLimit[iLimit].limitCode,
                      (int)integerValue(azArg[2]));
      }
      printf("%20s %d\n", aLimit[iLimit].zLimitName,
             sqlite3_limit(p->db, aLimit[iLimit].limitCode, -1));
    }
  } else if (c == 'l' && n > 2 && cli_strncmp(azArg[0], "lint", n) == 0) {
    open_db(p, 0);
    lintDotCommand(p, azArg, nArg);
  } else if (c == 'l' && cli_strncmp(azArg[0], "load", n) == 0) {
    const char *zFile, *zProc;
    char *zErrMsg = 0;
    failIfSafeMode(p, "cannot run .load in safe mode");
    if (nArg < 2 || azArg[1][0] == 0) {
      fprintf(stderr, "Usage: .load FILE ?ENTRYPOINT?\n");
      rc = 1;
      goto meta_command_exit;
    }
    zFile = azArg[1];
    zProc = nArg >= 3 ? azArg[2] : 0;
    open_db(p, 0);
    rc = sqlite3_load_extension(p->db, zFile, zProc, &zErrMsg);
    if (rc != 0) {
      fprintf(stderr, "Error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      rc = 1;
    }
  } else if (c == 'l' && cli_strncmp(azArg[0], "log", n) == 0) {
    if (nArg != 2) {
      fprintf(stderr, "Usage: .log FILENAME\n");
      rc = 1;
    } else {
      const char *zFile = azArg[1];
      if (p->bSafeMode && cli_strcmp(zFile, "on") != 0 &&
          cli_strcmp(zFile, "off") != 0) {
        fprintf(stdout,
                "cannot set .log to anything other than \"on\" or \"off\"\n");
        zFile = "off";
      }
      output_file_close(p->pLog);
      if (cli_strcmp(zFile, "on") == 0)
        zFile = "stdout";
      p->pLog = output_file_open(zFile, 0);
    }
  } else if (c == 'm' && cli_strncmp(azArg[0], "mode", n) == 0) {
    const char *zMode = 0;
    const char *zTabname = 0;
    int i, n2;
    ColModeOpts cmOpts = {60, 0, 0};
    for (i = 1; i < nArg; i++) {
      const char *z = azArg[i];
      if (optionMatch(z, "wrap") && i + 1 < nArg) {
        cmOpts.iWrap = integerValue(azArg[++i]);
      } else if (optionMatch(z, "ww")) {
        cmOpts.bWordWrap = 1;
      } else if (optionMatch(z, "wordwrap") && i + 1 < nArg) {
        cmOpts.bWordWrap = (u8)booleanValue(azArg[++i]);
      } else if (optionMatch(z, "quote")) {
        cmOpts.bQuote = 1;
      } else if (optionMatch(z, "noquote")) {
        cmOpts.bQuote = 0;
      } else if (zMode == 0) {
        zMode = z;
        if (cli_strcmp(z, "qbox") == 0) {
          ColModeOpts cmo = {60, 1, 0};
          zMode = "box";
          cmOpts = cmo;
        }
      } else if (zTabname == 0) {
        zTabname = z;
      } else if (z[0] == '-') {
        fprintf(stderr, "unknown option: %s\n", z);
        fprintf(stderr, "options:\n  --noquote\n  --quote\n  --wordwrap "
                        "on/off\n  --wrap N\n  --ww\n");
        rc = 1;
        goto meta_command_exit;
      } else {
        fprintf(stderr, "extra argument: \"%s\"\n", z);
        rc = 1;
        goto meta_command_exit;
      }
    }
    if (zMode == 0) {
      if (p->mode == 1 || (p->mode >= 14 && p->mode <= 16)) {
        fprintf(p->out,
                "current output mode: %s --wrap %d --wordwrap %s --%squote\n",
                modeDescr[p->mode], p->cmOpts.iWrap,
                p->cmOpts.bWordWrap ? "on" : "off",
                p->cmOpts.bQuote ? "" : "no");
      } else {
        fprintf(p->out, "current output mode: %s\n", modeDescr[p->mode]);
      }
      zMode = modeDescr[p->mode];
    }
    n2 = strlen30(zMode);
    if (cli_strncmp(zMode, "lines", n2) == 0) {
      p->mode = 0;
      sqlite3_snprintf(sizeof(p->rowSeparator), p->rowSeparator, "\n");
    } else if (cli_strncmp(zMode, "columns", n2) == 0) {
      p->mode = 1;
      if ((p->shellFlgs & 128) == 0) {
        p->showHeader = 1;
      }
      sqlite3_snprintf(sizeof(p->rowSeparator), p->rowSeparator, "\n");
      p->cmOpts = cmOpts;
    } else if (cli_strncmp(zMode, "list", n2) == 0) {
      p->mode = 2;
      sqlite3_snprintf(sizeof(p->colSeparator), p->colSeparator, "|");
      sqlite3_snprintf(sizeof(p->rowSeparator), p->rowSeparator, "\n");
    } else if (cli_strncmp(zMode, "html", n2) == 0) {
      p->mode = 4;
    } else if (cli_strncmp(zMode, "tcl", n2) == 0) {
      p->mode = 7;
      sqlite3_snprintf(sizeof(p->colSeparator), p->colSeparator, " ");
      sqlite3_snprintf(sizeof(p->rowSeparator), p->rowSeparator, "\n");
    } else if (cli_strncmp(zMode, "csv", n2) == 0) {
      p->mode = 8;
      sqlite3_snprintf(sizeof(p->colSeparator), p->colSeparator, ",");
      sqlite3_snprintf(sizeof(p->rowSeparator), p->rowSeparator, "\x0d\n");
    } else if (cli_strncmp(zMode, "tabs", n2) == 0) {
      p->mode = 2;
      sqlite3_snprintf(sizeof(p->colSeparator), p->colSeparator, "\t");
    } else if (cli_strncmp(zMode, "insert", n2) == 0) {
      p->mode = 5;
      set_table_name(p, zTabname ? zTabname : "table");
    } else if (cli_strncmp(zMode, "quote", n2) == 0) {
      p->mode = 6;
      sqlite3_snprintf(sizeof(p->colSeparator), p->colSeparator, ",");
      sqlite3_snprintf(sizeof(p->rowSeparator), p->rowSeparator, "\n");
    } else if (cli_strncmp(zMode, "ascii", n2) == 0) {
      p->mode = 10;
      sqlite3_snprintf(sizeof(p->colSeparator), p->colSeparator, "\x1f");
      sqlite3_snprintf(sizeof(p->rowSeparator), p->rowSeparator, "\x1e");
    } else if (cli_strncmp(zMode, "markdown", n2) == 0) {
      p->mode = 14;
      p->cmOpts = cmOpts;
    } else if (cli_strncmp(zMode, "table", n2) == 0) {
      p->mode = 15;
      p->cmOpts = cmOpts;
    } else if (cli_strncmp(zMode, "box", n2) == 0) {
      p->mode = 16;
      p->cmOpts = cmOpts;
    } else if (cli_strncmp(zMode, "count", n2) == 0) {
      p->mode = 17;
    } else if (cli_strncmp(zMode, "off", n2) == 0) {
      p->mode = 18;
    } else if (cli_strncmp(zMode, "json", n2) == 0) {
      p->mode = 13;
    } else {
      fprintf(stderr,
              "Error: mode should be one of: ascii box column csv html insert "
              "json line list markdown qbox quote table tabs tcl\n");
      rc = 1;
    }
    p->cMode = p->mode;
  } else if (c == 'n' && cli_strcmp(azArg[0], "nonce") == 0) {
    if (nArg != 2) {
      fprintf(stderr, "Usage: .nonce NONCE\n");
      rc = 1;
    } else if (p->zNonce == 0 || cli_strcmp(azArg[1], p->zNonce) != 0) {
      fprintf(stderr, "line %d: incorrect nonce: \"%s\"\n", p->lineno,
              azArg[1]);
      exit(1);
    } else {
      p->bSafeMode = 0;
      return 0;
    }
  } else if (c == 'n' && cli_strncmp(azArg[0], "nullvalue", n) == 0) {
    if (nArg == 2) {
      sqlite3_snprintf(
          sizeof(p->nullValue), p->nullValue, "%.*s",
          (int)(int)(sizeof(p->nullValue) / sizeof(p->nullValue[0])) - 1,
          azArg[1]);
    } else {
      fprintf(stderr, "Usage: .nullvalue STRING\n");
      rc = 1;
    }
  } else if (c == 'o' && cli_strncmp(azArg[0], "open", n) == 0 && n >= 2) {
    const char *zFN = 0;
    char *zNewFilename = 0;
    int iName = 1;
    int newFlag = 0;
    int openMode = 0;
    for (iName = 1; iName < nArg; iName++) {
      const char *z = azArg[iName];
      if (optionMatch(z, "new")) {
        newFlag = 1;
      } else if (optionMatch(z, "append")) {
        openMode = 2;
      } else if (optionMatch(z, "readonly")) {
        openMode = 4;
      } else if (optionMatch(z, "nofollow")) {
        p->openFlags |= 16777216;
      } else if (optionMatch(z, "deserialize")) {
        openMode = 5;
      } else if (optionMatch(z, "hexdb")) {
        openMode = 6;
      } else if (optionMatch(z, "maxsize") && iName + 1 < nArg) {
        p->szMax = integerValue(azArg[++iName]);
      } else if (z[0] == '-') {
        fprintf(stderr, "unknown option: %s\n", z);
        rc = 1;
        goto meta_command_exit;
      } else if (zFN) {
        fprintf(stderr, "extra argument: \"%s\"\n", z);
        rc = 1;
        goto meta_command_exit;
      } else {
        zFN = z;
      }
    };
    close_db(p->db);
    p->db = 0;
    p->pAuxDb->zDbFilename = 0;
    sqlite3_free(p->pAuxDb->zFreeOnClose);
    p->pAuxDb->zFreeOnClose = 0;
    p->openMode = openMode;
    p->openFlags = 0;
    p->szMax = 0;
    if (zFN || p->openMode == 6) {
      if (newFlag && zFN && !p->bSafeMode)
        shellDeleteFile(zFN);
      if (p->bSafeMode && p->openMode != 6 && zFN &&
          cli_strcmp(zFN, ":memory:") != 0) {
        failIfSafeMode(p, "cannot open disk-based database files in safe mode");
      }
      if (zFN) {
        zNewFilename = sqlite3_mprintf("%s", zFN);
        shell_check_oom(zNewFilename);
      } else {
        zNewFilename = 0;
      }
      p->pAuxDb->zDbFilename = zNewFilename;
      open_db(p, 1);
      if (p->db == 0) {
        fprintf(stderr, "Error: cannot open '%s'\n", zNewFilename);
        sqlite3_free(zNewFilename);
      } else {
        p->pAuxDb->zFreeOnClose = zNewFilename;
      }
    }
    if (p->db == 0) {
      p->pAuxDb->zDbFilename = 0;
      open_db(p, 0);
    }
  } else if ((c == 'o' && (cli_strncmp(azArg[0], "output", n) == 0 ||
                           cli_strncmp(azArg[0], "once", n) == 0)) ||
             (c == 'e' && n == 5 && cli_strcmp(azArg[0], "excel") == 0)) {
    char *zFile = 0;
    int bTxtMode = 0;
    int i;
    int eMode = 0;
    int bOnce = 0;
    unsigned char zBOM[4];
    zBOM[0] = 0;
    failIfSafeMode(p, "cannot run .%s in safe mode", azArg[0]);
    if (c == 'e') {
      eMode = 'x';
      bOnce = 2;
    } else if (cli_strncmp(azArg[0], "once", n) == 0) {
      bOnce = 1;
    }
    for (i = 1; i < nArg; i++) {
      char *z = azArg[i];
      if (z[0] == '-') {
        if (z[1] == '-')
          z++;
        if (cli_strcmp(z, "-bom") == 0) {
          zBOM[0] = 239;
          zBOM[1] = 187;
          zBOM[2] = 191;
          zBOM[3] = 0;
        } else if (c != 'e' && cli_strcmp(z, "-x") == 0) {
          eMode = 'x';
        } else if (c != 'e' && cli_strcmp(z, "-e") == 0) {
          eMode = 'e';
        } else {
          fprintf(p->out, "ERROR: unknown option: \"%s\".  Usage:\n", azArg[i]);
          showHelp(p->out, azArg[0]);
          rc = 1;
          goto meta_command_exit;
        }
      } else if (zFile == 0 && eMode != 'e' && eMode != 'x') {
        zFile = sqlite3_mprintf("%s", z);
        if (zFile && zFile[0] == '|') {
          while (i + 1 < nArg)
            zFile = sqlite3_mprintf("%z %s", zFile, azArg[++i]);
          break;
        }
      } else {
        fprintf(p->out, "ERROR: extra parameter: \"%s\".  Usage:\n", azArg[i]);
        showHelp(p->out, azArg[0]);
        rc = 1;
        sqlite3_free(zFile);
        goto meta_command_exit;
      }
    }
    if (zFile == 0) {
      zFile = sqlite3_mprintf("stdout");
    }
    if (bOnce) {
      p->outCount = 2;
    } else {
      p->outCount = 0;
    }
    output_reset(p);
    if (eMode == 'e' || eMode == 'x') {
      p->doXdgOpen = 1;
      outputModePush(p);
      if (eMode == 'x') {
        newTempFile(p, "csv");
        ((p)->shellFlgs &= (~(64)));
        p->mode = 8;
        sqlite3_snprintf(sizeof(p->colSeparator), p->colSeparator, ",");
        sqlite3_snprintf(sizeof(p->rowSeparator), p->rowSeparator, "\x0d\n");
      } else {
        newTempFile(p, "txt");
        bTxtMode = 1;
      }
      sqlite3_free(zFile);
      zFile = sqlite3_mprintf("%s", p->zTempFile);
    }
    shell_check_oom(zFile);
    if (zFile[0] == '|') {
      p->out = popen(zFile + 1, "w");
      if (p->out == 0) {
        fprintf(stderr, "Error: cannot open pipe \"%s\"\n", zFile + 1);
        p->out = stdout;
        rc = 1;
      } else {
        if (zBOM[0])
          fwrite(zBOM, 1, 3, p->out);
        sqlite3_snprintf(sizeof(p->outfile), p->outfile, "%s", zFile);
      }
    } else {
      p->out = output_file_open(zFile, bTxtMode);
      if (p->out == 0) {
        if (cli_strcmp(zFile, "off") != 0) {
          fprintf(stderr, "Error: cannot write to \"%s\"\n", zFile);
        }
        p->out = stdout;
        rc = 1;
      } else {
        if (zBOM[0])
          fwrite(zBOM, 1, 3, p->out);
        sqlite3_snprintf(sizeof(p->outfile), p->outfile, "%s", zFile);
      }
    }
    sqlite3_free(zFile);
  } else if (c == 'p' && n >= 3 && cli_strncmp(azArg[0], "parameter", n) == 0) {
    open_db(p, 0);
    if (nArg <= 1)
      goto parameter_syntax_error;
    if (nArg == 2 && cli_strcmp(azArg[1], "clear") == 0) {
      sqlite3_exec(p->db, "DROP TABLE IF EXISTS temp.sqlite_parameters;", 0, 0,
                   0);
    } else if (nArg == 2 && cli_strcmp(azArg[1], "list") == 0) {
      sqlite3_stmt *pStmt = 0;
      int rx;
      int len = 0;
      rx = sqlite3_prepare_v2(
          p->db, "SELECT max(length(key)) FROM temp.sqlite_parameters;", -1,
          &pStmt, 0);
      if (rx == 0 && sqlite3_step(pStmt) == 100) {
        len = sqlite3_column_int(pStmt, 0);
        if (len > 40)
          len = 40;
      }
      sqlite3_finalize(pStmt);
      pStmt = 0;
      if (len) {
        rx = sqlite3_prepare_v2(
            p->db, "SELECT key, quote(value) FROM temp.sqlite_parameters;", -1,
            &pStmt, 0);
        while (rx == 0 && sqlite3_step(pStmt) == 100) {
          fprintf(p->out, "%-*s %s\n", len, sqlite3_column_text(pStmt, 0),
                  sqlite3_column_text(pStmt, 1));
        }
        sqlite3_finalize(pStmt);
      }
    } else if (nArg == 2 && cli_strcmp(azArg[1], "init") == 0) {
      bind_table_init(p);
    } else if (nArg == 4 && cli_strcmp(azArg[1], "set") == 0) {
      int rx;
      char *zSql;
      sqlite3_stmt *pStmt;
      const char *zKey = azArg[2];
      const char *zValue = azArg[3];
      bind_table_init(p);
      zSql = sqlite3_mprintf(
          "REPLACE INTO temp.sqlite_parameters(key,value)VALUES(%Q,%s);", zKey,
          zValue);
      shell_check_oom(zSql);
      pStmt = 0;
      rx = sqlite3_prepare_v2(p->db, zSql, -1, &pStmt, 0);
      sqlite3_free(zSql);
      if (rx != 0) {
        sqlite3_finalize(pStmt);
        pStmt = 0;
        zSql = sqlite3_mprintf(
            "REPLACE INTO temp.sqlite_parameters(key,value)VALUES(%Q,%Q);",
            zKey, zValue);
        shell_check_oom(zSql);
        rx = sqlite3_prepare_v2(p->db, zSql, -1, &pStmt, 0);
        sqlite3_free(zSql);
        if (rx != 0) {
          fprintf(p->out, "Error: %s\n", sqlite3_errmsg(p->db));
          sqlite3_finalize(pStmt);
          pStmt = 0;
          rc = 1;
        }
      }
      sqlite3_step(pStmt);
      sqlite3_finalize(pStmt);
    } else if (nArg == 3 && cli_strcmp(azArg[1], "unset") == 0) {
      char *zSql = sqlite3_mprintf(
          "DELETE FROM temp.sqlite_parameters WHERE key=%Q", azArg[2]);
      shell_check_oom(zSql);
      sqlite3_exec(p->db, zSql, 0, 0, 0);
      sqlite3_free(zSql);
    } else
    parameter_syntax_error:
      showHelp(p->out, "parameter");
  } else if (c == 'p' && n >= 3 && cli_strncmp(azArg[0], "print", n) == 0) {
    int i;
    for (i = 1; i < nArg; i++) {
      if (i > 1)
        fprintf(p->out, " ");
      fprintf(p->out, "%s", azArg[i]);
    }
    fprintf(p->out, "\n");
  } else if (c == 'p' && n >= 3 && cli_strncmp(azArg[0], "progress", n) == 0) {
    int i;
    int nn = 0;
    p->flgProgress = 0;
    p->mxProgress = 0;
    p->nProgress = 0;
    for (i = 1; i < nArg; i++) {
      const char *z = azArg[i];
      if (z[0] == '-') {
        z++;
        if (z[0] == '-')
          z++;
        if (cli_strcmp(z, "quiet") == 0 || cli_strcmp(z, "q") == 0) {
          p->flgProgress |= 1;
          continue;
        }
        if (cli_strcmp(z, "reset") == 0) {
          p->flgProgress |= 2;
          continue;
        }
        if (cli_strcmp(z, "once") == 0) {
          p->flgProgress |= 4;
          continue;
        }
        if (cli_strcmp(z, "limit") == 0) {
          if (i + 1 >= nArg) {
            fprintf(stderr, "Error: missing argument on --limit\n");
            rc = 1;
            goto meta_command_exit;
          } else {
            p->mxProgress = (int)integerValue(azArg[++i]);
          }
          continue;
        }
        fprintf(stderr, "Error: unknown option: \"%s\"\n", azArg[i]);
        rc = 1;
        goto meta_command_exit;
      } else {
        nn = (int)integerValue(z);
      }
    }
    open_db(p, 0);
    sqlite3_progress_handler(p->db, nn, progress_handler, p);
  } else if (c == 'p' && cli_strncmp(azArg[0], "prompt", n) == 0) {
    if (nArg >= 2) {
      shell_strncpy(mainPrompt, azArg[1],
                    (int)(int)(sizeof(mainPrompt) / sizeof(mainPrompt[0])) - 1);
    }
    if (nArg >= 3) {
      shell_strncpy(
          continuePrompt, azArg[2],
          (int)(int)(sizeof(continuePrompt) / sizeof(continuePrompt[0])) - 1);
    }
  } else if (c == 'q' && cli_strncmp(azArg[0], "quit", n) == 0) {
    rc = 2;
  } else if (c == 'r' && n >= 3 && cli_strncmp(azArg[0], "read", n) == 0) {
    FILE *inSaved = p->in;
    int savedLineno = p->lineno;
    failIfSafeMode(p, "cannot run .read in safe mode");
    if (nArg != 2) {
      fprintf(stderr, "Usage: .read FILE\n");
      rc = 1;
      goto meta_command_exit;
    }
    if (azArg[1][0] == '|') {
      p->in = popen(azArg[1] + 1, "r");
      if (p->in == 0) {
        fprintf(stderr, "Error: cannot open \"%s\"\n", azArg[1]);
        rc = 1;
      } else {
        rc = process_input(p);
        pclose(p->in);
      }
    } else if ((p->in = openChrSource(azArg[1])) == 0) {
      fprintf(stderr, "Error: cannot open \"%s\"\n", azArg[1]);
      rc = 1;
    } else {
      rc = process_input(p);
      fclose(p->in);
    }
    p->in = inSaved;
    p->lineno = savedLineno;
  } else if (c == 'r' && n >= 3 && cli_strncmp(azArg[0], "restore", n) == 0) {
    const char *zSrcFile;
    const char *zDb;
    sqlite3 *pSrc;
    sqlite3_backup *pBackup;
    int nTimeout = 0;
    failIfSafeMode(p, "cannot run .restore in safe mode");
    if (nArg == 2) {
      zSrcFile = azArg[1];
      zDb = "main";
    } else if (nArg == 3) {
      zSrcFile = azArg[2];
      zDb = azArg[1];
    } else {
      fprintf(stderr, "Usage: .restore ?DB? FILE\n");
      rc = 1;
      goto meta_command_exit;
    }
    rc = sqlite3_open(zSrcFile, &pSrc);
    if (rc != 0) {
      fprintf(stderr, "Error: cannot open \"%s\"\n", zSrcFile);
      close_db(pSrc);
      return 1;
    }
    open_db(p, 0);
    pBackup = sqlite3_backup_init(p->db, zDb, pSrc, "main");
    if (pBackup == 0) {
      fprintf(stderr, "Error: %s\n", sqlite3_errmsg(p->db));
      close_db(pSrc);
      return 1;
    }
    while ((rc = sqlite3_backup_step(pBackup, 100)) == 0 || rc == 5) {
      if (rc == 5) {
        if (nTimeout++ >= 3)
          break;
        sqlite3_sleep(100);
      }
    }
    sqlite3_backup_finish(pBackup);
    if (rc == 101) {
      rc = 0;
    } else if (rc == 5 || rc == 6) {
      fprintf(stderr, "Error: source database is busy\n");
      rc = 1;
    } else {
      fprintf(stderr, "Error: %s\n", sqlite3_errmsg(p->db));
      rc = 1;
    }
    close_db(pSrc);
  } else if (c == 's' && cli_strncmp(azArg[0], "scanstats", n) == 0) {
    if (nArg == 2) {
      if (cli_strcmp(azArg[1], "est") == 0) {
        p->scanstatsOn = 2;
      } else {
        p->scanstatsOn = (u8)booleanValue(azArg[1]);
      }
      open_db(p, 0);
      sqlite3_db_config(p->db, 1018, p->scanstatsOn, (int *)0);
      fprintf(stderr, "Warning: .scanstats not available in this build.\n");
    } else {
      fprintf(stderr, "Usage: .scanstats on|off|est\n");
      rc = 1;
    }
  } else if (c == 's' && cli_strncmp(azArg[0], "schema", n) == 0) {
    ShellText sSelect;
    ShellState data;
    char *zErrMsg = 0;
    const char *zDiv = "(";
    const char *zName = 0;
    int iSchema = 0;
    int bDebug = 0;
    int bNoSystemTabs = 0;
    int ii;
    open_db(p, 0);
    memcpy(&data, p, sizeof(data));
    data.showHeader = 0;
    data.cMode = data.mode = 3;
    initText(&sSelect);
    for (ii = 1; ii < nArg; ii++) {
      if (optionMatch(azArg[ii], "indent")) {
        data.cMode = data.mode = 11;
      } else if (optionMatch(azArg[ii], "debug")) {
        bDebug = 1;
      } else if (optionMatch(azArg[ii], "nosys")) {
        bNoSystemTabs = 1;
      } else if (azArg[ii][0] == '-') {
        fprintf(stderr, "Unknown option: \"%s\"\n", azArg[ii]);
        rc = 1;
        goto meta_command_exit;
      } else if (zName == 0) {
        zName = azArg[ii];
      } else {
        fprintf(stderr, "Usage: .schema ?--indent? ?--nosys? ?LIKE-PATTERN?\n");
        rc = 1;
        goto meta_command_exit;
      }
    }
    if (zName != 0) {
      int isSchema = sqlite3_strlike(zName, "sqlite_master", '\\') == 0 ||
                     sqlite3_strlike(zName, "sqlite_schema", '\\') == 0 ||
                     sqlite3_strlike(zName, "sqlite_temp_master", '\\') == 0 ||
                     sqlite3_strlike(zName, "sqlite_temp_schema", '\\') == 0;
      if (isSchema) {
        char *new_argv[2], *new_colv[2];
        new_argv[0] = sqlite3_mprintf(
            "CREATE TABLE %s (\n  type text,\n  name text,\n  tbl_name text,\n "
            " rootpage integer,\n  sql text\n)",
            zName);
        shell_check_oom(new_argv[0]);
        new_argv[1] = 0;
        new_colv[0] = "sql";
        new_colv[1] = 0;
        callback(&data, 1, new_argv, new_colv);
        sqlite3_free(new_argv[0]);
      }
    }
    if (zDiv) {
      sqlite3_stmt *pStmt = 0;
      rc = sqlite3_prepare_v2(p->db, "SELECT name FROM pragma_database_list",
                              -1, &pStmt, 0);
      if (rc) {
        fprintf(stderr, "Error: %s\n", sqlite3_errmsg(p->db));
        sqlite3_finalize(pStmt);
        rc = 1;
        goto meta_command_exit;
      }
      appendText(&sSelect, "SELECT sql FROM", 0);
      iSchema = 0;
      while (sqlite3_step(pStmt) == 100) {
        const char *zDb = (const char *)sqlite3_column_text(pStmt, 0);
        char zScNum[30];
        sqlite3_snprintf(sizeof(zScNum), zScNum, "%d", ++iSchema);
        appendText(&sSelect, zDiv, 0);
        zDiv = " UNION ALL ";
        appendText(&sSelect, "SELECT shell_add_schema(sql,", 0);
        if (sqlite3_stricmp(zDb, "main") != 0) {
          appendText(&sSelect, zDb, '\'');
        } else {
          appendText(&sSelect, "NULL", 0);
        }
        appendText(&sSelect, ",name) AS sql, type, tbl_name, name, rowid,", 0);
        appendText(&sSelect, zScNum, 0);
        appendText(&sSelect, " AS snum, ", 0);
        appendText(&sSelect, zDb, '\'');
        appendText(&sSelect, " AS sname FROM ", 0);
        appendText(&sSelect, zDb, quoteChar(zDb));
        appendText(&sSelect, ".sqlite_schema", 0);
      }
      sqlite3_finalize(pStmt);
      if (zName) {
        appendText(&sSelect,
                   " UNION ALL SELECT shell_module_schema(name), 'table', "
                   "name, name, name, 9e+99, 'main' FROM pragma_module_list",
                   0);
      }
      appendText(&sSelect, ") WHERE ", 0);
      if (zName) {
        char *zQarg = sqlite3_mprintf("%Q", zName);
        int bGlob;
        shell_check_oom(zQarg);
        bGlob = strchr(zName, '*') != 0 || strchr(zName, '?') != 0 ||
                strchr(zName, '[') != 0;
        if (strchr(zName, '.')) {
          appendText(&sSelect, "lower(printf('%s.%s',sname,tbl_name))", 0);
        } else {
          appendText(&sSelect, "lower(tbl_name)", 0);
        }
        appendText(&sSelect, bGlob ? " GLOB " : " LIKE ", 0);
        appendText(&sSelect, zQarg, 0);
        if (!bGlob) {
          appendText(&sSelect, " ESCAPE '\\' ", 0);
        }
        appendText(&sSelect, " AND ", 0);
        sqlite3_free(zQarg);
      }
      if (bNoSystemTabs) {
        appendText(&sSelect, "name NOT LIKE 'sqlite_%%' AND ", 0);
      }
      appendText(&sSelect, "sql IS NOT NULL ORDER BY snum, rowid", 0);
      if (bDebug) {
        fprintf(p->out, "SQL: %s;\n", sSelect.z);
      } else {
        rc = sqlite3_exec(p->db, sSelect.z, callback, &data, &zErrMsg);
      }
      freeText(&sSelect);
    }
    if (zErrMsg) {
      fprintf(stderr, "Error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      rc = 1;
    } else if (rc != 0) {
      fprintf(stderr, "Error: querying schema information\n");
      rc = 1;
    } else {
      rc = 0;
    }
  } else if ((c == 's' && n == 11 &&
              cli_strncmp(azArg[0], "selecttrace", n) == 0) ||
             (c == 't' && n == 9 &&
              cli_strncmp(azArg[0], "treetrace", n) == 0)) {
    unsigned int x =
        nArg >= 2 ? (unsigned int)integerValue(azArg[1]) : 4294967295;
    sqlite3_test_control(31, 1, &x);
  } else if (c == 's' && n >= 4 && cli_strncmp(azArg[0], "selftest", n) == 0) {
    int bIsInit = 0;
    int bVerbose = 0;
    int bSelftestExists;
    int i, k;
    int nTest = 0;
    int nErr = 0;
    ShellText str;
    sqlite3_stmt *pStmt = 0;
    open_db(p, 0);
    for (i = 1; i < nArg; i++) {
      const char *z = azArg[i];
      if (z[0] == '-' && z[1] == '-')
        z++;
      if (cli_strcmp(z, "-init") == 0) {
        bIsInit = 1;
      } else if (cli_strcmp(z, "-v") == 0) {
        bVerbose++;
      } else {
        fprintf(stderr, "Unknown option \"%s\" on \"%s\"\n", azArg[i],
                azArg[0]);
        fprintf(stderr, "Should be one of: --init -v\n");
        rc = 1;
        goto meta_command_exit;
      }
    }
    if (sqlite3_table_column_metadata(p->db, "main", "selftest", 0, 0, 0, 0, 0,
                                      0) != 0) {
      bSelftestExists = 0;
    } else {
      bSelftestExists = 1;
    }
    if (bIsInit) {
      createSelftestTable(p);
      bSelftestExists = 1;
    }
    initText(&str);
    appendText(&str, "x", 0);
    for (k = bSelftestExists; k >= 0; k--) {
      if (k == 1) {
        rc = sqlite3_prepare_v2(
            p->db, "SELECT tno,op,cmd,ans FROM selftest ORDER BY tno", -1,
            &pStmt, 0);
      } else {
        rc = sqlite3_prepare_v2(
            p->db,
            "VALUES(0,'memo','Missing SELFTEST table - default checks "
            "only',''),      (1,'run','PRAGMA integrity_check','ok')",
            -1, &pStmt, 0);
      }
      if (rc) {
        fprintf(stderr, "Error querying the selftest table\n");
        rc = 1;
        sqlite3_finalize(pStmt);
        goto meta_command_exit;
      }
      for (i = 1; sqlite3_step(pStmt) == 100; i++) {
        int tno = sqlite3_column_int(pStmt, 0);
        const char *zOp = (const char *)sqlite3_column_text(pStmt, 1);
        const char *zSql = (const char *)sqlite3_column_text(pStmt, 2);
        const char *zAns = (const char *)sqlite3_column_text(pStmt, 3);
        if (zOp == 0)
          continue;
        if (zSql == 0)
          continue;
        if (zAns == 0)
          continue;
        k = 0;
        if (bVerbose > 0) {
          printf("%d: %s %s\n", tno, zOp, zSql);
        }
        if (cli_strcmp(zOp, "memo") == 0) {
          fprintf(p->out, "%s\n", zSql);
        } else if (cli_strcmp(zOp, "run") == 0) {
          char *zErrMsg = 0;
          str.n = 0;
          str.z[0] = 0;
          rc = sqlite3_exec(p->db, zSql, captureOutputCallback, &str, &zErrMsg);
          nTest++;
          if (bVerbose) {
            fprintf(p->out, "Result: %s\n", str.z);
          }
          if (rc || zErrMsg) {
            nErr++;
            rc = 1;
            fprintf(p->out, "%d: error-code-%d: %s\n", tno, rc, zErrMsg);
            sqlite3_free(zErrMsg);
          } else if (cli_strcmp(zAns, str.z) != 0) {
            nErr++;
            rc = 1;
            fprintf(p->out, "%d: Expected: [%s]\n", tno, zAns);
            fprintf(p->out, "%d:      Got: [%s]\n", tno, str.z);
          }
        } else {
          fprintf(stderr, "Unknown operation \"%s\" on selftest line %d\n", zOp,
                  tno);
          rc = 1;
          break;
        }
      }
      sqlite3_finalize(pStmt);
    }
    freeText(&str);
    fprintf(p->out, "%d errors out of %d tests\n", nErr, nTest);
  } else if (c == 's' && cli_strncmp(azArg[0], "separator", n) == 0) {
    if (nArg < 2 || nArg > 3) {
      fprintf(stderr, "Usage: .separator COL ?ROW?\n");
      rc = 1;
    }
    if (nArg >= 2) {
      sqlite3_snprintf(
          sizeof(p->colSeparator), p->colSeparator, "%.*s",
          (int)(int)(sizeof(p->colSeparator) / sizeof(p->colSeparator[0])) - 1,
          azArg[1]);
    }
    if (nArg >= 3) {
      sqlite3_snprintf(
          sizeof(p->rowSeparator), p->rowSeparator, "%.*s",
          (int)(int)(sizeof(p->rowSeparator) / sizeof(p->rowSeparator[0])) - 1,
          azArg[2]);
    }
  } else if (c == 's' && n >= 4 && cli_strncmp(azArg[0], "sha3sum", n) == 0) {
    const char *zLike = 0;
    int i;
    int bSchema = 0;
    int bSeparate = 0;
    int iSize = 224;
    int bDebug = 0;
    sqlite3_stmt *pStmt;
    char *zSql;
    char *zSep;
    ShellText sSql;
    ShellText sQuery;
    open_db(p, 0);
    for (i = 1; i < nArg; i++) {
      const char *z = azArg[i];
      if (z[0] == '-') {
        z++;
        if (z[0] == '-')
          z++;
        if (cli_strcmp(z, "schema") == 0) {
          bSchema = 1;
        } else if (cli_strcmp(z, "sha3-224") == 0 ||
                   cli_strcmp(z, "sha3-256") == 0 ||
                   cli_strcmp(z, "sha3-384") == 0 ||
                   cli_strcmp(z, "sha3-512") == 0) {
          iSize = atoi(&z[5]);
        } else if (cli_strcmp(z, "debug") == 0) {
          bDebug = 1;
        } else {
          fprintf(stderr, "Unknown option \"%s\" on \"%s\"\n", azArg[i],
                  azArg[0]);
          showHelp(p->out, azArg[0]);
          rc = 1;
          goto meta_command_exit;
        }
      } else if (zLike) {
        fprintf(stderr, "Usage: .sha3sum ?OPTIONS? ?LIKE-PATTERN?\n");
        rc = 1;
        goto meta_command_exit;
      } else {
        zLike = z;
        bSeparate = 1;
        if (sqlite3_strlike("sqlite\\_%", zLike, '\\') == 0)
          bSchema = 1;
      }
    }
    if (bSchema) {
      zSql = "SELECT lower(name) as tname FROM sqlite_schema WHERE "
             "type='table' AND coalesce(rootpage,0)>1 UNION ALL SELECT "
             "'sqlite_schema' ORDER BY 1 collate nocase";
    } else {
      zSql = "SELECT lower(name) as tname FROM sqlite_schema WHERE "
             "type='table' AND coalesce(rootpage,0)>1 AND name NOT LIKE "
             "'sqlite_%' ORDER BY 1 collate nocase";
    }
    sqlite3_prepare_v2(p->db, zSql, -1, &pStmt, 0);
    initText(&sQuery);
    initText(&sSql);
    appendText(&sSql, "WITH [sha3sum$query](a,b) AS(", 0);
    zSep = "VALUES(";
    while (100 == sqlite3_step(pStmt)) {
      const char *zTab = (const char *)sqlite3_column_text(pStmt, 0);
      if (zTab == 0)
        continue;
      if (zLike && sqlite3_strlike(zLike, zTab, 0) != 0)
        continue;
      if (cli_strncmp(zTab, "sqlite_", 7) != 0) {
        appendText(&sQuery, "SELECT * FROM ", 0);
        appendText(&sQuery, zTab, '\"');
        appendText(&sQuery, " NOT INDEXED;", 0);
      } else if (cli_strcmp(zTab, "sqlite_schema") == 0) {
        appendText(
            &sQuery,
            "SELECT type,name,tbl_name,sql FROM sqlite_schema ORDER BY name;",
            0);
      } else if (cli_strcmp(zTab, "sqlite_sequence") == 0) {
        appendText(&sQuery,
                   "SELECT name,seq FROM sqlite_sequence ORDER BY name;", 0);
      } else if (cli_strcmp(zTab, "sqlite_stat1") == 0) {
        appendText(&sQuery,
                   "SELECT tbl,idx,stat FROM sqlite_stat1 ORDER BY tbl,idx;",
                   0);
      } else if (cli_strcmp(zTab, "sqlite_stat4") == 0) {
        appendText(&sQuery, "SELECT * FROM ", 0);
        appendText(&sQuery, zTab, 0);
        appendText(&sQuery, " ORDER BY tbl, idx, rowid;\n", 0);
      }
      appendText(&sSql, zSep, 0);
      appendText(&sSql, sQuery.z, '\'');
      sQuery.n = 0;
      appendText(&sSql, ",", 0);
      appendText(&sSql, zTab, '\'');
      zSep = "),(";
    }
    sqlite3_finalize(pStmt);
    if (bSeparate) {
      zSql = sqlite3_mprintf("%s)) SELECT lower(hex(sha3_query(a,%d))) AS "
                             "hash, b AS label   FROM [sha3sum$query]",
                             sSql.z, iSize);
    } else {
      zSql = sqlite3_mprintf(
          "%s)) SELECT lower(hex(sha3_query(group_concat(a,''),%d))) AS hash   "
          "FROM [sha3sum$query]",
          sSql.z, iSize);
    }
    shell_check_oom(zSql);
    freeText(&sQuery);
    freeText(&sSql);
    if (bDebug) {
      fprintf(p->out, "%s\n", zSql);
    } else {
      shell_exec(p, zSql, 0);
    }
    {
      int lrc;
      char *zRevText = "SELECT lower(name) as tname FROM sqlite_schema\nWHERE "
                       "type='table' AND coalesce(rootpage,0)>1\nAND name NOT "
                       "LIKE 'sqlite_%%'%s\nORDER BY 1 collate nocase";
      zRevText =
          sqlite3_mprintf(zRevText, zLike ? " AND name LIKE $tspec" : "");
      zRevText = sqlite3_mprintf(
          "with tabcols as materialized(\nselect tname, cname\nfrom ( select "
          "ss.tname as tname, ti.name as cname\n from (%z) ss\n inner join "
          "pragma_table_info(tname) ti))\nselect 'SELECT total(bad_text_count) "
          "AS bad_text_count\nFROM ('||group_concat(query, ' UNION ALL ')||')' "
          "as btc_query\n from (select 'SELECT COUNT(*) AS "
          "bad_text_count\nFROM '||tname||' WHERE "
          "'\n||group_concat('CAST(CAST('||cname||' AS BLOB) AS "
          "TEXT)<>'||cname\n|| ' AND typeof('||cname||')=''text'' ',\n' OR ') "
          "as query, tname from tabcols group by tname)",
          zRevText);
      shell_check_oom(zRevText);
      if (bDebug)
        fprintf(p->out, "%s\n", zRevText);
      lrc = sqlite3_prepare_v2(p->db, zRevText, -1, &pStmt, 0);
      if (lrc != 0) {
        rc = 1;
      } else {
        if (zLike)
          sqlite3_bind_text(pStmt, 1, zLike, -1, ((sqlite3_destructor_type)0));
        lrc = 100 == sqlite3_step(pStmt);
        if (lrc) {
          const char *zGenQuery = (char *)sqlite3_column_text(pStmt, 0);
          sqlite3_stmt *pCheckStmt;
          lrc = sqlite3_prepare_v2(p->db, zGenQuery, -1, &pCheckStmt, 0);
          if (bDebug)
            fprintf(p->out, "%s\n", zGenQuery);
          if (lrc != 0) {
            rc = 1;
          } else {
            if (100 == sqlite3_step(pCheckStmt)) {
              double countIrreversible = sqlite3_column_double(pCheckStmt, 0);
              if (countIrreversible > 0) {
                int sz = (int)(countIrreversible + 0.500000);
                fprintf(stderr,
                        "Digest includes %d invalidly encoded text field%s.\n",
                        sz, (sz > 1) ? "s" : "");
              }
            }
            sqlite3_finalize(pCheckStmt);
          }
          sqlite3_finalize(pStmt);
        }
      }
      if (rc)
        fprintf(stderr, ".sha3sum failed.\n");
      sqlite3_free(zRevText);
    }
    sqlite3_free(zSql);
  } else if (c == 's' && (cli_strncmp(azArg[0], "shell", n) == 0 ||
                          cli_strncmp(azArg[0], "system", n) == 0)) {
    char *zCmd;
    int i, x;
    failIfSafeMode(p, "cannot run .%s in safe mode", azArg[0]);
    if (nArg < 2) {
      fprintf(stderr, "Usage: .system COMMAND\n");
      rc = 1;
      goto meta_command_exit;
    }
    zCmd =
        sqlite3_mprintf(strchr(azArg[1], ' ') == 0 ? "%s" : "\"%s\"", azArg[1]);
    for (i = 2; i < nArg && zCmd != 0; i++) {
      zCmd = sqlite3_mprintf(strchr(azArg[i], ' ') == 0 ? "%z %s" : "%z \"%s\"",
                             zCmd, azArg[i]);
    }
    x = zCmd != 0 ? system(zCmd) : 1;
    sqlite3_free(zCmd);
    if (x)
      fprintf(stderr, "System command returns %d\n", x);
  } else if (c == 's' && cli_strncmp(azArg[0], "show", n) == 0) {
    static const char *azBool[] = {"off", "on", "trigger", "full"};
    const char *zOut;
    int i;
    if (nArg != 1) {
      fprintf(stderr, "Usage: .show\n");
      rc = 1;
      goto meta_command_exit;
    }
    fprintf(p->out, "%12.12s: %s\n", "echo",
            azBool[(((p)->shellFlgs & (64)) != 0)]);
    fprintf(p->out, "%12.12s: %s\n", "eqp", azBool[p->autoEQP & 3]);
    fprintf(p->out, "%12.12s: %s\n", "explain",
            p->mode == 9     ? "on"
            : p->autoExplain ? "auto"
                             : "off");
    fprintf(p->out, "%12.12s: %s\n", "headers", azBool[p->showHeader != 0]);
    if (p->mode == 1 || (p->mode >= 14 && p->mode <= 16)) {
      fprintf(p->out, "%12.12s: %s --wrap %d --wordwrap %s --%squote\n", "mode",
              modeDescr[p->mode], p->cmOpts.iWrap,
              p->cmOpts.bWordWrap ? "on" : "off", p->cmOpts.bQuote ? "" : "no");
    } else {
      fprintf(p->out, "%12.12s: %s\n", "mode", modeDescr[p->mode]);
    }
    fprintf(p->out, "%12.12s: ", "nullvalue");
    output_c_string(p->out, p->nullValue);
    fprintf(p->out, "\n");
    fprintf(p->out, "%12.12s: %s\n", "output",
            strlen30(p->outfile) ? p->outfile : "stdout");
    fprintf(p->out, "%12.12s: ", "colseparator");
    output_c_string(p->out, p->colSeparator);
    fprintf(p->out, "\n");
    fprintf(p->out, "%12.12s: ", "rowseparator");
    output_c_string(p->out, p->rowSeparator);
    fprintf(p->out, "\n");
    switch (p->statsOn) {
    case 0:
      zOut = "off";
      break;
    default:
      zOut = "on";
      break;
    case 2:
      zOut = "stmt";
      break;
    case 3:
      zOut = "vmstep";
      break;
    }
    fprintf(p->out, "%12.12s: %s\n", "stats", zOut);
    fprintf(p->out, "%12.12s: ", "width");
    for (i = 0; i < p->nWidth; i++) {
      fprintf(p->out, "%d ", p->colWidth[i]);
    }
    fprintf(p->out, "\n");
    fprintf(p->out, "%12.12s: %s\n", "filename",
            p->pAuxDb->zDbFilename ? p->pAuxDb->zDbFilename : "");
  } else if (c == 's' && cli_strncmp(azArg[0], "stats", n) == 0) {
    if (nArg == 2) {
      if (cli_strcmp(azArg[1], "stmt") == 0) {
        p->statsOn = 2;
      } else if (cli_strcmp(azArg[1], "vmstep") == 0) {
        p->statsOn = 3;
      } else {
        p->statsOn = (u8)booleanValue(azArg[1]);
      }
    } else if (nArg == 1) {
      display_stats(p->db, p, 0);
    } else {
      fprintf(stderr, "Usage: .stats ?on|off|stmt|vmstep?\n");
      rc = 1;
    }
  } else if ((c == 't' && n > 1 && cli_strncmp(azArg[0], "tables", n) == 0) ||
             (c == 'i' && (cli_strncmp(azArg[0], "indices", n) == 0 ||
                           cli_strncmp(azArg[0], "indexes", n) == 0))) {
    sqlite3_stmt *pStmt;
    char **azResult;
    int nRow, nAlloc;
    int ii;
    ShellText s;
    initText(&s);
    open_db(p, 0);
    rc = sqlite3_prepare_v2(p->db, "PRAGMA database_list", -1, &pStmt, 0);
    if (rc) {
      sqlite3_finalize(pStmt);
      return shellDatabaseError(p->db);
    }
    if (nArg > 2 && c == 'i') {
      fprintf(stderr, "Usage: .indexes ?LIKE-PATTERN?\n");
      rc = 1;
      sqlite3_finalize(pStmt);
      goto meta_command_exit;
    }
    for (ii = 0; sqlite3_step(pStmt) == 100; ii++) {
      const char *zDbName = (const char *)sqlite3_column_text(pStmt, 1);
      if (zDbName == 0)
        continue;
      if (s.z && s.z[0])
        appendText(&s, " UNION ALL ", 0);
      if (sqlite3_stricmp(zDbName, "main") == 0) {
        appendText(&s, "SELECT name FROM ", 0);
      } else {
        appendText(&s, "SELECT ", 0);
        appendText(&s, zDbName, '\'');
        appendText(&s, "||'.'||name FROM ", 0);
      }
      appendText(&s, zDbName, '\"');
      appendText(&s, ".sqlite_schema ", 0);
      if (c == 't') {
        appendText(&s,
                   " WHERE type IN ('table','view')   AND name NOT LIKE "
                   "'sqlite_%'   AND name LIKE ?1",
                   0);
      } else {
        appendText(&s, " WHERE type='index'   AND tbl_name LIKE ?1", 0);
      }
    }
    rc = sqlite3_finalize(pStmt);
    if (rc == 0) {
      appendText(&s, " ORDER BY 1", 0);
      rc = sqlite3_prepare_v2(p->db, s.z, -1, &pStmt, 0);
    }
    freeText(&s);
    if (rc)
      return shellDatabaseError(p->db);
    nRow = nAlloc = 0;
    azResult = 0;
    if (nArg > 1) {
      sqlite3_bind_text(pStmt, 1, azArg[1], -1, ((sqlite3_destructor_type)-1));
    } else {
      sqlite3_bind_text(pStmt, 1, "%", -1, ((sqlite3_destructor_type)0));
    }
    while (sqlite3_step(pStmt) == 100) {
      if (nRow >= nAlloc) {
        char **azNew;
        int n2 = nAlloc * 2 + 10;
        azNew = sqlite3_realloc64(azResult, sizeof(azResult[0]) * n2);
        shell_check_oom(azNew);
        nAlloc = n2;
        azResult = azNew;
      }
      azResult[nRow] = sqlite3_mprintf("%s", sqlite3_column_text(pStmt, 0));
      shell_check_oom(azResult[nRow]);
      nRow++;
    }
    if (sqlite3_finalize(pStmt) != 0) {
      rc = shellDatabaseError(p->db);
    }
    if (rc == 0 && nRow > 0) {
      int len, maxlen = 0;
      int i, j;
      int nPrintCol, nPrintRow;
      for (i = 0; i < nRow; i++) {
        len = strlen30(azResult[i]);
        if (len > maxlen)
          maxlen = len;
      }
      nPrintCol = 80 / (maxlen + 2);
      if (nPrintCol < 1)
        nPrintCol = 1;
      nPrintRow = (nRow + nPrintCol - 1) / nPrintCol;
      for (i = 0; i < nPrintRow; i++) {
        for (j = i; j < nRow; j += nPrintRow) {
          char *zSp = j < nPrintRow ? "" : "  ";
          fprintf(p->out, "%s%-*s", zSp, maxlen,
                  azResult[j] ? azResult[j] : "");
        }
        fprintf(p->out, "\n");
      }
    }
    for (ii = 0; ii < nRow; ii++)
      sqlite3_free(azResult[ii]);
    sqlite3_free(azResult);
  } else if (c == 't' && cli_strcmp(azArg[0], "testcase") == 0) {
    output_reset(p);
    p->out = output_file_open("testcase-out.txt", 0);
    if (p->out == 0) {
      fprintf(stderr, "Error: cannot open 'testcase-out.txt'\n");
    }
    if (nArg >= 2) {
      sqlite3_snprintf(sizeof(p->zTestcase), p->zTestcase, "%s", azArg[1]);
    } else {
      sqlite3_snprintf(sizeof(p->zTestcase), p->zTestcase, "?");
    }
  } else if (c == 't' && n >= 8 && cli_strncmp(azArg[0], "testctrl", n) == 0) {
    static const struct {
      const char *zCtrlName;
      int ctrlCode;
      int unSafe;
      const char *zUsage;
    } aCtrl[] = {{"always", 13, 1, "BOOLEAN"},
                 {"assert", 12, 1, "BOOLEAN"},
                 {"byteorder", 22, 0, ""},
                 {"extra_schema_checks", 29, 0, "BOOLEAN"},
                 {"imposter", 25, 1, "SCHEMA ON/OFF ROOTPAGE"},
                 {"internal_functions", 17, 0, ""},
                 {"localtime_fault", 18, 0, "BOOLEAN"},
                 {"never_corrupt", 20, 1, "BOOLEAN"},
                 {"optimizations", 15, 0, "DISABLE-MASK"},
                 {"pending_byte", 11, 0, "OFFSET  "},
                 {"prng_restore", 6, 0, ""},
                 {"prng_save", 5, 0, ""},
                 {"prng_seed", 28, 0, "SEED ?db?"},
                 {"seek_count", 30, 0, ""},
                 {"sorter_mmap", 24, 0, "NMAX"},
                 {"tune", 32, 1, "ID VALUE"}};
    int testctrl = -1;
    int iCtrl = -1;
    int rc2 = 0;
    int isOk = 0;
    int i, n2;
    const char *zCmd = 0;
    if (!(((p)->shellFlgs & (1024)) != 0)) {
      fprintf(stderr, ".%s unavailable without --unsafe-testing\n", "testctrl");
      rc = 1;
      goto meta_command_exit;
    }
    open_db(p, 0);
    zCmd = nArg >= 2 ? azArg[1] : "help";
    if (zCmd[0] == '-' && zCmd[1]) {
      zCmd++;
      if (zCmd[0] == '-' && zCmd[1])
        zCmd++;
    }
    if (cli_strcmp(zCmd, "help") == 0) {
      fprintf(p->out, "Available test-controls:\n");
      for (i = 0; i < (int)(sizeof(aCtrl) / sizeof(aCtrl[0])); i++) {
        fprintf(p->out, "  .testctrl %s %s\n", aCtrl[i].zCtrlName,
                aCtrl[i].zUsage);
      }
      rc = 1;
      goto meta_command_exit;
    }
    n2 = strlen30(zCmd);
    for (i = 0; i < (int)(sizeof(aCtrl) / sizeof(aCtrl[0])); i++) {
      if (cli_strncmp(zCmd, aCtrl[i].zCtrlName, n2) == 0) {
        if (testctrl < 0) {
          testctrl = aCtrl[i].ctrlCode;
          iCtrl = i;
        } else {
          fprintf(stderr,
                  "Error: ambiguous test-control: \"%s\"\nUse \".testctrl "
                  "--help\" for help\n",
                  zCmd);
          rc = 1;
          goto meta_command_exit;
        }
      }
    }
    if (testctrl < 0) {
      fprintf(stderr,
              "Error: unknown test-control: %s\nUse \".testctrl --help\" for "
              "help\n",
              zCmd);
    } else if (aCtrl[iCtrl].unSafe && p->bSafeMode) {
      fprintf(stderr,
              "line %d: \".testctrl %s\" may not be used in safe mode\n",
              p->lineno, aCtrl[iCtrl].zCtrlName);
      exit(1);
    } else {
      switch (testctrl) {
      case 15:
        if (nArg == 3) {
          unsigned int opt = (unsigned int)strtol(azArg[2], 0, 0);
          rc2 = sqlite3_test_control(testctrl, p->db, opt);
          isOk = 3;
        }
        break;
      case 5:
      case 6:
      case 22:
        if (nArg == 2) {
          rc2 = sqlite3_test_control(testctrl);
          isOk = testctrl == 22 ? 1 : 3;
        }
        break;
      case 11:
        if (nArg == 3) {
          unsigned int opt = (unsigned int)integerValue(azArg[2]);
          rc2 = sqlite3_test_control(testctrl, opt);
          isOk = 3;
        }
        break;
      case 28:
        if (nArg == 3 || nArg == 4) {
          int ii = (int)integerValue(azArg[2]);
          sqlite3 *db;
          if (ii == 0 && cli_strcmp(azArg[2], "random") == 0) {
            sqlite3_randomness(sizeof(ii), &ii);
            printf("-- random seed: %d\n", ii);
          }
          if (nArg == 3) {
            db = 0;
          } else {
            db = p->db;
            sqlite3_table_column_metadata(db, 0, "x", 0, 0, 0, 0, 0, 0);
          }
          rc2 = sqlite3_test_control(testctrl, ii, db);
          isOk = 3;
        }
        break;
      case 12:
      case 13:
        if (nArg == 3) {
          int opt = booleanValue(azArg[2]);
          rc2 = sqlite3_test_control(testctrl, opt);
          isOk = 1;
        }
        break;
      case 18:
      case 20:
        if (nArg == 3) {
          int opt = booleanValue(azArg[2]);
          rc2 = sqlite3_test_control(testctrl, opt);
          isOk = 3;
        }
        break;
      case 17:
        rc2 = sqlite3_test_control(testctrl, p->db);
        isOk = 3;
        break;
      case 25:
        if (nArg == 5) {
          rc2 = sqlite3_test_control(testctrl, p->db, azArg[2],
                                     integerValue(azArg[3]),
                                     integerValue(azArg[4]));
          isOk = 3;
        }
        break;
      case 30: {
        u64 x = 0;
        rc2 = sqlite3_test_control(testctrl, p->db, &x);
        fprintf(p->out, "%llu\n", x);
        isOk = 3;
        break;
      }
      case 24:
        if (nArg == 3) {
          int opt = (unsigned int)integerValue(azArg[2]);
          rc2 = sqlite3_test_control(testctrl, p->db, opt);
          isOk = 3;
        }
        break;
      }
    }
    if (isOk == 0 && iCtrl >= 0) {
      fprintf(p->out, "Usage: .testctrl %s %s\n", zCmd, aCtrl[iCtrl].zUsage);
      rc = 1;
    } else if (isOk == 1) {
      fprintf(p->out, "%d\n", rc2);
    } else if (isOk == 2) {
      fprintf(p->out, "0x%08x\n", rc2);
    }
  } else if (c == 't' && n > 4 && cli_strncmp(azArg[0], "timeout", n) == 0) {
    open_db(p, 0);
    sqlite3_busy_timeout(p->db, nArg >= 2 ? (int)integerValue(azArg[1]) : 0);
  } else if (c == 't' && n >= 5 && cli_strncmp(azArg[0], "timer", n) == 0) {
    if (nArg == 2) {
      enableTimer = booleanValue(azArg[1]);
      if (enableTimer && !1) {
        fprintf(stderr, "Error: timer not available on this system.\n");
        enableTimer = 0;
      }
    } else {
      fprintf(stderr, "Usage: .timer on|off\n");
      rc = 1;
    }
  } else if (c == 't' && cli_strncmp(azArg[0], "trace", n) == 0) {
    int mType = 0;
    int jj;
    open_db(p, 0);
    for (jj = 1; jj < nArg; jj++) {
      const char *z = azArg[jj];
      if (z[0] == '-') {
        if (optionMatch(z, "expanded")) {
          p->eTraceType = 1;
        } else if (optionMatch(z, "plain")) {
          p->eTraceType = 0;
        } else if (optionMatch(z, "profile")) {
          mType |= 2;
        } else if (optionMatch(z, "row")) {
          mType |= 4;
        } else if (optionMatch(z, "stmt")) {
          mType |= 1;
        } else if (optionMatch(z, "close")) {
          mType |= 8;
        } else {
          fprintf(stderr, "Unknown option \"%s\" on \".trace\"\n", z);
          rc = 1;
          goto meta_command_exit;
        }
      } else {
        output_file_close(p->traceOut);
        p->traceOut = output_file_open(z, 0);
      }
    }
    if (p->traceOut == 0) {
      sqlite3_trace_v2(p->db, 0, 0, 0);
    } else {
      if (mType == 0)
        mType = 1;
      sqlite3_trace_v2(p->db, mType, sql_trace_callback, p);
    }
  } else if (c == 'v' && cli_strncmp(azArg[0], "version", n) == 0) {
    fprintf(p->out, "SQLite %s %s\n", sqlite3_libversion(), sqlite3_sourceid());
    fprintf(p->out, "clang-15.0.7\n");
  } else if (c == 'v' && cli_strncmp(azArg[0], "vfsinfo", n) == 0) {
    const char *zDbName = nArg == 2 ? azArg[1] : "main";
    sqlite3_vfs *pVfs = 0;
    if (p->db) {
      sqlite3_file_control(p->db, zDbName, 27, &pVfs);
      if (pVfs) {
        fprintf(p->out, "vfs.zName      = \"%s\"\n", pVfs->zName);
        fprintf(p->out, "vfs.iVersion   = %d\n", pVfs->iVersion);
        fprintf(p->out, "vfs.szOsFile   = %d\n", pVfs->szOsFile);
        fprintf(p->out, "vfs.mxPathname = %d\n", pVfs->mxPathname);
      }
    }
  } else if (c == 'v' && cli_strncmp(azArg[0], "vfslist", n) == 0) {
    sqlite3_vfs *pVfs;
    sqlite3_vfs *pCurrent = 0;
    if (p->db) {
      sqlite3_file_control(p->db, "main", 27, &pCurrent);
    }
    for (pVfs = sqlite3_vfs_find(0); pVfs; pVfs = pVfs->pNext) {
      fprintf(p->out, "vfs.zName      = \"%s\"%s\n", pVfs->zName,
              pVfs == pCurrent ? "  <--- CURRENT" : "");
      fprintf(p->out, "vfs.iVersion   = %d\n", pVfs->iVersion);
      fprintf(p->out, "vfs.szOsFile   = %d\n", pVfs->szOsFile);
      fprintf(p->out, "vfs.mxPathname = %d\n", pVfs->mxPathname);
      if (pVfs->pNext) {
        fprintf(p->out, "-----------------------------------\n");
      }
    }
  } else if (c == 'v' && cli_strncmp(azArg[0], "vfsname", n) == 0) {
    const char *zDbName = nArg == 2 ? azArg[1] : "main";
    char *zVfsName = 0;
    if (p->db) {
      sqlite3_file_control(p->db, zDbName, 12, &zVfsName);
      if (zVfsName) {
        fprintf(p->out, "%s\n", zVfsName);
        sqlite3_free(zVfsName);
      }
    }
  } else if (c == 'w' && cli_strncmp(azArg[0], "wheretrace", n) == 0) {
    unsigned int x =
        nArg >= 2 ? (unsigned int)integerValue(azArg[1]) : 4294967295;
    sqlite3_test_control(31, 3, &x);
  } else if (c == 'w' && cli_strncmp(azArg[0], "width", n) == 0) {
    int j;
    ((void)sizeof((nArg <= (int)(sizeof(azArg) / sizeof(azArg[0]))) ? 1 : 0), ({
       if (nArg <= (int)(sizeof(azArg) / sizeof(azArg[0])))
         ;
       else
         __assert_fail("nArg<=ArraySize(azArg)", "shell.c", 26589,
                       __PRETTY_FUNCTION__);
     }));
    p->nWidth = nArg - 1;
    p->colWidth = realloc(p->colWidth, (p->nWidth + 1) * sizeof(int) * 2);
    if (p->colWidth == 0 && p->nWidth > 0)
      shell_out_of_memory();
    if (p->nWidth)
      p->actualWidth = &p->colWidth[p->nWidth];
    for (j = 1; j < nArg; j++) {
      p->colWidth[j - 1] = (int)integerValue(azArg[j]);
    }
  } else {
    fprintf(stderr,
            "Error: unknown command or invalid arguments:  \"%s\". Enter "
            "\".help\" for help\n",
            azArg[0]);
    rc = 1;
  }
meta_command_exit:
  if (p->outCount) {
    p->outCount--;
    if (p->outCount == 0)
      output_reset(p);
  }
  p->bSafeMode = p->bSafeModePersist;
  return rc;
}
typedef enum {
  QSS_HasDark = 1 << 8,
  QSS_EndingSemi = 2 << 8,
  QSS_CharMask = (1 << 8) - 1,
  QSS_ScanMask = 3 << 8,
  QSS_Start = 0
} QuickScanState;
static QuickScanState quickscan(char *zLine, QuickScanState qss,
                                t_DynaPromptRef pst) {
  char cin;
  char cWait = (char)qss;
  if (cWait == 0) {
  PlainScan:
    ((void)sizeof((cWait == 0) ? 1 : 0), ({
       if (cWait == 0)
         ;
       else
         __assert_fail("cWait==0", "shell.c", 26641, __PRETTY_FUNCTION__);
     }));
    while ((cin = *zLine++) != 0) {
      if (((*__ctype_b_loc())[(int)(((unsigned char)cin))] &
           (unsigned short int)_ISspace))
        continue;
      switch (cin) {
      case '-':
        if (*zLine != '-')
          break;
        while ((cin = *++zLine) != 0)
          if (cin == '\n')
            goto PlainScan;
        return qss;
      case ';':
        qss |= QSS_EndingSemi;
        continue;
      case '/':
        if (*zLine == '*') {
          ++zLine;
          cWait = '*';
          if (pst && stdin_is_interactive)
            setLexemeOpen(pst, "/*", 0);
          qss = ((cWait) | ((qss)&QSS_ScanMask));
          goto TermScan;
        }
        break;
      case '[':
        cin = ']';
        ;
      case '`':
      case '\'':
      case '\"':
        cWait = cin;
        qss = QSS_HasDark | cWait;
        if (pst && stdin_is_interactive)
          setLexemeOpen(pst, 0, cin);
        goto TermScan;
      case '(':
        if (pst && stdin_is_interactive)
          (trackParenLevel(pst, 1));
        break;
      case ')':
        if (pst && stdin_is_interactive)
          (trackParenLevel(pst, -1));
        break;
      default:
        break;
      }
      qss = (qss & ~QSS_EndingSemi) | QSS_HasDark;
    }
  } else {
  TermScan:
    while ((cin = *zLine++) != 0) {
      if (cin == cWait) {
        switch (cWait) {
        case '*':
          if (*zLine != '/')
            continue;
          ++zLine;
          cWait = 0;
          if (pst && stdin_is_interactive)
            setLexemeOpen(pst, 0, 0);
          qss = ((0) | ((qss)&QSS_ScanMask));
          goto PlainScan;
        case '`':
        case '\'':
        case '\"':
          if (*zLine == cWait) {
            ++zLine;
            continue;
          };
        case ']':
          cWait = 0;
          if (pst && stdin_is_interactive)
            setLexemeOpen(pst, 0, 0);
          qss = ((0) | ((qss)&QSS_ScanMask));
          goto PlainScan;
        default:
          ((void)sizeof((0) ? 1 : 0), ({
             if (0)
               ;
             else
               __assert_fail("0", "shell.c", 26709, __PRETTY_FUNCTION__);
           }));
        }
      }
    }
  }
  return qss;
}
static int line_is_command_terminator(char *zLine) {
  while (((*__ctype_b_loc())[(int)(((unsigned char)zLine[0]))] &
          (unsigned short int)_ISspace)) {
    zLine++;
  };
  if (zLine[0] == '/')
    zLine += 1;
  else if ((char)tolower((unsigned char)zLine[0]) == 'g' &&
           (char)tolower((unsigned char)zLine[1]) == 'o')
    zLine += 2;
  else
    return 0;
  return quickscan(zLine, QSS_Start, 0) == QSS_Start;
}
static int line_is_complete(char *zSql, int nSql) {
  int rc;
  if (zSql == 0)
    return 1;
  zSql[nSql] = ';';
  zSql[nSql + 1] = 0;
  rc = sqlite3_complete(zSql);
  zSql[nSql] = 0;
  return rc;
}
static int runOneSqlLine(ShellState *p, char *zSql, FILE *in, int startline) {
  int rc;
  char *zErrMsg = 0;
  open_db(p, 0);
  if ((((p)->shellFlgs & (4)) != 0))
    resolve_backslashes(zSql);
  if (p->flgProgress & 2)
    p->nProgress = 0;
  beginTimer();
  rc = shell_exec(p, zSql, &zErrMsg);
  endTimer();
  if (rc || zErrMsg) {
    char zPrefix[100];
    const char *zErrorTail;
    const char *zErrorType;
    if (zErrMsg == 0) {
      zErrorType = "Error";
      zErrorTail = sqlite3_errmsg(p->db);
    } else if (cli_strncmp(zErrMsg, "in prepare, ", 12) == 0) {
      zErrorType = "Parse error";
      zErrorTail = &zErrMsg[12];
    } else if (cli_strncmp(zErrMsg, "stepping, ", 10) == 0) {
      zErrorType = "Runtime error";
      zErrorTail = &zErrMsg[10];
    } else {
      zErrorType = "Error";
      zErrorTail = zErrMsg;
    }
    if (in != 0 || !stdin_is_interactive) {
      sqlite3_snprintf(sizeof(zPrefix), zPrefix, "%s near line %d:", zErrorType,
                       startline);
    } else {
      sqlite3_snprintf(sizeof(zPrefix), zPrefix, "%s:", zErrorType);
    }
    fprintf(stderr, "%s %s\n", zPrefix, zErrorTail);
    sqlite3_free(zErrMsg);
    zErrMsg = 0;
    return 1;
  } else if ((((p)->shellFlgs & (32)) != 0)) {
    char zLineBuf[2000];
    sqlite3_snprintf(sizeof(zLineBuf), zLineBuf,
                     "changes: %lld   total_changes: %lld",
                     sqlite3_changes64(p->db), sqlite3_total_changes64(p->db));
    fprintf(p->out, "%s\n", zLineBuf);
  }
  return 0;
}
static void echo_group_input(ShellState *p, const char *zDo) {
  if ((((p)->shellFlgs & (64)) != 0))
    fprintf(p->out, "%s\n", zDo);
}
static int process_input(ShellState *p) {
  char *zLine = 0;
  char *zSql = 0;
  i64 nLine;
  i64 nSql = 0;
  i64 nAlloc = 0;
  int rc;
  int errCnt = 0;
  i64 startline = 0;
  QuickScanState qss = QSS_Start;
  if (p->inputNesting == 25) {
    fprintf(stderr,
            "Input nesting limit (%d) reached at line %d. Check recursion.\n",
            25, p->lineno);
    return 1;
  }
  ++p->inputNesting;
  p->lineno = 0;
  do {
    setLexemeOpen(&dynPrompt, 0, 0);
    trackParenLevel(&dynPrompt, 0);
  } while (0);
  while (errCnt == 0 || !bail_on_error ||
         (p->in == 0 && stdin_is_interactive)) {
    fflush(p->out);
    zLine = one_input_line(p->in, zLine, nSql > 0);
    if (zLine == 0) {
      if (p->in == 0 && stdin_is_interactive)
        printf("\n");
      break;
    }
    if (seenInterrupt) {
      if (p->in != 0)
        break;
      seenInterrupt = 0;
    }
    p->lineno++;
    if ((((qss)&QSS_CharMask) == QSS_Start) &&
        line_is_command_terminator(zLine) && line_is_complete(zSql, nSql)) {
      memcpy(zLine, ";", 2);
    }
    qss = quickscan(zLine, qss, (&dynPrompt));
    if ((((qss) & ~QSS_EndingSemi) == QSS_Start) && nSql == 0) {
      echo_group_input(p, zLine);
      qss = QSS_Start;
      continue;
    }
      do {
        setLexemeOpen(&dynPrompt, 0, 0);
        trackParenLevel(&dynPrompt, 0);
      } while (0);
      echo_group_input(p, zLine);
      if (zLine[0] == '.') {
        rc = do_meta_command(zLine, p);
        if (rc == 2) {
          break;
        } else if (rc) {
          errCnt++;
        }
      }
      qss = QSS_Start;
      continue;
    }
    nLine = strlen(zLine);
    if (nSql + nLine + 2 >= nAlloc) {
      nAlloc = nSql + (nSql >> 1) + nLine + 100;
      zSql = realloc(zSql, nAlloc);
      shell_check_oom(zSql);
    }
    if (nSql == 0) {
      i64 i;
      for (i = 0;
           zLine[i] && ((*__ctype_b_loc())[(int)(((unsigned char)zLine[i]))] &
                        (unsigned short int)_ISspace);
           i++) {
      }
      ((void)sizeof((nAlloc > 0 && zSql != 0) ? 1 : 0), ({
         if (nAlloc > 0 && zSql != 0)
           ;
         else
           __assert_fail("nAlloc>0 && zSql!=0", "shell.c", 26921,
                         __PRETTY_FUNCTION__);
       }));
      memcpy(zSql, zLine + i, nLine + 1 - i);
      startline = p->lineno;
      nSql = nLine - i;
    } else {
      zSql[nSql++] = '\n';
      memcpy(zSql + nSql, zLine, nLine + 1);
      nSql += nLine;
    }
    if (nSql && (((qss) & ~QSS_HasDark) == QSS_EndingSemi) &&
        sqlite3_complete(zSql)) {
      echo_group_input(p, zSql);
      errCnt += runOneSqlLine(p, zSql, p->in, startline);
      do {
        setLexemeOpen(&dynPrompt, 0, 0);
        trackParenLevel(&dynPrompt, 0);
      } while (0);
      nSql = 0;
      if (p->outCount) {
        output_reset(p);
        p->outCount = 0;
      } else {
        clearTempFile(p);
      }
      p->bSafeMode = p->bSafeModePersist;
      qss = QSS_Start;
    } else if (nSql && (((qss) & ~QSS_EndingSemi) == QSS_Start)) {
      echo_group_input(p, zSql);
      nSql = 0;
      qss = QSS_Start;
    }
  }
  if (nSql) {
    echo_group_input(p, zSql);
    errCnt += runOneSqlLine(p, zSql, p->in, startline);
    do {
      setLexemeOpen(&dynPrompt, 0, 0);
      trackParenLevel(&dynPrompt, 0);
    } while (0);
  }
  free(zSql);
  free(zLine);
  --p->inputNesting;
  return errCnt > 0;
}
static char *find_home_dir(int clearFlag) {
  static char *home_dir = ((void *)0);
  if (clearFlag) {
    free(home_dir);
    home_dir = 0;
    return 0;
  }
  if (home_dir)
    return home_dir;
  {
    struct passwd *pwent;
    uid_t uid = getuid();
    if ((pwent = getpwuid(uid)) != ((void *)0)) {
      home_dir = pwent->pw_dir;
    }
  }
  if (!home_dir) {
    home_dir = getenv("HOME");
  }
  if (home_dir) {
    i64 n = strlen(home_dir) + 1;
    char *z = malloc(n);
    if (z)
      memcpy(z, home_dir, n);
    home_dir = z;
  }
  return home_dir;
}
static const char *find_xdg_config(void) {
  static int alreadyTried = 0;
  static char *zConfig = 0;
  const char *zXdgHome;
  if (alreadyTried != 0) {
    return zConfig;
  }
  alreadyTried = 1;
  zXdgHome = getenv("XDG_CONFIG_HOME");
  if (zXdgHome == 0) {
    return 0;
  }
  zConfig = sqlite3_mprintf("%s/sqlite3/sqliterc", zXdgHome);
  shell_check_oom(zConfig);
  if (access(zConfig, 0) != 0) {
    sqlite3_free(zConfig);
    zConfig = 0;
  }
  return zConfig;
}
static void process_sqliterc(ShellState *p, const char *sqliterc_override) {
  char *home_dir = ((void *)0);
  const char *sqliterc = sqliterc_override;
  char *zBuf = 0;
  FILE *inSaved = p->in;
  int savedLineno = p->lineno;
  if (sqliterc == ((void *)0)) {
    sqliterc = find_xdg_config();
  }
  if (sqliterc == ((void *)0)) {
    home_dir = find_home_dir(0);
    if (home_dir == 0) {
      fprintf(
          stderr,
          "-- warning: cannot find home directory; cannot read ~/.sqliterc\n");
      return;
    }
    zBuf = sqlite3_mprintf("%s/.sqliterc", home_dir);
    shell_check_oom(zBuf);
    sqliterc = zBuf;
  }
  p->in = fopen(sqliterc, "rb");
  if (p->in) {
    if (stdin_is_interactive) {
      fprintf(stderr, "-- Loading resources from %s\n", sqliterc);
    }
    if (process_input(p) && bail_on_error)
      exit(1);
    fclose(p->in);
  } else if (sqliterc_override != 0) {
    fprintf(stderr, "cannot open: \"%s\"\n", sqliterc);
    if (bail_on_error)
      exit(1);
  }
  p->in = inSaved;
  p->lineno = savedLineno;
  sqlite3_free(zBuf);
}
static const char zOptions[] =
    "   --                   treat no subsequent arguments as options\n   "
    "-append              append the database to the end of the file\n   "
    "-ascii               set output mode to 'ascii'\n   -bail                "
    "stop after hitting an error\n   -batch               force batch I/O\n   "
    "-box                 set output mode to 'box'\n   -column              "
    "set output mode to 'column'\n   -cmd COMMAND         run \"COMMAND\" "
    "before reading stdin\n   -csv                 set output mode to 'csv'\n  "
    " -deserialize         open the database using sqlite3_deserialize()\n   "
    "-echo                print inputs before execution\n   -init FILENAME     "
    "  read/process named file\n   -[no]header          turn headers on or "
    "off\n   -help                show this message\n   -html                "
    "set output mode to HTML\n   -interactive         force interactive I/O\n  "
    " -json                set output mode to 'json'\n   -line                "
    "set output mode to 'line'\n   -list                set output mode to "
    "'list'\n   -lookaside SIZE N    use N entries of SZ bytes for lookaside "
    "memory\n   -markdown            set output mode to 'markdown'\n   "
    "-maxsize N           maximum size for a --deserialize database\n   "
    "-memtrace            trace all memory allocations and deallocations\n   "
    "-mmap N              default mmap size set to N\n   -newline SEP         "
    "set output row separator. Default: '\\n'\n   -nofollow            refuse "
    "to open symbolic links to database files\n   -nonce STRING        set the "
    "safe-mode escape nonce\n   -nullvalue TEXT      set text string for NULL "
    "values. Default ''\n   -pagecache SIZE N    use N slots of SZ bytes each "
    "for page cache memory\n   -quote               set output mode to "
    "'quote'\n   -readonly            open the database read-only\n   -safe    "
    "            enable safe-mode\n   -separator SEP       set output column "
    "separator. Default: '|'\n   -stats               print memory stats "
    "before each finalize\n   -table               set output mode to "
    "'table'\n   -tabs                set output mode to 'tabs'\n   "
    "-unsafe-testing      allow unsafe commands and modes for testing\n   "
    "-version             show SQLite version\n   -vfs NAME            use "
    "NAME as the default VFS\n";
static void usage(int showDetail) {
  fprintf(stderr,
          "Usage: %s [OPTIONS] [FILENAME [SQL]]\nFILENAME is the name of an "
          "SQLite database. A new database is created\nif the file does not "
          "previously exist. Defaults to :memory:.\n",
          Argv0);
  if (showDetail) {
    fprintf(stderr, "OPTIONS include:\n%s", zOptions);
  } else {
    fprintf(stderr, "Use the -help option for additional information\n");
  }
  exit(1);
}
static void verify_uninitialized(void) {
  if (sqlite3_config(-1) == 21) {
    fprintf(stdout,
            "WARNING: attempt to configure SQLite after initialization.\n");
  }
}
static void main_init(ShellState *data) {
  memset(data, 0, sizeof(*data));
  data->normalMode = data->cMode = data->mode = 2;
  data->autoExplain = 1;
  data->pAuxDb = &data->aAuxDb[0];
  memcpy(data->colSeparator, "|", 2);
  memcpy(data->rowSeparator, "\n", 2);
  data->showHeader = 0;
  data->shellFlgs = 2;
  sqlite3_config(16, shellLog, data);
  verify_uninitialized();
  sqlite3_config(17, 1);
  sqlite3_config(2);
  sqlite3_snprintf(sizeof(mainPrompt), mainPrompt, "sqlite> ");
  sqlite3_snprintf(sizeof(continuePrompt), continuePrompt, "   ...> ");
}
static void printBold(const char *zText) { printf("", zText); }
static char *cmdline_option_value(int argc, char **argv, int i) {
  if (i == argc) {
    fprintf(stderr, "%s: Error: missing argument to %s\n", argv[0],
            argv[argc - 1]);
    exit(1);
  }
  return argv[i];
}
static void sayAbnormalExit(void) {
  if (seenInterrupt)
    fprintf(stderr, "Program interrupted.\n");
}
int main(int argc, char **argv) {
  char *zErrMsg = 0;
  ShellState data;
  const char *zInitFile = 0;
  int i;
  int rc = 0;
  int warnInmemoryDb = 0;
  int readStdin = 1;
  int nCmd = 0;
  int nOptsEnd = argc;
  char **azCmd = 0;
  const char *zVfs = 0;
  setvbuf(stderr, 0, 2, 0);
  stdin_is_interactive = isatty(0);
  stdout_is_console = isatty(1);
  atexit(sayAbnormalExit);
  if (getenv("SQLITE_DEBUG_BREAK")) {
    if (isatty(0) && isatty(2)) {
      fprintf(stderr,
              "attach debugger to process %d and press any key to continue.\n",
              getpid());
      fgetc(stdin);
    } else {
      raise(5);
    }
  }
  signal(2, interrupt_handler);
  if (cli_strncmp(
          sqlite3_sourceid(),
          "2023-05-16 12:36:15 "
          "831d0fb2836b71c9bc51067c49fee4b8f18047814f2ff22d817d25195cf350b0",
          60) != 0) {
    fprintf(stderr, "SQLite header and source version mismatch\n%s\n%s\n",
            sqlite3_sourceid(),
            "2023-05-16 12:36:15 "
            "831d0fb2836b71c9bc51067c49fee4b8f18047814f2ff22d817d25195cf350b0");
    exit(1);
  }
  main_init(&data);
  ((void)sizeof((argc >= 1 && argv && argv[0]) ? 1 : 0), ({
     if (argc >= 1 && argv && argv[0])
       ;
     else
       __assert_fail("argc>=1 && argv && argv[0]", "shell.c", 27388,
                     __PRETTY_FUNCTION__);
   }));
  Argv0 = argv[0];
  verify_uninitialized();
  for (i = 1; i < argc; i++) {
    char *z;
    z = argv[i];
    if (z[0] != '-' || i > nOptsEnd) {
      if (data.aAuxDb->zDbFilename == 0) {
        data.aAuxDb->zDbFilename = z;
      } else {
        readStdin = 0;
        nCmd++;
        azCmd = realloc(azCmd, sizeof(azCmd[0]) * nCmd);
        shell_check_oom(azCmd);
        azCmd[nCmd - 1] = z;
      }
      continue;
    }
    if (z[1] == '-')
      z++;
    if (cli_strcmp(z, "-") == 0) {
      nOptsEnd = i;
      continue;
    } else if (cli_strcmp(z, "-separator") == 0 ||
               cli_strcmp(z, "-nullvalue") == 0 ||
               cli_strcmp(z, "-newline") == 0 || cli_strcmp(z, "-cmd") == 0) {
      (void)cmdline_option_value(argc, argv, ++i);
    } else if (cli_strcmp(z, "-init") == 0) {
      zInitFile = cmdline_option_value(argc, argv, ++i);
    } else if (cli_strcmp(z, "-batch") == 0) {
      stdin_is_interactive = 0;
    } else if (cli_strcmp(z, "-heap") == 0) {
      (void)cmdline_option_value(argc, argv, ++i);
    } else if (cli_strcmp(z, "-pagecache") == 0) {
      sqlite3_int64 n, sz;
      sz = integerValue(cmdline_option_value(argc, argv, ++i));
      if (sz > 70000)
        sz = 70000;
      if (sz < 0)
        sz = 0;
      n = integerValue(cmdline_option_value(argc, argv, ++i));
      if (sz > 0 && n > 0 && 281474976710655 / sz < n) {
        n = 281474976710655 / sz;
      }
      verify_uninitialized();
      sqlite3_config(7, (n > 0 && sz > 0) ? malloc(n * sz) : 0, sz, n);
      data.shellFlgs |= 1;
    } else if (cli_strcmp(z, "-lookaside") == 0) {
      int n, sz;
      sz = (int)integerValue(cmdline_option_value(argc, argv, ++i));
      if (sz < 0)
        sz = 0;
      n = (int)integerValue(cmdline_option_value(argc, argv, ++i));
      if (n < 0)
        n = 0;
      verify_uninitialized();
      sqlite3_config(13, sz, n);
      if (sz * n == 0)
        data.shellFlgs &= ~2;
    } else if (cli_strcmp(z, "-threadsafe") == 0) {
      int n;
      n = (int)integerValue(cmdline_option_value(argc, argv, ++i));
      verify_uninitialized();
      switch (n) {
      case 0:
        sqlite3_config(1);
        break;
      case 2:
        sqlite3_config(2);
        break;
      default:
        sqlite3_config(3);
        break;
      }
    } else if (cli_strcmp(z, "-mmap") == 0) {
      sqlite3_int64 sz = integerValue(cmdline_option_value(argc, argv, ++i));
      verify_uninitialized();
      sqlite3_config(22, sz, sz);
    } else if (cli_strcmp(z, "-vfs") == 0) {
      zVfs = cmdline_option_value(argc, argv, ++i);
    } else if (cli_strcmp(z, "-append") == 0) {
      data.openMode = 2;
    } else if (cli_strcmp(z, "-deserialize") == 0) {
      data.openMode = 5;
    } else if (cli_strcmp(z, "-maxsize") == 0 && i + 1 < argc) {
      data.szMax = integerValue(argv[++i]);
    } else if (cli_strcmp(z, "-readonly") == 0) {
      data.openMode = 4;
    } else if (cli_strcmp(z, "-nofollow") == 0) {
      data.openFlags = 16777216;
    } else if (cli_strcmp(z, "-memtrace") == 0) {
      sqlite3MemTraceActivate(stderr);
    } else if (cli_strcmp(z, "-bail") == 0) {
      bail_on_error = 1;
    } else if (cli_strcmp(z, "-nonce") == 0) {
      free(data.zNonce);
      data.zNonce = strdup(argv[++i]);
    } else if (cli_strcmp(z, "-unsafe-testing") == 0) {
      ((&data)->shellFlgs |= (1024));
    } else if (cli_strcmp(z, "-safe") == 0) {
    }
  }
  verify_uninitialized();
  sqlite3_initialize();
  if (zVfs) {
    sqlite3_vfs *pVfs = sqlite3_vfs_find(zVfs);
    if (pVfs) {
      sqlite3_vfs_register(pVfs, 1);
    } else {
      fprintf(stderr, "no such VFS: \"%s\"\n", zVfs);
      exit(1);
    }
  }
  if (data.pAuxDb->zDbFilename == 0) {
    data.pAuxDb->zDbFilename = ":memory:";
    warnInmemoryDb = argc == 1;
  }
  data.out = stdout;
  sqlite3_appendvfs_init(0, 0, 0);
  if (access(data.pAuxDb->zDbFilename, 0) == 0) {
    open_db(&data, 0);
  }
  process_sqliterc(&data, zInitFile);
  for (i = 1; i < argc; i++) {
    char *z = argv[i];
    if (z[0] != '-' || i >= nOptsEnd)
      continue;
    if (z[1] == '-') {
      z++;
    }
    if (cli_strcmp(z, "-init") == 0) {
      i++;
    } else if (cli_strcmp(z, "-html") == 0) {
      data.mode = 4;
    } else if (cli_strcmp(z, "-list") == 0) {
      data.mode = 2;
    } else if (cli_strcmp(z, "-quote") == 0) {
      data.mode = 6;
      sqlite3_snprintf(sizeof(data.colSeparator), data.colSeparator, ",");
      sqlite3_snprintf(sizeof(data.rowSeparator), data.rowSeparator, "\n");
    } else if (cli_strcmp(z, "-line") == 0) {
      data.mode = 0;
    } else if (cli_strcmp(z, "-column") == 0) {
      data.mode = 1;
    } else if (cli_strcmp(z, "-json") == 0) {
      data.mode = 13;
    } else if (cli_strcmp(z, "-markdown") == 0) {
      data.mode = 14;
    } else if (cli_strcmp(z, "-table") == 0) {
      data.mode = 15;
    } else if (cli_strcmp(z, "-box") == 0) {
      data.mode = 16;
    } else if (cli_strcmp(z, "-csv") == 0) {
      data.mode = 8;
      memcpy(data.colSeparator, ",", 2);
    } else if (cli_strcmp(z, "-append") == 0) {
      data.openMode = 2;
    } else if (cli_strcmp(z, "-deserialize") == 0) {
      data.openMode = 5;
    } else if (cli_strcmp(z, "-maxsize") == 0 && i + 1 < argc) {
      data.szMax = integerValue(argv[++i]);
    } else if (cli_strcmp(z, "-readonly") == 0) {
      data.openMode = 4;
    } else if (cli_strcmp(z, "-nofollow") == 0) {
      data.openFlags |= 16777216;
    } else if (cli_strcmp(z, "-ascii") == 0) {
      data.mode = 10;
      sqlite3_snprintf(sizeof(data.colSeparator), data.colSeparator, "\x1f");
      sqlite3_snprintf(sizeof(data.rowSeparator), data.rowSeparator, "\x1e");
    } else if (cli_strcmp(z, "-tabs") == 0) {
      data.mode = 2;
      sqlite3_snprintf(sizeof(data.colSeparator), data.colSeparator, "\t");
      sqlite3_snprintf(sizeof(data.rowSeparator), data.rowSeparator, "\n");
    } else if (cli_strcmp(z, "-separator") == 0) {
      sqlite3_snprintf(sizeof(data.colSeparator), data.colSeparator, "%s",
                       cmdline_option_value(argc, argv, ++i));
    } else if (cli_strcmp(z, "-newline") == 0) {
      sqlite3_snprintf(sizeof(data.rowSeparator), data.rowSeparator, "%s",
                       cmdline_option_value(argc, argv, ++i));
    } else if (cli_strcmp(z, "-nullvalue") == 0) {
      sqlite3_snprintf(sizeof(data.nullValue), data.nullValue, "%s",
                       cmdline_option_value(argc, argv, ++i));
    } else if (cli_strcmp(z, "-header") == 0) {
      data.showHeader = 1;
      ((&data)->shellFlgs |= (128));
    } else if (cli_strcmp(z, "-noheader") == 0) {
      data.showHeader = 0;
      ((&data)->shellFlgs |= (128));
    } else if (cli_strcmp(z, "-echo") == 0) {
      ((&data)->shellFlgs |= (64));
    } else if (cli_strcmp(z, "-eqp") == 0) {
      data.autoEQP = 1;
    } else if (cli_strcmp(z, "-eqpfull") == 0) {
      data.autoEQP = 3;
    } else if (cli_strcmp(z, "-stats") == 0) {
      data.statsOn = 1;
    } else if (cli_strcmp(z, "-scanstats") == 0) {
      data.scanstatsOn = 1;
    } else if (cli_strcmp(z, "-backslash") == 0) {
      ((&data)->shellFlgs |= (4));
    } else if (cli_strcmp(z, "-bail") == 0) {
    } else if (cli_strcmp(z, "-version") == 0) {
      printf("%s %s\n", sqlite3_libversion(), sqlite3_sourceid());
      return 0;
    } else if (cli_strcmp(z, "-interactive") == 0) {
      stdin_is_interactive = 1;
    } else if (cli_strcmp(z, "-batch") == 0) {
      stdin_is_interactive = 0;
    } else if (cli_strcmp(z, "-utf8") == 0) {
    } else if (cli_strcmp(z, "-heap") == 0) {
      i++;
    } else if (cli_strcmp(z, "-pagecache") == 0) {
      i += 2;
    } else if (cli_strcmp(z, "-lookaside") == 0) {
      i += 2;
    } else if (cli_strcmp(z, "-threadsafe") == 0) {
      i += 2;
    } else if (cli_strcmp(z, "-nonce") == 0) {
      i += 2;
    } else if (cli_strcmp(z, "-mmap") == 0) {
      i++;
    } else if (cli_strcmp(z, "-memtrace") == 0) {
      i++;
    } else if (cli_strcmp(z, "-vfs") == 0) {
      i++;
    } else if (cli_strcmp(z, "-help") == 0) {
      usage(1);
    } else if (cli_strcmp(z, "-cmd") == 0) {
      if (i == argc - 1)
        break;
      z = cmdline_option_value(argc, argv, ++i);
      if (z[0] == '.') {
        rc = do_meta_command(z, &data);
        if (rc && bail_on_error)
          return rc == 2 ? 0 : rc;
      } else {
        open_db(&data, 0);
        rc = shell_exec(&data, z, &zErrMsg);
        if (zErrMsg != 0) {
          fprintf(stderr, "Error: %s\n", zErrMsg);
          if (bail_on_error)
            return rc != 0 ? rc : 1;
        } else if (rc != 0) {
          fprintf(stderr, "Error: unable to process SQL \"%s\"\n", z);
          if (bail_on_error)
            return rc;
        }
      }
    } else if (cli_strcmp(z, "-safe") == 0) {
      data.bSafeMode = data.bSafeModePersist = 1;
    } else if (cli_strcmp(z, "-unsafe-testing") == 0) {
    } else {
      fprintf(stderr, "%s: Error: unknown option: %s\n", Argv0, z);
      fprintf(stderr, "Use -help for a list of options.\n");
      return 1;
    }
    data.cMode = data.mode;
  }
  if (!readStdin) {
    for (i = 0; i < nCmd; i++) {
      if (azCmd[i][0] == '.') {
        rc = do_meta_command(azCmd[i], &data);
        if (rc) {
          free(azCmd);
          return rc == 2 ? 0 : rc;
        }
      } else {
        open_db(&data, 0);
        echo_group_input(&data, azCmd[i]);
        rc = shell_exec(&data, azCmd[i], &zErrMsg);
        if (zErrMsg || rc) {
          if (zErrMsg != 0) {
            fprintf(stderr, "Error: %s\n", zErrMsg);
          } else {
            fprintf(stderr, "Error: unable to process SQL: %s\n", azCmd[i]);
          }
          sqlite3_free(zErrMsg);
          free(azCmd);
          return rc != 0 ? rc : 1;
        }
      }
    }
  } else {
    if (stdin_is_interactive) {
      char *zHome;
      char *zHistory;
      int nHistory;
      printf("SQLite version %s %.19s\nEnter \".help\" for usage hints.\n",
             sqlite3_libversion(), sqlite3_sourceid());
      if (warnInmemoryDb) {
        printf("Connected to a ");
        printBold("transient in-memory database");
        printf(
            ".\nUse \".open FILENAME\" to reopen on a persistent database.\n");
      }
      zHistory = getenv("SQLITE_HISTORY");
      if (zHistory) {
        zHistory = strdup(zHistory);
      } else if ((zHome = find_home_dir(0)) != 0) {
        nHistory = strlen30(zHome) + 20;
        if ((zHistory = malloc(nHistory)) != 0) {
          sqlite3_snprintf(nHistory, zHistory, "%s/.sqlite_history", zHome);
        }
      }
      if (zHistory) {
        ;
      }
      data.in = 0;
      rc = process_input(&data);
      if (zHistory) {
        ;
        ;
        free(zHistory);
      }
    } else {
      data.in = stdin;
      rc = process_input(&data);
    }
  }
  free(azCmd);
  set_table_name(&data, 0);
  if (data.db) {
    ;
    close_db(data.db);
  }
  for (i = 0; i < (int)(sizeof(data.aAuxDb) / sizeof(data.aAuxDb[0])); i++) {
    sqlite3_free(data.aAuxDb[i].zFreeOnClose);
    if (data.aAuxDb[i].db) {
      ;
      close_db(data.aAuxDb[i].db);
    }
  }
  find_home_dir(1);
  output_reset(&data);
  data.doXdgOpen = 0;
  clearTempFile(&data);
  free(data.colWidth);
  free(data.zNonce);
  memset(&data, 0, sizeof(data));
  return rc;
}

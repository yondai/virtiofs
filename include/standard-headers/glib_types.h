#ifndef _GLIB_TYPES_H
#define _GLIB_TYPES_H

typedef char   gchar;
#ifndef TRUE
#define TRUE true
#define FALSE false
#endif

typedef unsigned int guint;
typedef void* gpointer;
typedef const void *gconstpointer;
typedef int gint;
typedef gint gboolean;
typedef void (*GFunc) (gpointer data, gpointer user_data);
typedef struct _GThreadPool GThreadPool;
struct _GThreadPool
{
  GFunc func;
  gpointer user_data;
  gboolean exclusive;
};

static inline void g_autoptr_cleanup_generic_gfree (void *p)
{
  void **pp = (void**)p;
//   g_free (*pp);
  free (*pp);
}

#define _GLIB_CLEANUP(func) __attribute__((cleanup(func)))
#define g_autofree _GLIB_CLEANUP(g_autoptr_cleanup_generic_gfree)

typedef struct _GHashTable  GHashTable;

typedef gboolean  (*GHRFunc)  (gpointer  key,
                               gpointer  value,
                               gpointer  user_data);

typedef struct _GHashTableIter GHashTableIter;

struct _GHashTableIter
{
  /*< private >*/
  gpointer      dummy1;
  gpointer      dummy2;
  gpointer      dummy3;
  int           dummy4;
  gboolean      dummy5;
  gpointer      dummy6;
};


#endif /* _GLIB_TYPES_H */

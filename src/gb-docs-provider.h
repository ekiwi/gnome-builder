/* gb-docs-provider.h:
 *
 * Copyright (C) 2013 Christian Hergert <christian@hergert.me>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GB_DOCS_PROVIDER_H
#define GB_DOCS_PROVIDER_H

#include <glib-object.h>

G_BEGIN_DECLS

#define GB_TYPE_DOCS_PROVIDER            (gb_docs_provider_get_type())
#define GB_DOCS_PROVIDER(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GB_TYPE_DOCS_PROVIDER, GbDocsProvider))
#define GB_DOCS_PROVIDER_CONST(obj)      (G_TYPE_CHECK_INSTANCE_CAST ((obj), GB_TYPE_DOCS_PROVIDER, GbDocsProvider const))
#define GB_DOCS_PROVIDER_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass),  GB_TYPE_DOCS_PROVIDER, GbDocsProviderClass))
#define GB_IS_DOCS_PROVIDER(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GB_TYPE_DOCS_PROVIDER))
#define GB_IS_DOCS_PROVIDER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass),  GB_TYPE_DOCS_PROVIDER))
#define GB_DOCS_PROVIDER_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj),  GB_TYPE_DOCS_PROVIDER, GbDocsProviderClass))

typedef struct _GbDocsProvider        GbDocsProvider;
typedef struct _GbDocsProviderClass   GbDocsProviderClass;
typedef struct _GbDocsProviderPrivate GbDocsProviderPrivate;

struct _GbDocsProvider
{
   GObject parent;

   /*< private >*/
   GbDocsProviderPrivate *priv;
};

struct _GbDocsProviderClass
{
   GObjectClass parent_class;
};

GType gb_docs_provider_get_type (void) G_GNUC_CONST;

G_END_DECLS

#endif /* GB_DOCS_PROVIDER_H */

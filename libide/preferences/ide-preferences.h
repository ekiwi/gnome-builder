/* ide-preferences.h
 *
 * Copyright (C) 2015 Christian Hergert <chergert@redhat.com>
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

#ifndef IDE_PREFERENCES_H
#define IDE_PREFERENCES_H

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define IDE_TYPE_PREFERENCES (ide_preferences_get_type())

G_DECLARE_INTERFACE (IdePreferences, ide_preferences, IDE, PREFERENCES, GObject)

struct _IdePreferencesInterface
{
  GTypeInterface parent_interface;

  void     (*set_page)         (IdePreferences *self,
                                const gchar    *page_name,
                                GHashTable     *map);
  void     (*add_page)         (IdePreferences *self,
                                const gchar    *page_name,
                                const gchar    *title,
                                gint            priority);
  void     (*add_group)        (IdePreferences *self,
                                const gchar    *page_name,
                                const gchar    *group_name,
                                const gchar    *title,
                                gint            priority);
  void     (*add_list_group)   (IdePreferences   *self,
                                const gchar      *page_name,
                                const gchar      *group_name,
                                const gchar      *title,
                                GtkSelectionMode  mode,
                                gint              priority);
  guint    (*add_radio)        (IdePreferences *self,
                                const gchar    *page_name,
                                const gchar    *group_name,
                                const gchar    *schema_id,
                                const gchar    *key,
                                const gchar    *path,
                                const gchar    *variant_string,
                                const gchar    *title,
                                const gchar    *subtitle,
                                const gchar    *keywords,
                                gint            priority);
  guint    (*add_font_button)  (IdePreferences *self,
                                const gchar    *page_name,
                                const gchar    *group_name,
                                const gchar    *schema_id,
                                const gchar    *key,
                                const gchar    *title,
                                const gchar    *keywords,
                                gint            priority);
  guint    (*add_switch)       (IdePreferences *self,
                                const gchar    *page_name,
                                const gchar    *group_name,
                                const gchar    *schema_id,
                                const gchar    *key,
                                const gchar    *path,
                                const gchar    *variant_string,
                                const gchar    *title,
                                const gchar    *subtitle,
                                const gchar    *keywords,
                                gint            priority);
  guint    (*add_spin_button)  (IdePreferences *self,
                                const gchar    *page_name,
                                const gchar    *group_name,
                                const gchar    *schema_id,
                                const gchar    *key,
                                const gchar    *path,
                                const gchar    *title,
                                const gchar    *subtitle,
                                const gchar    *keywords,
                                gint            priority);
  guint    (*add_file_chooser) (IdePreferences      *self,
                                const gchar         *page_name,
                                const gchar         *group_name,
                                const gchar         *schema_id,
                                const gchar         *key,
                                const gchar         *path,
                                const gchar         *title,
                                const gchar         *subtitle,
                                GtkFileChooserAction action,
                                const gchar         *keywords,
                                gint                 priority);
  guint    (*add_custom)       (IdePreferences *self,
                                const gchar    *page_name,
                                const gchar    *group_name,
                                GtkWidget      *widget,
                                const gchar    *keywords,
                                gint            priority);

  gboolean (*remove_id)        (IdePreferences *self,
                                guint           widget_id);

  GtkWidget *(*get_widget)     (IdePreferences *self,
                                guint           widget_id);
};

void     ide_preferences_add_page         (IdePreferences *self,
                                           const gchar    *page_name,
                                           const gchar    *title,
                                           gint            priority);
void     ide_preferences_add_group        (IdePreferences *self,
                                           const gchar    *page_name,
                                           const gchar    *group_name,
                                           const gchar    *title,
                                           gint            priority);
void     ide_preferences_add_list_group   (IdePreferences   *self,
                                           const gchar      *page_name,
                                           const gchar      *group_name,
                                           const gchar      *title,
                                           GtkSelectionMode  mode,
                                           gint              priority);
guint    ide_preferences_add_radio        (IdePreferences *self,
                                           const gchar    *page_name,
                                           const gchar    *group_name,
                                           const gchar    *schema_id,
                                           const gchar    *key,
                                           const gchar    *path,
                                           const gchar    *variant_string,
                                           const gchar    *title,
                                           const gchar    *subtitle,
                                           const gchar    *keywords,
                                           gint            priority);
guint    ide_preferences_add_switch       (IdePreferences *self,
                                           const gchar    *page_name,
                                           const gchar    *group_name,
                                           const gchar    *schema_id,
                                           const gchar    *key,
                                           const gchar    *path,
                                           const gchar    *variant_string,
                                           const gchar    *title,
                                           const gchar    *subtitle,
                                           const gchar    *keywords,
                                           gint            priority);
guint    ide_preferences_add_spin_button  (IdePreferences *self,
                                           const gchar    *page_name,
                                           const gchar    *group_name,
                                           const gchar    *schema_id,
                                           const gchar    *key,
                                           const gchar    *path,
                                           const gchar    *title,
                                           const gchar    *subtitle,
                                           const gchar    *keywords,
                                           gint            priority);
guint    ide_preferences_add_custom       (IdePreferences *self,
                                           const gchar    *page_name,
                                           const gchar    *group_name,
                                           GtkWidget      *widget,
                                           const gchar    *keywords,
                                           gint            priority);
guint    ide_preferences_add_font_button  (IdePreferences *self,
                                           const gchar    *page_name,
                                           const gchar    *group_name,
                                           const gchar    *schema_id,
                                           const gchar    *key,
                                           const gchar    *title,
                                           const gchar    *keywords,
                                           gint            priority);
guint    ide_preferences_add_file_chooser (IdePreferences      *self,
                                           const gchar         *page_name,
                                           const gchar         *group_name,
                                           const gchar         *schema_id,
                                           const gchar         *key,
                                           const gchar         *path,
                                           const gchar         *title,
                                           const gchar         *subtitle,
                                           GtkFileChooserAction action,
                                           const gchar         *keywords,
                                           gint                 priority);
gboolean ide_preferences_remove_id        (IdePreferences *self,
                                           guint           widget_id);
void     ide_preferences_set_page         (IdePreferences *self,
                                           const gchar    *page_name,
                                           GHashTable     *map);
GtkWidget *ide_preferences_get_widget     (IdePreferences *self,
                                           guint           widget_id);


G_END_DECLS

#endif /* IDE_PREFERENCES_H */

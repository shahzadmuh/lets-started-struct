#include <stdio.h>
#include <json-c/json.h>

int main()
{
  char *xml = "<?xml version='1.0'?>";
  char buf[] = "{ \"name\": \"ramin\", \"age\": 23, \"address\": \"nothing\" }";

  json_object *new_obj = json_tokener_parse(buf);


  json_object *obj_name;
  obj_name = json_object_object_get(new_obj,"name");

  json_object *obj_age;
  obj_age = json_object_object_get(new_obj,"age");

  json_object *obj_addr;
  obj_addr = json_object_object_get(new_obj,"address");

  const char *name = json_object_get_string(obj_name);
  const char *age = json_object_get_string(obj_age);
  const char *addr = json_object_get_string(obj_addr);
  printf("%s\n",xml);  
  printf("<name type='string'>%s</name>\n",name);
  printf("<age type='int'>%s</age>\n",age);
  printf("<address type='string'>%s</address>\n",addr);

  json_object_put(new_obj);


}

#include <json-c/json.h>
#include <stdio.h>


/*
 * Access to JSON array value
 *
 */

int object_array_value_json(struct json_object *curr_object_json,const char *keys){
    
    struct json_object *secu_code, *tmp;
    int i;
    json_object_object_get_ex(curr_object_json, keys, &secu_code);
        for (i = 0; i < json_object_array_length(secu_code); i++) {
		    tmp = json_object_array_get_idx(secu_code, i);
		    printf("%s[%d] = %s\n", keys, i, json_object_to_json_string(tmp));
	}
    return 0;
}

int main() {


	struct json_object *jobj,*object;
    int i;
    int val_type;
    char *val_type_str;
    char *key_object;

	char *str = "{ \"msg-type\": [ \"0xdeadbeef\", \"irc log\" ], \
		\"msg-from\": { \"class\": \"soldier\", \"name\": \"Wixilav\" }, \
		\"msg-to\": { \"class\": \"supreme-commander\", \"name\": \"[Redacted]\" }, \
		\"msg-log\": [ \
			\"soldier: Boss there is a slight problem with the piece offering to humans\", \
			\"supreme-commander: Explain yourself soldier!\", \
			\"soldier: Well they don't seem to move anymore...\", \
			\"supreme-commander: Oh snap, I came here to see them twerk!\" \
			] \
		}";

	printf("str:\n---\n%s\n---\n\n", str);

	jobj = json_tokener_parse(str);
	printf("jobj from str:\n---\n%s\n---\n", json_object_to_json_string_ext(jobj, JSON_C_TO_STRING_SPACED | JSON_C_TO_STRING_PRETTY));
    
    json_object_object_foreach(jobj, key, val) {
	    val_type = json_object_get_type(val);

	    switch (val_type) {
		    case json_type_null:
			    val_type_str = "val is NULL";
			    break;

		    case json_type_boolean:
			    val_type_str = "val is a boolean";
		    	break;

		    case json_type_double:
			    val_type_str = "val is a double";
			    break;

		    case json_type_int:
			    val_type_str = "val is an integer";
			    break;

		    case json_type_string:
			    val_type_str = "val is a string";
			    str = (char *) json_object_get_string(val);
			    break;

		    case json_type_object:
			    val_type_str = "val is an object";
			    break;

		    case json_type_array:
			    object_array_value_json(jobj,key);
                val_type_str = "val is an array";
			    break;
		    }

		str = NULL;
	}

	return 0;
}

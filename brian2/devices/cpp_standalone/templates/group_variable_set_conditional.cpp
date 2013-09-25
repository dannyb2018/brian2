////////////////////////////////////////////////////////////////////////////
//// MAIN CODE /////////////////////////////////////////////////////////////

{% macro cpp_file() %}

#include "{{codeobj_name}}.h"
#include<math.h>
#include "brianlib/common_math.h"
#include<stdint.h>

////// SUPPORT CODE ///////
namespace {
	{% for line in condition_support_code_lines %}
	{{line}}
	{% endfor %}
}

////// HASH DEFINES ///////
{% for line in condition_hashdefine_lines %}
{{line}}
{% endfor %}

void _run_{{codeobj_name}}(double t)
{
	///// CONSTANTS ///////////
	%CONSTANTS%
	///// POINTERS ////////////
	{% for line in condition_pointers_lines %}
	{{line}}
	{% endfor %}

	//// MAIN CODE ////////////
	const int _num_group_idx = _num_idx;
	for(int _idx_group_idx=0; _idx_group_idx<_num_group_idx; _idx_group_idx++)
	{
		//const int _idx = _group_idx[_idx_group_idx];
		const int _idx = _idx_group_idx;
		const int _vectorisation_idx = _idx;
		{% for line in code_lines['condition'] %}
		{{line}}
		{% endfor %}
		if(_cond)
		{
			{% for line in code_lines['statement'] %}
			{{line}}
			{% endfor %}
		}
	}
}
{% endmacro %}

////////////////////////////////////////////////////////////////////////////
//// HEADER FILE ///////////////////////////////////////////////////////////

{% macro h_file() %}
#ifndef _INCLUDED_{{codeobj_name}}
#define _INCLUDED_{{codeobj_name}}

#include "arrays.h"

void _run_{{codeobj_name}}(double t);

#endif
{% endmacro %}

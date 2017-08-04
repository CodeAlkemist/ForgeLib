/**
    Copyright 2017 Matheus Xavier Silva

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef NULL
/**
 * The standard NULL macro definition
 */
#define NULL ((void *) 0)
#endif

#ifndef __FLBOOL
typedef enum{
    true = 1,
    false = 0
}bool_t;
#define __FLBOOL
#endif

#ifndef __TYPES
#define __TYPES
#endif

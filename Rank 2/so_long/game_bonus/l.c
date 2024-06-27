/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:49:42 by maugusto          #+#    #+#             */
/*   Updated: 2024/06/27 16:51:17 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

{   
	"configurations": [
    {
      "name": "C/C++: gcc.exe build and debug active file",
      "type": "cppdbg",
      "request": "launch",
      "program": "${workspaceRoot}/so_long/so_long",
      "args": ["map/map_test.ber"],
      "stopAtEntry": false,
      "cwd": "${fileDirname}",
      "environment": [],
      "externalConsole": false,
      "MIMode": "gdb",
    "setupCommands": [
    {
      "description": "Enable pretty-printing for gdb",
      "text": "-enable-pretty-printing",
      "ignoreFailures": true
    },
   ]
  }
  ],
  "preLaunchTask": "C/C++: gcc.exe build active file"
}
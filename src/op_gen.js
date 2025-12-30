#!/bin/node

const { exec } = require("child_process");
const fs = require("fs/promises");
new Promise(async function(res){
	res();

	let entries = [
		...(await fs.readdir("op")).filter(f => f.endsWith(".c"))
	];

	entries.map(entry => exec(`
g++ -I./ \\
 -L../SDL3 -L../SDL3_ttf -lSDL3_image -lSDL3_ttf -lSDL3 \\
 	\`pkg-config --cflags --libs sdl3 sdl3-image\` \\
 -Wall -Wextra -pedantic \\
 -c op/${entry.slice(0, -2)}.c \\
 -o op/${entry.slice(0, -2)}.o
	`, console.log));

	let macro = entries.map(f => "op_" + f.slice(0, -2) + '()').join('; ');
	macro = `#define OP_INCLUDE() ${macro}`
	entries = entries.map(function(file){
		return `void op_${file.slice(0, -2)}(void);`;
	});
	entries.push(macro);

	await fs.writeFile("op.h", entries
		.join('\n')
	);
})

#!/usr/bin/lua

local input = io.open(..., "r") or io.stdin
local class = (...):match('%w+')
local s = input:read('*a')

function m_type(t)
	local l = {
		INTEGER = 'QVariant::Int',
		LOGICAL = 'QVariant::Bool',
		REAL = 'QVariant::Double',
		CHARACTER = 'QVariant::String',
	}
	return t
end

local defs = setmetatable({}, { __index=table })
for h in s:gmatch("(.-)\n\n\n") do
	print("->",h)
	local name, p_type, help = h:match("(%S+)%s+(%S+)%s+(.*)")
	help = help:gsub('\n+', '\\n'):gsub('%s+', ' ')
	--print("name = ", name)
	--print("type = ", p_type)
	--print("help = ", help)
	p_type = m_type(p_type)
	if not name:match(',') then
		defs:insert{ name=name, type=p_type, label=name, help=help }
	elseif name:match('%b()') then
		defs:insert{ name=name, type=p_type, label=name, help=help, isList=true }
	else
		for n in (name..','):gmatch('(%S+),') do
			defs:insert{ name=n, type=p_type, label=n, help=help }
		end
	end
end

local editors = {
	INTEGER = 'QSpinBox',
	LOGICAL = 'QCheckBox',
	REAL = 'QDoubleSpinBox',
	CHARACTER = 'QLineEdit',
}

local extractors = {
	INTEGER = '->cleanText()',
	LOGICAL = '->isChecked()?QString(".true."):QString(".false.")',
	REAL = '->cleanText()',
	CHARACTER = '->text().prepend(\'\"\').append(\'\"\')',
}

for _, v in ipairs(defs) do
	--print( class..'.names << "'..v.name..'";' )
	--print( class..'.type["'..v.name..'"] = '..v.type..'; ' )
	--print( class..'.label["'..v.name..'"] = "'..v.label..'"; ' )
	--print( class..'.isList["'..v.name..'"] = '..(v.isList and 'true' or 'false')..'; ' )
	--print( class..'.help["'..v.name..'"] = "'..v.help..'"; ' )
	--print (v.type, v.name)
	print('editor = new '..editors[v.type]..'; editor->setObjectName("'..v.name..'"); layout->addRow("'..v.label..'", editor);')
end

print() print()

for _, v in ipairs(defs) do
	--print( class..'.names << "'..v.name..'";' )
	--print( class..'.type["'..v.name..'"] = '..v.type..'; ' )
	--print( class..'.label["'..v.name..'"] = "'..v.label..'"; ' )
	--print( class..'.isList["'..v.name..'"] = '..(v.isList and 'true' or 'false')..'; ' )
	--print( class..'.help["'..v.name..'"] = "'..v.help..'"; ' )
	--print (v.type, v.name)
	print('entry = form->findChild<'..editors[v.type]..'*>("'..v.name..'")'..extractors[v.type]..'; if (!entry.isEmpty() && entry!="\\"\\"") list << ("  '..v.name..' = " + entry);')
end



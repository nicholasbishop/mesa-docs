from glob import glob
from os import path
from subprocess import check_call

for input_name in glob('*.html'):
    if input_name in ('contents.html', 'index.html'):
        continue
    output_name = path.splitext(input_name)[0] + '.rst'
    cmd = ('pandoc', input_name, '-o', output_name)
    print ' '.join(cmd)
    check_call(cmd)

    with open(output_name) as rfile:
        contents = rfile.read()

    # Search for the second rubric in the output, then reformat that to be a title

    rubric = '.. rubric:: '

    pos = contents.index(rubric)
    pos = contents.index(rubric, pos + len(rubric))
    contents = contents[pos + len(rubric):]

    lines = contents.splitlines()
    lines[1] = '=' * len(lines[0])
    contents = '\n'.join(lines)

    with open(output_name, 'w') as wfile:
        contents = wfile.write(contents)

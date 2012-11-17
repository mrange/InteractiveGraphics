$radbrush = 'RadBrush'
$spheres = 1..20 | %{'Object_' + $_}

Import-Module .\InteractiveGraphics.Lib.dll
Open-IGWindow
Clear-IGState
Set-IGWindow -Width 640 -Height 480
New-IGRadialGradientBrush $radbrush -OffsetX -0.5 -OffsetY -0.5
Add-IGGradientStop $radbrush -Offset 0     -Color '#FFF'
Add-IGGradientStop $radbrush -Offset 0.5   -Color '#88E'
Add-IGGradientStop $radbrush -Offset 1     -Color '#224'

foreach($sphere in $spheres)
{
    New-IGFilledEllipse $sphere -NameOfBrush $radbrush -X 0 -Y 0 -Width 40 -Height 40
}

$iter = 0;
while(![System.Console]::KeyAvailable)
{
    ++$iter
    $phase = ([System.Math]::PI * $iter) / 100.0  

    foreach($sphere in $spheres)
    {
        $x = [float](320 + [System.Math]::Sin(2.7 * $phase) * 150)
        $y = [float](200 + [System.Math]::Cos($phase) * 150)
        Set-IGObject $sphere -X $x -Y $y

        $phase += 0.2
    }
    Wait-IGStateIsPresented
}

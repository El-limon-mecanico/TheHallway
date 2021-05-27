Manivela ={
    Active = true,
    Tag = "Manivela",
    Components = {"Transform","MeshRenderer", "Rigidbody", "Lever","AudioSource"},

    Transform = {
        Position = {0,0,0},
        Scale = {100,100,100},
        Rotation = {90,0,-90}
    },

    MeshRenderer ={
        Mesh = "Manivela.mesh",
    },

    Rigidbody = {
        Type = "Sphere",
        Mass = 1,
        Trigger = true,
        Static = true,
        PositionConstrains = {1,1,1},
        RotationConstrains = {1,1,1}
    },

    Lever = {
        Total = 5,
        ChargingVel = 1,
        UncharginVel = 0.5
    },
    AudioSource={
        Source="Manivela.mp3",
        Volume=0.8,
        Loops=-1,
        Play=false,
        D3=false,
        Enabled=true
    }
}
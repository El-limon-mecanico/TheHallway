Manivela ={
    Active = true,
    Tag = "Manivela",
    Components = {"Transform","MeshRenderer", "Rigidbody", "Lever","AudioSource"},

    Transform = {
        Position = {0,0,0},
        Scale = {3,3,3},
        Rotation = {0,0,0}
    },

    MeshRenderer ={
        Mesh = "Cube",
    },

    Rigidbody = {
        Type = "Box",
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
        Source="Throne.mp3",
        Volume=0.25,
        Loops=-1,
        Play=false,
        D3=false,
        Enabled=true
    }
}